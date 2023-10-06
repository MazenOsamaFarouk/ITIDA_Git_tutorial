#include <iostream>
using namespace std;

class counter
{
private:
int count;
public:
counter() : count(0)
{}
void increment()
{
    count++;
}
void decrement()
{
    count--;
}

void display()
{
    cout<<count;
}
};

int main()
{

    return 0;
}