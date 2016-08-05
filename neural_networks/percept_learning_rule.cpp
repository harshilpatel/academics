// Perceptron Learning Rule - neural networks
// harshil912@gmail.com

#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout << "Perceptron learning rule: Enter samples and size of inputs \n";
    int input_size, iter;
    cin >> iter >> input_size;
    int x[iter][input_size], d[input_size];
    int w[iter][input_size], o[input_size];
    int alpha = 1;

    for(int i=0; i<iter; i++){
        cout << "Enter input x("<<i<<"): ";
        for(int j=0; j<input_size; j++){
            cin >> x[i][j];
            }
        }

    cout << "Enter expected output for "<< iter <<" samples: ";
    for(int i=0; i<iter; i++){
        cin >> d[i];
        }
    cout << "Enter first weight vector: ";
    for(int i=0; i<input_size; i++){
        cin >> w[0][i];
        }

    for(int i=0; i<iter; i++){
        cout << "Calculating for input sample " << i << endl;
        int net = 0;
        for(int j=0; j<input_size; j++){
              net += ( x[i][j] * w[i][j] );
            }
        if(net >= 0) o[i] = 1;
        else o[i] = -1;
        cout << "net: " << net << " and o: " << o[i];

        if (o[i] != d[i]){
            cout<<"\nCalculated value not equal to Expected for iteration: " << i <<" \nHence updating weights to: ";
            for(int z=0; z<input_size; z++){
                w[i+1][z] = w[i][z] +  (alpha * (d[i] - o[i]) * x[i][z]);
                cout << w[i+1][z] << " ";
                }
        }
        else{
            cout<<"\nCalculated value equal to Expected for iteration: " << i <<" \n";
            for(int z=0; z<input_size; z++){
                w[i+1][z] = w[i][z];
                }
            };
        cout << "\n\n";
        }

    cout << "\nOutput O: ";
    for(int i=0; i<iter; i++){
        cout << o[i] << " ";
        }
    cout << "\n#####\n";
    cout << "Weights: \n";
    for(int i=0; i<iter;i++){
        cout << "weight " << i << ": ";
        for(int j=0; j<input_size;j++){
            cout << w[i][j] << " ";
            }
        cout << "\n";
        }

}
