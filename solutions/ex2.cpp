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
	int choice = 0;
	cout<< "Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		t1.payingcar();
		break;
		
		case 2:
		t1.nopaycar();
		break;
	}
	t1.display();
	
	return 0;
}