#include <iostream>
#include <string>

using namespace std;
int main()
{
    int xlen,hlen,n;
    cout << "Enter size of x(n) and h(n): ";
    cin>>xlen;
    cin>>hlen;

    //paddding
    if (xlen != hlen){
        n = xlen + hlen - 1;
    } else{
         n = xlen;
    }
    int x[n],xtemp[n],h[n],y[n];

    cout << "Enter input signal: ";
    for(int i=0;i<n;i++) {
        if(i>xlen-1)  x[i] = 0;
        else cin>>x[i];

        xtemp[i]=x[i];
        y[i]=0;
    }
    cout << "Enter reference signal: ";
    for(int i=0;i<n;i++) {
        if (i>hlen-1) h[i] = 0;
        else cin>>h[i];
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            int temp = (k-i)%n;
            if (temp<0){ 
                temp = n+temp;
            }
            xtemp[k] = x[temp];
            }
        for(int j=0;j<n;j++){
            y[i] = y[i] + xtemp[j]*h[j];
            }
        }
    cout << "Output signal:";
    for(int i=0;i<n;i++){cout<< " "<<y[i] ;}
    cout << "\n";
}
