#include <iostream>

#define ARR_MAX  100

class cSafeArray_int
{

public:
    int& access(unsigned int index)
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
    int& operator [](unsigned int index)
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
    int ret ;
    int m_arr[ARR_MAX];
    bool error;


};



int main(void)
{
    cSafeArray_int arr1;

    for(int i=0; i<ARR_MAX; i++)
    {
        // arr1.access(i) = (i+2) ;
        arr1[i] = (i+3) ;
        
    }

    for(int i=0; i<ARR_MAX; i++)
    {
        std::cout << arr1[i] << " " ;
    }

    


    return 0;
}