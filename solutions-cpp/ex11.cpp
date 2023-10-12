#include <iostream>

#define ARR_MAX  100



template <class T, int size>
class cSafeArray
{

public:
    T& access(unsigned int index)
    {
        if(index < ARR_MAX)
        {
            error = false;
            return m_arr[index];
        }
        else
        {
            error = true;
            ret = -1 ;
            return ret;
        }
    }
    T& operator [](unsigned int index)
    {
        if(index < ARR_MAX)
        {
            error = false;
            return m_arr[index];
        }
        else
        {
            error = true;
            ret = -1 ;
            return ret;
        }
    }

    bool isError()
    {
        return error;
    }


private:
    T ret ;
    T m_arr[size];
    bool error;


};



int main(void)
{
    cSafeArray<int,10> arr1;

    for(int i=0; i<10; i++)
    {
        // arr1.access(i) = (i+2) ;
        arr1[i] = (i+3) ;
        
    }

    for(int i=0; i<10; i++)
    {
        std::cout << arr1[i] << " " ;
    }

    cSafeArray<std::string,5> arr2;

    arr2[0] = "Hello";
    arr2[1] = "I am";
    arr2[2] = "MAzen";
    arr2[3] = "Osama";
    arr2[4] = "Farouk";

    for(int i=0; i<10; i++)
    {
        std::cout << arr2[i] << " " ;
    }

    


    return 0;
}