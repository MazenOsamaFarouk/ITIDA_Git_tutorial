#include <iostream>
using namespace std;

int main()
{
    char input[1000]={0};
    cin.getline(input,1000);
    string str_input = string(input);
    int start = 0;
    int last = 0;
    string sub;
    while (start < str_input.size())
    {
        start = str_input.find_first_not_of(" ,.?!;:");
        last = str_input.find_first_of(" ,.?!;:", start);
        sub = str_input.substr(start,last-start);
        cout<<sub<<endl;
        str_input.erase(start,last);
    }
    return 0;
}