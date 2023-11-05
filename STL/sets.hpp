#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Timer.h"

namespace stl
{
    namespace sets
    {
        void main(void);
    }

}

void
stl::sets::main(void)
{
    std::vector<int> v = {1, 2, 3, 3,3, 5 ,3,3,5, 3, 6, 3 } ;
    std::set<int> s;

    
    auto vit = v.begin();
    for(;vit != v.end(); vit++)
    {
        s.insert(*vit); 
    }



    auto sit = s.begin();
    for(;sit != s.end(); sit++)
    {
        std::cout << *sit << " ";
    }









}