#include <iostream >

using namespace std;

class counter
{
private:
    int c_counter;
public:
    counter() : c_counter(0)
    {
        /*do nothing*/
    }
    void increment()
    {
        c_counter++;
    }
    void decrement()
    {
        c_counter--;
    }
    void display()
    {
        cout<<c_counter<<endl;
    }
};

int main(void)
{
    counter i;
    i.increment();
    i.display();
    i.increment();
    i.display();
    i.decrement();
    i.display();

    return 0;
}