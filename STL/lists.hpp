#pragma once

#include <iostream>
#include <string>
#include <list>
#include "Timer.h"


namespace stl
{
    namespace lists
    {
        void main(void);
    }

}

void
stl::lists::main(void)
{
    std::cout << "testing " << "lists" << " ...\n" ; 

    std::list<int> ls;

#if 0
    for(int i=0; i<5; i++)
    {
        ls.push_back(rand()%100);
    }


    std::list<int>::iterator it = ls.begin() ;
    for(it; it != ls.end()  ;it++)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
#endif


    for(int i=0; i<1000000; i++)
    {
        int random_num = rand() % 100 ;

        ls.push_back(random_num) ;
    }

    
    for(int i=0; i<250000; i++)
    {
        TIME(ls.push_front(88), NANO);
    }





    std::cout << "End of testing " << "lists" << " ...\n" ; 
}