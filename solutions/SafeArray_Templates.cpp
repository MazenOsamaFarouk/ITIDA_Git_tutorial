#include <iostream>
using namespace std;

#define LIM  50

template <class T>

class safearay
{
private:
T arr[LIM];

public:
T& operator [](int n) 
{
if( n< 0 || n>=LIM )
{ cout << "Index out of bounds"<<endl;  }
return arr[n];
}

};

int main()
{
    safearay <int>s1;
for(int i=0; i<LIM; i++)  
s1[i] = i;           
for(int i=0; i<LIM; i++)      
{
int temp = s1[i];       
cout << "Element " << i << " is " << temp << endl;
}
return 0;

}