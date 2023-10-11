#include <iostream>

#define SIZE 10

class cSafeArray_int
{
private:
    int m_arr[SIZE];

public:
    cSafeArray_int()
    {
        for (int i = 0; i < SIZE; i++)
        {
            m_arr[i] = 0;
        }
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= SIZE)
        {
            std::cout << "Index out of bounds. Exiting." << std::endl;
            exit(0);
        }
        return m_arr[index];
    }
};

int main()
{
    cSafeArray_int arr;

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i * 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < 12; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
