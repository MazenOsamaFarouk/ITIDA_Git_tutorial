#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	char c[1000] = {0} ;
	char res[1000] = {0} ;

	cin.getline(c , 1000);

	str = string(c);

	cout<< "you entered : \n" << str << endl;

	for(int i = 0 , j = 0 ; i <= 1000 ; i++)
	{
		if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')){
			res[j] = c[i];
			j++;
		}
		else{
				res[j] = '~';
				j++;
			}
	}

	 cout << "\nres : \n" << res << endl;

	for (int i = 0 ; i < 1000 ; i++)
	{
		if( res[i] == '~')
		{
			if (res[i-1] == '~')
			{
				continue;
			}
			else
			{
				cout << endl;
			}

		} else
		{
			cout << res[i];
		}
	}

	return 0;
}