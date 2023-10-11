#include <iostream>

class CCounter
{
private:
    int counter_;

public:
    CCounter() : counter_(0)
    {
        /*do nothing*/
    }

    CCounter(int value) : counter_(value)
    {
        /*do nothing*/
    }

    CCounter& increment()
    {
        counter_++;
        return (*this);
    }

    CCounter& decrement()
    {
        counter_--;
        return (*this);
    }

    CCounter operator++(int)
    {
        CCounter temp = *this;
        counter_++;
        return temp;
    }

    CCounter operator++(void)
    {
        ++counter_;
        return (*this);
    }

    CCounter operator--(int)
    {
        CCounter temp = *this;
        counter_--;
        return temp;
    }

    CCounter operator--(void)
    {
        --counter_;
        return (*this);
    }

    CCounter operator+(int number)
    {
        return CCounter(counter_ + number);
    }

    CCounter operator-(int number)
    {
        return CCounter(counter_ - number);
    }

    void display()
    {
        std::cout << counter_ << std::endl;
    }
};

int main(void)
{
    CCounter i, j;

    i++;        //1
    --i;        //0
    j++;        //1
    --j;        //0

    j = i++; /*post increment*/   //j=0  , i=1
    j.display();            //0
    i.display();            //1

    std::cout << std::endl;

    j = ++i; /*pre increment*/ //j=2 //i=2
    j.display();    //2
    i.display();    //2

    std::cout << std::endl;

    i=i+5;      //2+5 =7
    i.display();

    j=j-5;      //2-5=-3
    j.display();
    
    return 0;
}
