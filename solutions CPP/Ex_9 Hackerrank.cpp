#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
  string st_1 ,st_2;
  cin >> st_1>>st_2;
  int length_st1= st_1.size();
  int length_st2= st_2.size();
  cout<< length_st1<< " " << length_st2 << endl ; 
  cout<< st_1 << st_2<<endl;
  char c1 = st_1[0];
  char c2 = st_2[0];
   st_1[0] = c2 ;
   st_2[0] = c1;
   cout<< st_1 << " "<<st_2 << endl ;
    return 0;
}