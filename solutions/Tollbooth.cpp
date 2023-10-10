#include <iostream> 
using namespace std;


const float toll = 0.5;

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

char c;
while(c !='q')
{
    cout << "Enter character: ";
    cin  >> c;  
switch(c)
{
    case 'p' : booth1.payingCar()    ;break;
    case 'n' : booth1.nopayCar ()    ;break;
    case 'q' :                        break;
    default  : cout << "Wrong choice";break; 
}
}

booth1.display();

}