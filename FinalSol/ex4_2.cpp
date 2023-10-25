#include<iostream>

using namespace std;

class cCounter
{
    private:
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

int main(void)
{
    cCounter C1;
    cCounter C2(2,1);
    // C1.increment(); C1.decrement(); C1.increment(); C1.decrement(); C1.increment();
    C1.increment().increment().decrement().increment();
    C1.Display();

    C2.increment().increment().decrement();
    C2.Display();
    return 0;
}