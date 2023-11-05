#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "vectors.hpp"
#include "Timer.h"

namespace stl
{
    namespace algo
    {
        void main(void);
    }

}

// bash: what if everything is a string ?
// C: what if everything is a pointer ?
// C++: what if everything is object ?


// function object (functor)
struct Compare
{
bool operator ()(int a, int b)
{
    return (a<b) ;
}

};

void
stl::algo::main(void)
{

    std::vector<int> v;
    
    for(int i=0; i<10; i++)
    {
        int random_num = (rand() % 100 ) +1 ;

        v.push_back(random_num) ;
    } 

#if 0
    std::cout << "before sorting: " ;

    print_v(v);

    Compare comp;
    std::sort(v.begin(), v.end(),comp );
    // std::reverse(v.begin(), v.end());

    std::cout << "\nAfter sorting: " ;

    print_v(v);
#endif
    auto it = std::find(v.begin(), v.end(), 101);

    if(it == v.end())
    {
        std::cout << "not found " << std::endl;  ;  

    }
    else
    {
        std::cout << "found " << *it << std::endl;   ;
    }

    std::cout << std::endl;
    std::vector<int>::iterator it2;
    TIME(it2 = std::find(v.begin(), v.end(), v[2]), MILLI);
    
    if(it2 == v.end())
    {
        std::cout << "not found "  << std::endl;  

    }
    else
    {
        std::cout << "found " << *it2 << std::endl;
    }



}


