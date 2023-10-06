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
    c_counter& increment()
    {
        m_counter++;
        return (*this);
    }
    c_counter& decrement()
    {
        m_counter--;
        return (*this);
    }
    void display()
    {
        cout << m_counter << endl;
    }
};

int main(void)
{
    c_counter i;
    i.increment().increment().increment();
    i.display();
    i.increment();
    i.display();
    i.decrement().decrement().decrement().decrement();
    i.display();

    return 0;
}