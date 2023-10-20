#include <iostream>
using namespace std;

class cCounter
{
    protected:
        int m_count;

    public:
        cCounter(): m_count(0){}
        cCounter(int c): m_count(c){};


        int count()
        {
            return m_count;
        }

};

class SimpleCounter: public cCounter
{
    public:
        SimpleCounter(): cCounter(){};
        SimpleCounter(int n): cCounter(n){};

        SimpleCounter operator ++ (int)
        {
            m_count++;
            return SimpleCounter(m_count);
        }
        SimpleCounter& increment()
        {
            m_count++;
            return(*this);
        }
};

class ExtendedCounter: public cCounter
{
    public:
        ExtendedCounter(): cCounter(){};
        ExtendedCounter(int n): cCounter(n){};

        ExtendedCounter operator += (int n)
        {
            m_count += n;
            return ExtendedCounter(m_count);
        }
        ExtendedCounter operator -= (int n)
        {
            m_count -= n;
            return ExtendedCounter(m_count);
        }
        ExtendedCounter& increment()
        {
            m_count++;
            return(*this);
        }
        ExtendedCounter& decrement()
        {
            m_count--;
            return(*this);
        }

};

int main (void)
{
	SimpleCounter c1;
	ExtendedCounter c2;

	c1++;
	c1.increment().increment();

	c2 -= 5;
	c2.decrement().decrement();

	cout << c1.count()<<endl<<c2.count();

	return 0;
}