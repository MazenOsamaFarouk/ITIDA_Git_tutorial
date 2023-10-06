#include <iostream>

using namespace std;

class tollBooth
{
	private:
	unsigned int carCount;
	double totalCash;

	public:
	tollBooth(): carCount(0), totalCash(0.0){}

	void payingcar()
	{
		carCount++;
		totalCash += 0.50;
	}

	void nopaycar()
	{
		carCount++;
	}

	void display()
	{
		cout << "The total number of cars: "<< carCount<<endl;
		cout << "The total cash: "<< totalCash<<endl;
	}
};

int main (void)
{
	tollBooth t1;
	char choice;
	cout<< "Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 'a':
		t1.payingcar();
		break;

		case 'b':
		t1.nopaycar();
		break;

		case 'q':
		t1.display();
		break;
	}


	return 0;
}
