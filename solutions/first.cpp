#include <iostream>

using namespace std;

class  tollBooth
{
	private:
		unsigned int TotalCars_no;
		double TotalMoney_amount;
	public:
		
		tollBooth()
		{
			TotalCars_no = 0;
			TotalMoney_amount =0 ;
			
		}
		
		void payingCar()
		{
			TotalCars_no++;
			TotalMoney_amount += 0.50;
		}
		void nopayCar()
		{
			TotalCars_no++;
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

	int key, cars_no ;
	cout << "Please enter number of cars \n";
	cin >> cars_no;
	for(int i = 0; i < cars_no; i++)
	{
		cout << "Please enter car key enter 1 if paying and 0 if not \n";
		cin >> key;
			if(key == 1)
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
		
	}
	
	obj.display();
	
	return 0;
}