#include <iostream>
#include <string>
#include <list>

using namespace std;
int main()
{
  list<int> output;
  cout << "Auto Correlation: ";
  cout << "Enter signal size for x:  ";
  int xl;
  cin >> xl;
  int yl = xl+xl-1;
  float x[xl];
  cout << "Enter x(n): ";
  for(int i=0; i<xl; i++){
      cin >> x[i];
      }   
  for(int i =-yl; i<yl; i++){
      int value = 0;
      for(int j=0; j<xl; j++){
        if( (j-i >=0) && (j-i <= xl) ){
              value += (x[j]*x[j-i]);
            }
        }
       output.push_back(value);
      }
  cout << "\nOutput: \n";
  int pos = -yl;
  while(! output.empty()){
     cout << " y(" <<pos << ") : "<< output.front() << "\n";
     pos++;
     output.pop_front();
	}
 cout << "\n";
 return 0;
} 
