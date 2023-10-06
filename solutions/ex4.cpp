#include <iostream>

using namespace std;

class cCounter
{
    private:
        int m_count;

    public:
        cCounter(): m_count(0){}

        void increment()
        {
            m_count++;
        }
        void decrement()
        {
            m_count--;
        }
        int count()
        {
            return m_count;
        }

};

int main (void)
{
	cCounter c1;
	c1.increment();
	c1.increment();
	c1.increment();
	cout << c1.count();
	
	return 0;
}
