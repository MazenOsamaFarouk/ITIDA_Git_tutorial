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
    char key=NULL;
    tollbooth t1;
    while(key!='q')
    {
        cout<<"please enter car case : ";
        cin>>key;
        switch (key)
        {
        case 'p':
            t1.PayingCar();
            cout<<"car added p"<<endl;
            break;
        case 'n':
            t1.NoPayCar();
            cout<<"car added n"<<endl;
            break;
        default:
            break;
        }
    }
    
    t1.Display();
    return 0;
}