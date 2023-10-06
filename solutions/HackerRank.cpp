#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
   string a,b;
    cin >> a >> b ;
    int a_len = a.size();
    int b_len = b.size();
    cout << a_len <<" "<<b_len << endl;
    cout << a << b << endl;
    char c1 = a[0];
    char c2 = b[0];
    a[0] = c2;
    b[0] = c1;
    cout << a <<" "<<b;
    return 0;
}