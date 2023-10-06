#include <iostream>

using namespace std;

class  tollBooth
{
	private:
		unsigned int TotalCars_no;
		double TotalMoney_amount;
	public:
		//initializer list
		tollBooth():
			TotalCars_no(0),
			TotalMoney_amount(0)
			
		{

			
		}
		
		void nopayCar()
		{
			TotalCars_no++;
		}
		
		void payingCar()
		{
			nopayCar();
			TotalMoney_amount += 0.50;
		}
		
		
		void display()
		{
			cout << "total number of functions " << TotalCars_no << "\n";
			cout << "total amount of money " << TotalMoney_amount << "\n";
		}
};
int main (void)
{
	tollBooth obj;

	char key = '2';
	bool flag = true;
	while(flag)
	{
		cout << "Please enter car key enter 1 if paying and 0 if not \n";
		cin >> key;
		switch(key)
		{
			case 'p':
				obj.payingCar();
				break;
			case 'n':
				obj.nopayCar();
				break;
			case 'q':
			flag = false;
				break;
			default:
				cout << "Invalid key \n";
				break;
			
		}
	}
			/*if(key == 1)
		{
			obj.payingCar(); 
			
			
		}
		else if(key == 0) 
		{
			obj.nopayCar();
		}
		else{
			cout << "Invalid key \n";
			break;
		}
		
	}*/
	
	obj.display();
	
	return 0;
}