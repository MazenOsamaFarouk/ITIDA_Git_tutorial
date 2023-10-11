#include <iostream>
using namespace std;

const int LIM = 50;

class safearay
{
private:
int arr[LIM];

public:
int& operator [](int n) 
{
if( n< 0 || n>=LIM )
{ cout << "\nIndex out of bounds";  }
return arr[n];
}

};

int main()
{
    safearay s1;
for(int i=0; i<LIM; i++)  
s1[i] = i*10;           
for(int i=0; i<LIM; i++)      
{
int temp = s1[i];       
cout << "Element " << i << " is " << temp << endl;
}
return 0;

}