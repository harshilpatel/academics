#include "string.h"
#include <iostream>

using namespace std;
int main(){
  char alpha[] = "abcdefghijklmnopqrstuvwxyz";
  string alphastr = "abcdefghijklmnopqrstuvwxyz";
  string plaintext, ciphertext;
  int key;
  cout << "Product Cipher\nEnter key and plaintext:  ";
  cin >> key;
  cin >> plaintext;
  int size = plaintext.size();
  // Ceaser cipher
  cout << "Substitution Cipher: Ceaser Cipher" << endl;
  for(int i=0; i<size;i++){
    for(int j=0; j<alphastr.size(); j++){
      if( alphastr.at(j) == plaintext.at(i) ){
        ciphertext += alphastr.at( ( j+key )%alphastr.size() );
        break;
      }
    }
  }
  cout << "Ceaser CIpher: " << ciphertext << endl;
  // left shift by 2
  string ciphertext2;
  for(int i=0; i<size; i++){
    ciphertext2 += ciphertext.at( (i+2)%size );
  }
  cout << "Left Shift by 2: " << ciphertext2 << endl;
  // transposition cipher
  string ciphertext3[size][2];
  for(int i=0; i<size; i=i+2){
    ciphertext3[0][i] = ciphertext2.at(i);
    ciphertext3[1][i] = ciphertext2.at(i+1);
  }
  cout << "Rail Fence cipher: ";
  for(int i=0; i<2; i++){
    for(int j=0; j<size; j++){
      cout << ciphertext3[i][j];
    }
  }
  cout << endl;
  // for(signed int i=-2; i< (size*2)-2; i = i+2){
  //   ciphertext3 += ciphertext2.at((i+2)%size);
  //   if (i%2 == 0){
  //     if(i>size) i=i+1
  //   }
  // }

}
