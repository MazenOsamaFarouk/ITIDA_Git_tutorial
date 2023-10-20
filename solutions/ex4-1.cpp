#include <iostream>
using namespace std;

class cCounter
{
    private:
        int m_count;

    public:
        cCounter(): m_count(0){}
        cCounter(int c): m_count(c){};

        cCounter operator ++ ()
        {
            ++m_count;
            return cCounter(m_count);
        }
        cCounter operator -- ()
        {
            --m_count;
            return cCounter(m_count);
        }
        int count()
        {
            return m_count;
        }

};

int main (void)
{
	cCounter c1, c2;
	++c1;
	c2 = ++c1;

	cout << c1.count()<<endl<<c2.count();

	return 0;
}