#include <iostream >

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

    CCounter &increment()
    {
        counter_++;
        return (*this);
    }

    CCounter &decrement()
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
    i++;
    j++;
    --i;
    --j;

    j = i++; /*post increment*/
    j.display();
    i.display();
    std::cout << std::endl;
    j = ++i; /*pre increment*/
    j.display();
    i.display();

    std::cout << std::endl;

    i=i+5;
    i.display();

    j=j-5;
    j.display();

    return 0;
}