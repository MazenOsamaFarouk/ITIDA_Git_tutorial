#include<iostream>

using namespace std;

class tollbooth
{
    private:
        unsigned int CarNumber;
        double TotalCash;

    public:

    tollbooth()
    {
        CarNumber=0;
        TotalCash=0;
    }

    void PayingCar()
    {
        CarNumber++;
        TotalCash+=0.50;
    }

    void NoPayCar()
    {
        CarNumber++;
    }

    void Display()
    {
        cout<<"Total Number of cars passed = "<<CarNumber<<endl;
        cout<<"Total Value of cash = "<<TotalCash<<endl;
    }

};


int main()
{   
    tollbooth t1;
    t1.PayingCar();
    t1.PayingCar();
    t1.NoPayCar();
    t1.Display();
    return 0;
}