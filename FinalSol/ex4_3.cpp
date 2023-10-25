#include<iostream>

using namespace std;

class cCounter
{
    protected:
        int m_Counter;
        int m_step;
    public:
        cCounter():m_Counter(0),m_step(1) { }
        cCounter(int initCounter, int initStep):m_Counter(initCounter),m_step(initStep) { }

        /*
            //using the normal methods
        void increment() { m_Counter++ ;}
        void decrement() { m_Counter-- ;}
        */
            //Method chaining
        cCounter& increment() 
        { 
            m_Counter+=m_step;
            return (*this); 
        }

        cCounter& decrement() 
        { 
            m_Counter-=m_step;
            return (*this); 
        }
        
        void Display() { cout<<"counter = "<< m_Counter<<endl; }
};



class cSimpleCounter : private cCounter
{
    public:
        cSimpleCounter() { m_step = 1 ; }

        cSimpleCounter& increment()
        {
            m_Counter+=m_step;
            return (*this);
        }

        void Display() { cCounter::Display(); }
};

class cExtendedCounter : private cCounter
{   
    public:
        cExtendedCounter() { m_Counter=0; m_step= 1; }
        cExtendedCounter(int initStep) { m_Counter=0; m_step= initStep; }
    
        cExtendedCounter& increment()
        {
            m_Counter+=m_step;
            return (*this);
        }

        cExtendedCounter& decrement()
        {
            m_Counter -= m_step;
            return (*this);
        }

        void Display() { cCounter::Display(); }
};

int main(void)
{
    cSimpleCounter C1;
    C1.increment().increment().increment();
    C1.Display();

    cExtendedCounter C2(2);
    C2.increment().increment().decrement();
    C2.Display();
    return 0;
}