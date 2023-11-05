#pragma once

#include <iostream>
#include <string>
#include <array>

#include <random>

namespace stl
{
    namespace arrays
    {
        void main(void);
    }

}

void
stl::arrays::main(void)
{

    std::cout << "testing " << "arrays" << " ...\n" ; 
    std::array<int, 10> arr;

    arr.fill(-1);
    std::cout << arr.data() << std::endl;

    for(int i=0; i<arr.size(); i++)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;

    for(int i=0; i<arr.size(); i++)
    {
        int random_num = rand() % 100 ;

        arr[i] = random_num ;
    } 

    for(int i=0; i<arr.size(); i++)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << std::endl;


    std::cout << "End of testing " << "arrays" << " ...\n" ; 
}