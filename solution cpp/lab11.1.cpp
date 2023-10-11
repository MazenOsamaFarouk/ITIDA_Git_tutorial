#include <iostream>
#include <stdexcept>
#define ARRAY_SIZE 10
using namespace std;
template<class T>
class SafeArray
{
private:
    T data[ARRAY_SIZE];

public:

    SafeArray()
    {
        for (T i = 0; i < ARRAY_SIZE; i++)
        {
            data[i] = 0;
        }
    }


    T& operator[](T index)
    {
        if(!((index >=0)&&(index <ARRAY_SIZE)))
        {
             cout<<"Out of range"<<endl;
             int x=0xff;
             return x;
        }
        return data[index];
    }
};
int main()
{
    SafeArray<int> arr1;
    arr1[5]=10;
    cout<<arr1[5]<<endl;
    return 0;
}
