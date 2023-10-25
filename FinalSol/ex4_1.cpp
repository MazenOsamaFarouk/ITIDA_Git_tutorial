#include<iostream>

using namespace std;

class cCounter
{
    private:
        int m_Counter;
    public:
        cCounter():m_Counter(0) { }
        cCounter(int init):m_Counter(init) { }

            //Operator OverLoading
        cCounter operator++(void) //prefix
        { 
            m_Counter++;
            // cCounter temp(m_Counter);
            // return temp;
            //instead use the following line
            return cCounter(m_Counter); // as to do NewObj = ++CurrentObject
        }
            // Method chaining
        cCounter& increment(void)
        { 
            m_Counter++;
            return (*this); 
        }

        cCounter operator--() //prefix
        { 
            m_Counter--;
            return cCounter(m_Counter);
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
    C1.increment(); C1.decrement(); C1.increment(); C1.decrement(); C1.increment();
    ++C1;
    ++C1;
    --C1;
    C1.Display();
    return 0;
}