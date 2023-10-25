#include<iostream>

using namespace std;

class cEmployee
{
    protected:
        string m_name;
        int m_age;
    public:
        cEmployee(string _name, int _age): m_name(_name), m_age(_age) {     }

        virtual void printPosition() const = 0;
};

class cEngineer : public cEmployee
{
    private:

    public:
        using cEmployee::cEmployee; // This line inherits all constructors found in Base class
        // cEngineer(string _name, int _age): cEmployee(_name,_age) {     } // here we call cEmplyess constructor to inialize the base class data
        
        void printPosition() const
        {
            cout<<"The Engineer name is : "<<m_name<<endl;
            cout<<"The Engineer age is : "<<m_age<<endl;
        }
};

class cManager : public cEmployee
{
    private:

    public:
        using cEmployee::cEmployee; // This line inherits all constructors found in Base class
        // cEngineer(string _name, int _age): cEmployee(_name,_age) {     } // here we call cEmplyess constructor to inialize the base class data
        
        void printPosition() const
        {
            cout<<"The Manager name is : "<<m_name<<endl;
            cout<<"The Manager age is : "<<m_age<<endl;
        }
};

class cSalesman : public cEmployee
{
    private:

    public:
        using cEmployee::cEmployee; // This line inherits all constructors found in Base class
        // cEngineer(string _name, int _age): cEmployee(_name,_age) {     } // here we call cEmplyess constructor to inialize the base class data
        
        void printPosition() const
        {
            cout<<"The Salesman name is : "<<m_name<<endl;
            cout<<"The Salesman age is : "<<m_age<<endl;
        }
};

int main(void)
{
    cEngineer e1("hamada",23);
    e1.printPosition();

    cManager m1("Modeer",55);
    m1.printPosition();

    cSalesman s1("Mamdouh",20);
    s1.printPosition();

    return 0;
}