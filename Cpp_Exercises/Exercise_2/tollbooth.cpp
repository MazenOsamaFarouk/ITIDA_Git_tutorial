#include <iostream>
#include <algorithm>
#include <string>

#define CAR 1
#define BUS 2
#define TRUCK 3
#define OTHER 4

#define CAR_FEE 0.50
#define BUS_FEE 1
#define TRUCK_FEE 2
#define OTHER_FEE 3

class c_tollbooth
{
private:
    bool m_error;
    unsigned int m_Paying_Vehicles;
    unsigned int m_Non_Paying_Vehicles;
    unsigned int m_Number_of_Cars;
    unsigned int m_Number_of_Busses;
    unsigned int m_Number_of_Trucks;
    unsigned int m_Number_of_Others;
    double m_MoneyCollected;

public:
    /*constructor with initializer list
    constructor is a method with the exact same name as the class 
    that get called when creating an object from a class
    takes nothing "void" is not allowed also and initializes variables*/
    c_tollbooth() : m_error(false),
                    m_Paying_Vehicles(0),
                    m_Non_Paying_Vehicles(0),
                    m_Number_of_Cars(0),
                    m_Number_of_Busses(0),
                    m_Number_of_Trucks(0),
                    m_Number_of_Others(0),
                    m_MoneyCollected(0)
    {/*do nothing*/}

    bool PayingVehicles(int VehicleType)
    {
        m_error = false;

        switch (VehicleType)
        {
        case CAR:   m_Number_of_Cars++;   m_MoneyCollected += CAR_FEE;   break;
        case BUS:   m_Number_of_Busses++; m_MoneyCollected += BUS_FEE;   break;
        case TRUCK: m_Number_of_Trucks++; m_MoneyCollected += TRUCK_FEE; break;
        case OTHER: m_Number_of_Others++; m_MoneyCollected += OTHER_FEE; break;
        default:    m_error = true;                                      break;
        }

        m_Paying_Vehicles++;
        std::cout << "Paying Vehicles count: " << m_Paying_Vehicles << "." << std::endl;
        return m_error;
    }

    bool NonPayingVehicles(int VehicleType)
    {
        m_error = false;

        switch (VehicleType)
        {
        case CAR:   m_Number_of_Cars++;   break;
        case BUS:   m_Number_of_Busses++; break;
        case TRUCK: m_Number_of_Trucks++; break;
        case OTHER: m_Number_of_Others++; break;
        default:    m_error = true;       break;
        }

        m_Non_Paying_Vehicles++;
        std::cout << "Non Paying Vehicles count: " << m_Non_Paying_Vehicles << "." << std::endl;
        return m_error;
    }

    void DisplayHelpList(void)
    { 
        std::cout << std::endl << "Welcome to tollbooth Program v0.0.1." << std::endl;
        std::cout << "|---------------Help---------------|" << std::endl;
        std::cout << "|Input \"pc\" for paying car.        |" << std::endl;
        std::cout << "|Input \"pb\" for paying bus.        |" << std::endl;
        std::cout << "|Input \"pt\" for paying truck.      |" << std::endl;
        std::cout << "|Input \"po\" for paying other.      |" << std::endl;
        std::cout << "|----------------------------------|" << std::endl;
        std::cout << "|Input \"nc\" for non paying car.    |" << std::endl;
        std::cout << "|Input \"nb\" for non paying bus.    |" << std::endl;
        std::cout << "|Input \"nt\" for non paying truck.  |" << std::endl;
        std::cout << "|Input \"no\" for non paying other.  |" << std::endl;
        std::cout << "|----------------------------------|" << std::endl;
        std::cout << "|Input \"exit\" To Exit Program.     |" << std::endl;
        std::cout << "|Input \"help\" To Display Help.     |" << std::endl;
        std::cout << "|Input \"status\" To Display Status. |" << std::endl;
        std::cout << "*---------------End.---------------*" << std::endl << std::endl;
    }

    void DisplayStatus(void)
    {
        std::cout << std::endl << "***************Status***************" << std::endl;
        std::cout << "Number of Cars: " << m_Number_of_Cars << "." << std::endl;
        std::cout << "Number of Busses: " << m_Number_of_Busses << "." << std::endl;
        std::cout << "Number of Trucks: " << m_Number_of_Trucks << "." << std::endl;
        std::cout << "Number of Others: " << m_Number_of_Others << "." << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Number of Paying Vehicles: " << m_Paying_Vehicles << "." << std::endl;
        std::cout << "Number of Non Paying Vehicles: " << m_Non_Paying_Vehicles << "." << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Total Number of Vehicles: " << m_Paying_Vehicles + m_Non_Paying_Vehicles << "." << std::endl;
        std::cout << "Total Cash Collected: " << m_MoneyCollected << " EGP." << std::endl;
        std::cout << "****************END.****************" << std::endl << std::endl;
    }

    void DisplayError(void)
    {
        std::cout << std::endl << "Error Please Try Again." << std::endl;
        std::cout << "To Display List of Commands Type \"help\"." << std::endl << std::endl;
    }
};

int main(void)
{
    std::string user_input;
    c_tollbooth Cairo_tollbooth;
    Cairo_tollbooth.DisplayHelpList();

    while (1)
    {

        std::cout << "User Input: ";
        std::cin >> user_input;
        std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

        if      (user_input == "pc")    {Cairo_tollbooth.PayingVehicles(CAR);}
        else if (user_input == "pb")    {Cairo_tollbooth.PayingVehicles(BUS);}
        else if (user_input == "pt")    {Cairo_tollbooth.PayingVehicles(TRUCK);}
        else if (user_input == "po")    {Cairo_tollbooth.PayingVehicles(OTHER);}
        else if (user_input == "nc")    {Cairo_tollbooth.NonPayingVehicles(CAR);}
        else if (user_input == "nb")    {Cairo_tollbooth.NonPayingVehicles(BUS);}
        else if (user_input == "nt")    {Cairo_tollbooth.NonPayingVehicles(TRUCK);}
        else if (user_input == "no")    {Cairo_tollbooth.NonPayingVehicles(OTHER);}
        else if (user_input == "help")  {Cairo_tollbooth.DisplayHelpList();}
        else if (user_input == "status"){Cairo_tollbooth.DisplayStatus();}
        else if (user_input == "exit")  {break;}
        else                            {Cairo_tollbooth.DisplayError();}

    };

    return 0;
}