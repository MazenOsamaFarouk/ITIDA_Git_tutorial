#include<iostream>

using namespace std;

class cCounter
{
    private:
        int m_Counter;
    public:
        cCounter():m_Counter(0) { }
        cCounter(int init):m_Counter(init) { }

        /*
            //using the normal methods
        void increment() { m_Counter++ ;}
        void decrement() { m_Counter-- ;}
        */
            //Method chaining
        cCounter& increment() 
        { 
            m_Counter++;
            return (*this); 
        }

        cCounter& decrement() 
        { 
            m_Counter--;
            return (*this); 
        }
        
        void Display() { cout<<"counter = "<< m_Counter<<endl; }
};

int main(void)
{
    cCounter C1;
    // C1.increment(); C1.decrement(); C1.increment(); C1.decrement(); C1.increment();
    C1.increment().increment().decrement().increment();
    C1.Display();
    return 0;
}