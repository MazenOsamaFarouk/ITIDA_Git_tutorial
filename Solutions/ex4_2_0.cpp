#include <iostream>

using namespace std;

class cCounter
{
	int m_counts;
	signed int m_step;
public:
	cCounter():
	m_counts(0)
	,m_step(1)
	{/* nothing to do */}


	cCounter& increment()
	{
		m_counts += m_step;
		return (*this);
	}

	cCounter& decrement()
	{
		m_counts -= m_step;
		return (*this);
	}

	cCounter& setStep(int _a)
	{
		m_step = _a;
		return (*this);
	}

	void operator ++() //increment (prefix)
	{
		m_counts += m_step;
		
	}

	void operator --() //increment (prefix)
	{
		m_counts -= m_step;
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