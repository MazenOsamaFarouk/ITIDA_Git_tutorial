#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Timer.h"

namespace stl
{
    namespace vectors
    {
        void main(void);
    }

}

void print_v(std::vector<int>& v)
{
    auto it = v.begin();
    for(; it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void rprint_v(std::vector<int>& v)
{
    auto rit = v.rbegin();
    for(; rit != v.rend(); rit++)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}





void
stl::vectors::main(void)
{

    std::cout << "testing " << "vectors" << " ...\n" ; 

#if 0
    std::vector<int> v = {10,12,23}; // std::initializer_list


    for(int i=0; i<15; i++)
    {
        int random_num = rand() % 100 ;

        v.push_back(random_num) ;
    } 
    std::cout << v.data() << std::endl;

    print_v(v);

    for(int i=0; i<5 ; i++)
    {
        v.insert(v.begin()+2, 88);
    }

    print_v(v);

    

    typedef std::vector< std::vector<int> > Matrix ;
    Matrix v2 ;

    for(int i=0; i< 3; i++)
    {
        std::vector<int> tmpv;
        for(int j=0; j<3; j++)
        {
            tmpv.push_back(rand()%10) ;
        }
        v2.push_back(tmpv);
    }


    for(int i=0; i<v2.size(); i++)
    {
        for(int j=0; j<v2[i].size(); j++)
        {
            std::cout << v2[i][j] << " " ;
        }
        std::cout <<std::endl;
    }
#endif
    std::vector<int> v ; 


    for(int i=0; i<5; i++)
    {
        int random_num = rand() % 100 ;

        v.push_back(random_num) ;
    }

    print_v(v);
    rprint_v(v);


#if 0
    for(int i=0; i<25000000; i++)
    {
        TIME(v.insert(v.begin(), 88), MILLI);
    }
#endif

    std::cout << "End of testing " << "vectors" << " ...\n" ; 

}