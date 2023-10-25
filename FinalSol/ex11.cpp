#include <iostream>
// #include <string>
using namespace std;

#define SIZE 50

class cSafeArray_int
{
    private:
        int m_array[SIZE];
        bool error;
        int ret;
    public:
        cSafeArray_int()
        {
                            // cant inialize array in the initialize list,, can inialize first element only
                            // call new here if created dynamically,, dont forget delete in the destructor
        }

        int& Access(unsigned int index)     //return by reference to set and get
        {
            if( index >= SIZE ) 
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

        int& operator[](unsigned int index)     //return by reference to set and get
        {
            if( index >= SIZE ) 
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
    cSafeArray_int a1;
    a1.Access(3)=12;
    a1.DisplayElement(3);
    a1[3]=5;
    a1.DisplayElement(3);
    return 0;
}