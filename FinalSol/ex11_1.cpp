#include <iostream>
// #include <string>
using namespace std;

#define SIZE 50


template <class T, int size>
class cSafeArray
{
    private:
        T m_array[size];
        bool error;
        T ret;
    public:
        cSafeArray_int()
        {
                            // cant inialize array in the initialize list,, can inialize first element only
                            // call new here if created dynamically,, dont forget delete in the destructor
        }

        T& Access(unsigned int index)     //return by reference to set and get
        {
            if( index >= size ) 
            { 
                error = true;
                cout<<"error out of array scope\n"; 
                return ret= -1;
            }
            else
            {
                error = false;
                return m_array[index];
            }
        }

        T& operator[](unsigned int index)     //return by reference to set and get
        {
            if( index >= size ) 
            { 
                error = true;
                cout<<"error out of array scope\n"; 
                return ret= -1;
            }
            else
            {
                error = false;
                return m_array[index];
            }
        }

        void DisplayElement(int Index) const
        {
            cout<<m_array[Index]<<endl;
        }
};


int main() {
    cSafeArray<int,10> a1;
    a1.Access(3)=12;
    a1.DisplayElement(3);
    a1[3]=5;
    a1.DisplayElement(3);

    cSafeArray<string,5> s1;
    s1[0] = "Hello";
    s1[1] = "My";
    s1[2] = "Name";
    s1[3] = "Youssef";

    for(int i=0; i <5; i++)
    {
        s1.DisplayElement(i);
    }
    return 0;
}