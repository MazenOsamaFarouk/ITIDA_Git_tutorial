#include <iostream>
using namespace std ; 

class tollbooth {
    private : 
         unsigned int totalCars ;
         double totalMoney ; 
    public : 
        tollbooth():
        totalCars(0), totalMoney(0.0){}
        void PayingCar(){
            totalCars++;
            totalMoney += 0.50;
        }
        void noPayCar(){
            totalCars++;
        }
        void display()const {
            cout<<"Total cars:"<< totalCars<< endl << "Total money : "<<totalMoney<<endl;

        }


};
int main ()
{
    tollbooth booth ; 
    char c ; 
    while (c != 'q')
    {
        cout<< "press P to count paying car , press n to count none paying cars press q to quit"<<endl;
        cin >> c;
        switch (c)
        {

       
        case 'p':
        booth.PayingCar();
        cout<< "a paying car has been counted"<<endl; break;
        case 'n':
        booth.noPayCar();
        cout<< "a none car has been counted"<<endl; break;
        }
    }
    if (c=='q')
    {
        booth.display();
    }
    return 0 ;
}