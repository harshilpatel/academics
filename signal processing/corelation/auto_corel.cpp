// Example program
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int x_length;
    int y_length;
    int z_length;
    
    
    cout << "Enter 0 for Cross and 1 for AUTO: ";
    int choice;
    cin >> choice;
    if (choice == 1){
        cout << "Auto Co-Relation:\nEnter length of input signal:  ";
        cin >> x_length;
        y_length = x_length;
        }
    else{
        cout << "Cross Co-Relation:\nEnter length of input signals 1 and 2:  ";
        cin >> x_length >> y_length;    
    }
    
    int x[x_length], y[y_length], z[x_length+y_length-1];
    
    cout << "Enter First signal(" << x_length <<") elements: ";
    for(int i=0; i<x_length; i++){
        cin >> x[i];
        }
    if(choice == 0){
    cout << "Enter Second Signal("<< y_length <<") elements:";
        for(int i=0; i<y_length; i++){
            cin >> y[i];
        }    
    } else{
        for(int i=0; i< x_length; i++){
            y[i] == x[i];
        }
    }    
    
    
    for(int n=0; n< (x_length+y_length-1); n++){
        z[n] = 0;
        cout << "\nElement: "<< n << ": ";
        for(int k=0; k<(x_length); k++){
            z[n] = z[n] + ( x[k] * y[k-n] );
	    cout << " " << z[n] << " ";
            }
        // cout << z[n] << " ";
        }
    
    cout << "Resultant signal: ";
    for(int i=0; i<(x_length+y_length-1); i++){
        cout << z[i] << " ";
        }
    
}

