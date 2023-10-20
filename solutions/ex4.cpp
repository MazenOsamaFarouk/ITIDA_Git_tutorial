#include <iostream>
using namespace std;

class cCounter
{
    private:
        int m_count;

    public:
        cCounter(): m_count(0){}

        cCounter& increment()
        {
            m_count++;
            return(*this);
        }
        cCounter& decrement()
        {
            m_count--;
            return(*this);
        }
        int count()
        {
            return m_count;
        }

};

int main (void)
{
	cCounter c1;
	c1.increment().increment().increment().decrement();
	cout << c1.count();

	return 0;
}
