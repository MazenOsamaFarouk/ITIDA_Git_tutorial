#include <iostream>
#include <string>

int main (void)
{
	std:: string s1;
	std::cout << "Please enter numbers \n";
	std::cin >> s1;
	
	//std::string s2 = "";
    int count = 0;
	int i = s1.size();
	
    for (i , count; i >= 0; i--, count++) {
		
       // s2 = s1[i] + s2;
        if (count % 3 == 0 && i > 0 && i != s1.size()) {
            s1.insert(i, ",");
        }
    }
	std::cout << "output is " << s1 << std::endl;
	return 0;
}