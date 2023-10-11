#include <iostream>

using namespace std;

int main ()
{

    string str;
    char found;
    char line[1000]= {0};
    cin.getline(line,1000);
    str = (string)line;
    cout<< "you entered : "<<str;

    while(!found)
    {

    found = str.find_first_of(".,?!:;");
    str.substr(found,1,"");
    }

cout<< "you entered : "<<str;
    return 0;
}