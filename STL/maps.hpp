#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Timer.h"

namespace stl
{
    namespace maps
    {
        void main(void);
    }

}

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment << "\n";

    // std::variant --> generic data type
    // C++98 alternative:
    auto it = m.begin(); // type inference: it tries to infer the type from the return of the expression.
    for (; it != m.end(); ++it) // it --> pointer to a pair
        std::cout << it->first << " = " << it->second << "; ";
    
        std::cout << '\n';
}



void
stl::maps::main(void)
{
     // Create a map of three (string, int) pairs
    std::map<std::string, int> m{
        {"CPU", 10}, {"GPU", 15}, {"RAM", 20}
    };
 
    print_map("1) Initial map: ", m);
 
    m["CPU"] = 25; // update an existing value
    m["SSD"] = 30; // insert a new value
    print_map("2) Updated map: ", m);
    
    m["UPS"] = 100 ;
    // Using operator[] with non-existent key always performs an insert
    std::cout << "3) m[UPS] = " << m["UPS"] << '\n';
    print_map("4) Updated map: ", m);
 
    m.erase("GPU");
    print_map("5) After erase: ", m);
 
 
    m.clear();


    std::pair<std::string, float> p{"Mazen", 5.256} ;
    std::cout << "my pair is: first: " << p.first << " and second is: "
    << p.second <<std::endl;

    std::pair<int,int> point ; // for x and y points




}