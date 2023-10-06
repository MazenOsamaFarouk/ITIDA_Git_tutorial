#include <iostream>

using namespace std;


class cTollBooth
{

unsigned int m_cars;
double m_money;

public:
	// initializer list
cTollBooth():
	m_cars(0) ,
	m_money(0)
{ /* noting to do */}

void nopayCar()
{
	m_cars ++;
}

void payingCar()
{
	nopayCar();
	m_money += 0.50;
}


void display()
{
	cout << "Total cars : " << m_cars << endl;
	cout << "Total money : " << m_money << endl;
}

};


int main(void)
{
	cTollBooth a;
	char x;
	bool run = true;

	while (run)
	{
	    cout <<  "Enter a for paying car or b for no paying car or q to display" << endl;
	    cin >> x;
		/*  if (x == 'q')
		{
			a.display();
			break;
		}
		else if (x == 'a')
		{
			a.payingCar();
		}

		else if ( x == 'b')
		{
			a.nopayCar();
		}   */

		switch(x)
		{
			case 'a':
				a.payingCar();
				break;

			case 'b':
				a.nopayCar();
				break;

			case 'q':
				a.display();
				run = false;
		}

	}


	return 0;
}