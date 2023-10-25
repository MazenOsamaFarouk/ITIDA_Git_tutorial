#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
     string st1,st2;
    char t;
    cin>>st1>>st2;
    cout<<st1.length()<<" "<<st2.length()<<endl;
    cout<<st1 + st2<<endl;
    t = st1[0];
    st1[0] = st2[0];
    st2[0]=t;
    cout<<st1<<" "<<st2<<endl;
    return 0;
}