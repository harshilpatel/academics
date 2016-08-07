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
    float x[iter][input_size];
    int d[input_size];
    float w[input_size];
    float o;
    cout << "Enter the constant value:  ";
    float alpha; cin >> alpha;
    cout << "Enter the threshold value: ";
    float th; cin >> th;

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
        cin >> w[i];
        }
    int correct_case = 0;
    int i=0;
    do {
      cout << "#####################"<< i <<"#####################" << endl;
      cout << "Calculating for input sample " << i << endl;
      float net = 0;
      for(int j=0; j<input_size; j++){
            net += ( x[i][j] * w[j] );
          }
      if(net >= th) o = 1;
      else o = -1;
      cout << "net: " << net << " and o: " << o;

      if (o != d[i]){
          cout<<"\nCalculated value not equal to Expected for iteration: " << i <<" \nHence updating weights to: ";
          for(int z=0; z<input_size; z++){
              w[z] = w[z] +  (alpha * (d[i] - o) * x[i][z]);
              cout << w[z] << " ";
              }
      }
      else{
          cout<<"\nCalculated value equal to Expected for iteration: " << i <<" \n";
          correct_case++;
          // for(int z=0; z<input_size; z++){
          //     w[i+1][z] = w[i][z];
          //     }
          }
      cout << "\n\n";
      i = (i+1)%iter ;
    } while( correct_case < iter + 1 );

    // for(int i=0; i<iter; i++){
    //     cout << "Calculating for input sample " << i << endl;
    //     float net = 0;
    //     for(int j=0; j<input_size; j++){
    //           net += ( x[i][j] * w[i][j] );
    //         }
    //     if(net >= 0) o[i] = 1;
    //     else o[i] = -1;
    //     cout << "net: " << net << " and o: " << o[i];
    //
    //     if (o[i] != d[i]){
    //         cout<<"\nCalculated value not equal to Expected for iteration: " << i <<" \nHence updating weights to: ";
    //         for(int z=0; z<input_size; z++){
    //             w[i+1][z] = w[i][z] +  (alpha * (d[i] - o[i]) * x[i][z]);
    //             cout << w[i+1][z] << " ";
    //             }
    //     }
    //     else{
    //         cout<<"\nCalculated value equal to Expected for iteration: " << i <<" \n";
    //         for(int z=0; z<input_size; z++){
    //             w[i+1][z] = w[i][z];
    //             }
    //         };
    //     cout << "\n\n";
    //     }

    // cout << "\nOutput O: ";
    // for(int i=0; i<iter; i++){
    //     cout << o[i] << " ";
    //     }
    cout << "\n#####\n";
    cout << "Weights: \n";
    for(int i=0; i<input_size;i++){
        cout << w[i] << " ";
        }
    cout << "\n";

}
