#include <iostream>
#include <string>


int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::string unwanted_chars = ".,?!:; ";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < unwanted_chars.length(); j++)
        {
            if (str[i] == unwanted_chars[j])
            {
                str[i] = ' ';
                break;
            }
        }
    }
    std::cout << str << std::endl;

    return 0;
}
