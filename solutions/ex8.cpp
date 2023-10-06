#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b;
    cin>>a;
    cin>>b;
    cout <<a.size()<<" "<<b.size()<<endl;
    cout<<a+b<<endl;
    string temp = a;
    a.replace(0,1,b,0,1);
    b.replace(0,1,temp,0,1);
    cout <<a<<" "<<b<<endl;
    return 0;
}