#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b;
    std::cin>>a>>b;
    cout<<a.size()<<" "<<b.size()<<endl;
    
    cout<<a+b<<endl;
    
    char t;
    t=a[0];
    a[0]=b[0];
    b[0]=t;
    
    cout<<a<<" "<<b<<endl;
    
    return 0;
}
