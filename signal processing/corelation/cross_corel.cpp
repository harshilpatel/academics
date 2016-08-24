// Example program
#include <iostream>
#include <string>

using namespace std;
int main()
{
    int x_length;
    int y_length;
    int z_length;
    int x_zero;
    int y_zero;

    cout << "Cross Co-Relation:\nEnter length of input signals 1 and 2:  ";
    cin >> x_length >> y_length;

    int x[x_length], y[y_length], z[x_length+y_length-1];
    
    cout << "Enter First signal(" << x_length <<") elements: ";
    for(int i=0; i<x_length; i++){
        cin >> x[i];
        }
    
    cout << "Enter Second Signal("<< y_length <<") elements:";
    for(int i=0; i<y_length; i++){
        cin >> y[i];
    }        
    
    cout << "Enter zero positions of signals: ";
    cin >> x_zero >> y_zero;

    
    
    
    cout << "\nResultant signal: ";
    for(int i=0; i<(x_length+y_length-1); i++){
        cout << z[i] << " ";
        }
    cout << "\n";
    
}

