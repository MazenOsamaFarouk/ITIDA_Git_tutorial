#include <iostream >

using namespace std;

class c_counter
{
private:
    int m_counter;
public:
    c_counter() : m_counter(0)
    {
        /*do nothing*/
    }
    void increment()
    {
        m_counter++;
    }
    void decrement()
    {
        m_counter--;
    }
    void display()
    {
        cout<<m_counter<<endl;
    }
};

int main(void)
{
    c_counter i;
    i.increment();
    i.display();
    i.increment();
    i.display();
    i.decrement();
    i.display();

    return 0;
}