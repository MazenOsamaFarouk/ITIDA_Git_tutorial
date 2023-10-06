#include <iostream> 
using namespace std;


const double toll = 0.5;

class tollBooth
{
    private:
unsigned int total_cars;
double       total_money;

public:
tollBooth()
{
    total_cars =0;
    total_money = 0.0;
}

void payingCar()                       
    { total_cars++;
 total_money += toll;
    }

    void nopayCar()                        
{ 
    total_cars++; 
}

void display() const                  
{ cout << "\nCars=" << total_cars<< ", cash=" << total_money<< endl; }


};

int main()
{

tollBooth booth1;           

}