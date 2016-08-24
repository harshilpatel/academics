#include <iostream>
#include <string>
#include <list>

using namespace std;
int main()
{
  list<int> output;
  cout << "Cross Correlation: ";
  cout << "Enter signal size for x and h:  ";
  int xl,hl;
  cin >> xl >> hl;
  int yl = hl+xl-1;
  float x[xl], h[hl];
  cout << "Enter x(n): ";
  for(int i=0; i<xl; i++){
      cin >> x[i];
      }
  cout << "Enter h(n): ";
  for(int i=0; i<hl; i++){
      cin >> h[i];
     }
     
  for(int i =-yl; i<yl; i++){
      int value = 0;
      for(int j=0; j<xl; j++){
        if( (j-i >=0) && (j-i <= hl) ){
              value += (x[j]*h[j-i]);
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
