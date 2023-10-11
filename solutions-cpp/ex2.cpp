#include <iostream>

class cTollBooth
{
    public:
       // initializer list
        cTollBooth():
            m_totalCars(0)  ,
            m_totalMoney(0) 
        { /* nothing to do */}

        void nopayCar()
        {
            m_totalCars++;
        }

        void payingCar()
        {
            nopayCar();
            m_totalMoney += 0.5 ;
        }

        void display()
        {
            std::cout << "total Cars: " << m_totalCars << std::endl;
            std::cout << "total Money: " << m_totalMoney << std::endl;
        }
    private:
        unsigned int m_totalCars;
        double m_totalMoney;
};



int main()
{
    // int z = 30 ;
    // int x(10); // int x = 10;
    // // int y{20}; // int y = 20


    cTollBooth booth;
    // cTollBooth booth = cTollBooth(12,23);
    char ch = '2';
    bool run = true;
    while(run)
    {
        std::cin >> ch ;
        switch(ch)
        {
            case 'p':
                booth.payingCar();
            break;

            case 'n':
                booth.nopayCar();
            break;

            case 'q':
                run = false;
            break;

            default:
            std::cout << "Wrong choice " << std::endl;
            break;
        }
    }
    booth.display();


    return 0;
}