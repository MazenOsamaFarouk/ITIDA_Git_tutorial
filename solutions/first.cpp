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
	obj.display();
	
}