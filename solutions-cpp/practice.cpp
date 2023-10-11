#include <iostream>
#include <string>


int g = 10;


// setter and getter at the same time
int& modifyG()
{  
    return g;
}

void func3(int*& addr)
{
    std::cout << addr;
}


int main(void)
{

    // modifyG() = 20;
    // int* ptr = &g;
    // std::cout << &g << " " ;
    // // std::cout << modifyG();
    // func3(ptr);

    std::string s1("Mazen");
    std::string s2("Osama");

    std::string s3 = s1 + ' ' + s2 ;
    std::cout << s3 << " " << s3[2] << std::endl;

    std::string search_key = "sam" ;

    int pos = s3.find(search_key); // Mazen Osama
    // std::cout << "position is " << pos << std::endl;

    std::string sub = s3.substr(pos,search_key.size() );

    // std::cout << sub <<std::endl ;

    // pos = s3.find_first_of("s");
    pos = s3.find_first_not_of("Mazen");

    // std::cout << "position is " << pos << std::endl;

    // modifying methods
    std::cout << "String before erase: " << s3 << std::endl;
    s3.erase(2,4);
    std::cout << "String after erase: " << s3 << std::endl;
    s3.insert(2,"zen.");
    std::cout << "String after insert: " << s3 << std::endl;
    s3.replace(3,5,"EN..OS"); // Mazen.Osama --> MazEN..OSama
    std::cout << "String after replace: " << s3 << std::endl;
    s3.append(" Farouk");
    std::cout << "String after append: " << s3 << std::endl;
    












    return 0;
}