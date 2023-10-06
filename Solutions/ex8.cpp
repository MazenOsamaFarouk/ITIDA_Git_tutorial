#include <iostream>
#include <string>
using namespace std;

int main() {
    string a , b ;
    
    cin >> a;
    cin >> b;
    
    
    cout << a.size() << " " << b.size() << endl;
    cout << a+b <<endl;
    
    
    string c = a;
    string d = b;
    a = a.erase(0,1);
    b = b.erase(0,1);
    
    c = c.erase(1);
    d = d.erase(1);
    
    a = d + a;
    b = c + b;
    
    cout << a << " " << b << endl;
  
    return 0;
}