#include<iostream>

using namespace std;

const char ESC = '2';
const double toll = 0.5;

class tollbooth
{
    private:
        unsigned int totalCars;
        double totalCash;
    public:
        tollbooth(): totalCars(0),totalCash(0)
        {
            /*do nothing*/
        }
        void pay()
        {
            totalCars++;
            totalCash += toll;
        }
        void noPay()
        {
            totalCars++;
        }
        void display()
        {
            cout << "Total number of cars: " << totalCars << endl;
            cout << "Total cash collected: " << totalCash << endl;
        }
};

int main()
{
    tollbooth tollbooth;
    char ch;
    cout << "Enter 0 for each non-paying car" << endl;
    cout << "Enter 1 for each paying car" << endl;
    cout << "Press 2 to exit" << endl;
    while(ch != ESC)
    {
        cout<<"Please Enter : "<<endl;
        cin >> ch;
        if(ch == '0')
        {
            tollbooth.noPay();
        }
        if(ch == '1')
        {
            tollbooth.pay();
        }
    }
    tollbooth.display();
    return 0;
}