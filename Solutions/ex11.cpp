#include <iostream>
 
#define ARR_MAX 100

using namespace std;
 


class cSafeArray_int {
private:
	int m_arr[ARR_MAX];
	bool error;
	int ret;
 
public:
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
			ret = -1;
			return ret;
		}
	}

	bool isError()
	{
		return error;
	}


 
};
 

int main()
{
    cSafeArray_int arr1;

    for (int i = 0; i < ARR_MAX; ++i)
    {
    	arr1[i] = (i+3);
    }

    for (int i = 0; i < ARR_MAX; ++i)
    {
    	cout << arr1[i] << " ";
    }
}