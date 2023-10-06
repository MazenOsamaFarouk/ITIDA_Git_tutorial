#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	string str ;
	cin >> str;

	if (str.size() % 3 == 0)
	{
		
		for (int count = str.size() - 3 ; count > 0 ; count -= 3)
		{
			str.insert((str.size() - count) , ",");
		}
	}
	else
	{

		for (int count = str.size() - (str.size()%3) ; count > 0 ; count -= 3)
		{
			str.insert((str.size() - count) , ",");
		}
	}	

	cout << "Number : " << str << endl;

	return 0 ;
}