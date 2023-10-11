#include <iostream>

using namespace std;

class cCounter
{
	int m_counts;
	signed int step;
public:
	cCounter():
	m_counts(0)
	,step(1)
	{/* nothing to do */}

	cCounter& increment()
	{
		m_counts += step;
		return (*this);
	}

	cCounter& decrement()
	{
		m_counts -= step;
		return (*this);
	}

	cCounter& setStep(int _a)
	{
		step = _a;
		return (*this);
	}

	void operator ++() //increment (prefix)
	{
		m_counts += step;
	}

	void operator --() //increment (prefix)
	{
		m_counts -= step;
	}

	void display()
	{
		cout << "Number of counts : " << m_counts << endl;
	}

	
};



int main(void)
{
	cCounter c;
	
	c.setStep(5);
	++c;
	++c;
	c.display();


	return 0;
}