#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    cout << "Please, enter any number: ";
    cin >> num;

    for(int i = num.size(),j=0 ; i>=0 ; i--,j++)
    {
        if( j%3 ==0 && i != 0 && i!= num.size())
        {
            num.insert(i, ",");
        }
    }

    cout<< "Number after modifing: "<<num<<endl;
    return 0;
}