#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str;
    cout << "Please enter a number: " << endl;
    cin >> str;
    int i = 0, j = 0;
    int length = str.size();

    for (i = length, j = 0; i >= 0; j++, i--)
    {
        if (j % 3 == 0 && i != length && i != 0)
        {
            str.insert(i, ",");
        }
    }
    cout << str << endl;
    return 0;
}