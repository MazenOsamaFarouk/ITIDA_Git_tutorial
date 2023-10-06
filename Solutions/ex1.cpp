#include <iostream>

using namespace std;



long hms_to_secs(int x , int y , int z)
{
	while (x != 0)
	{
		x--;
		y += 60 ;
	}

	while (y != 0)
	{
		y --;
		z += 60 ;
	}

	return z;
}




int main(void)
{
	int x, y, z;
	long s;
	while(1)
	{
		cout << "Enter time : " ;
		cin >> x ;
		cout <<":" ;
		cin >> y ;
		cout <<":" ;
		cin >> z;

		s = hms_to_secs(x ,y , z);	
		cout << "seconds : " << s << endl ;	
	}


	return 0 ;
}