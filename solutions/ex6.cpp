#include <iostream>
#include <string>

using namespace std;

int main (void)
{
	string input_money;
	cout<<"Enter the value: ";
	cin>>input_money;
	for (int i = 3; i<input_money.size(); i+=4)
    {
        input_money.insert(i,",");
    }
    cout<<"After modification: "<<input_money;
	return 0;
}