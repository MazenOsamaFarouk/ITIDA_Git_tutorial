#include <iostream>
#include <string>


int main(void)
{

    std::string num;
    std::cin >> num ;

    for(int i = num.size(), j=0 ; i >=0 ; i--, j++ )
    {
        if(j%3 == 0 && i!= 0 && i != num.size())
        {
            num.insert(i,",");
        }
    }

    std::cout << num << std::endl;


    return 0;
}
