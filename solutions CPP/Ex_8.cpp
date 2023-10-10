#include <iostream>
#include <string>
using namespace std;
void swap_first_letter(string str1,string str2);
int main() {
	string input_1,input_2;
    cin>>input_1>>input_2;
    cout<<input_1.size()<<" "<<input_2.size()<<endl;
    cout<<input_1+input_2<<endl;
    swap(input_1[0],input_2[0]);
 
    cout<<input_1<<" "<<input_2<<endl;
  
    return 0;
}