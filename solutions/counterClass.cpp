#include <iostream>
using namespace std;

class counter
{
private:
int count;

public:
//counter() : count(0)
//{count++;}

counter( int step = 1 )
{
    count += step;
}

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

counter operator ++()
{
    count ++;
    return counter()
}

counter operator --()
{
    count --;
}


};

int main()
{
    counter c1;
    ++c1;
    --c1;
    c1.display();

    return 0;
}