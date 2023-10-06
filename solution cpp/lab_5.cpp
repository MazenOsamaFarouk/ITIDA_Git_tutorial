#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout<<"enter some digits"<<endl;
    cin>>str;
    int i;
    for(i=3;str[i]!='\0';i=i+4)
    {
        str.insert(i,".");
    }
    cout<<"digits after modify"<<endl;
    cout<<str<<endl;
    return 0;
}
