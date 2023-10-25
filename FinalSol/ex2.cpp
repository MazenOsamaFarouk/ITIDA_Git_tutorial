#include<iostream>

using namespace std;


class cTollBooth
{
    private:
        unsigned int m_TotalCarNumber;
        double m_TotalMoney;    
    public:
        cTollBooth():m_TotalCarNumber(0),m_TotalMoney(0)
        { 

        }

        void PayingCar()
        {
            m_TotalCarNumber++;
            m_TotalMoney+=0.5;
        }

        void NoPayCar()
        {
            m_TotalCarNumber++;
        }

        void Display() const
        {
            cout<<"Total Cars Passed = "<<m_TotalCarNumber<<endl;
            cout<<"Total Money Collected = "<<m_TotalMoney<<endl;
        }
};

int main(void)
{
    char Key;
    cTollBooth booth1;
    cout<<"paying car enter <i>\t non-paying car enter <d>\t to show amount enter <s>\t to quit enter <q>"<<endl;
    while(Key != 'q')
    {
        cin>>Key;

        switch (Key)
        {
        case 'i':
            booth1.PayingCar();
            cout<<"Paying Car Added"<<endl;
            break;

        case 'd':
            booth1.NoPayCar();
            cout<<"Non-paying Car Added"<<endl;
            break;

        case 's':
            booth1.Display();
            break;

        default:
            cout<<"Wrong Entery! try again\n";
            break;
        }
    }
    booth1.Display();
    return 0;
}