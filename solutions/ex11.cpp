#include <iostream>
#include <process.h>

using namespace std;

#define MAX 10

class SafeArray
{
private:
        int arr[MAX];

public:
        int& operator[](int n)
        {
         if (n<0 || n>= MAX)
         {
             cout<<"Index outside limit"<<endl;
             exit(1);
         }
         return arr[n];
        }
};

int main()
{
    SafeArray a1;
    int i, temp;
    for(i = 0; i<MAX; i++)
    {
        a1[i] = i*10;
    }

    for(i = 0; i<MAX; i++)
    {
        temp = a1[i];
        cout<< "Element "<<i<<" = "<<temp<<endl;
    }
    return 0;
}