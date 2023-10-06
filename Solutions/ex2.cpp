#include <iostream>

using namespace std;


class tollBooth
{

unsigned int cars;
double money;

public:
tollBooth()
{
	cars = 0;
	money =0;
}

void payingCar()
{
	cars ++;
	money += 0.50;
}

void nopayCar()
{
	cars ++;
}

void display()
{
	cout << "cars : " <<cars << endl;
	cout << "money : " << money << endl;
}

};






int main(void)
{
	tollBooth a;
	char x;

	while (1)
	{
	    cout <<  "Enter a for paying car or b for no paying car or q to display" << endl;
	    cin >> x;
		if (x == 'q')
		{
			a.display();
			break;
		}
		else if (x == 'a')
		{
			a.payingCar();
		}

		else if ( x == 'z')
		{
			a.nopayCar();
		}

	}


	return 0;
}