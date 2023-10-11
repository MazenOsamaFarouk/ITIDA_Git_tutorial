#include <iostream>

using namespace std;

class cCounter
{
    private:
    int m_counts;
    int m_step;

    public:
    cCounter(void):m_counts(0),m_step(1)
    {

    }
    cCounter(int StartValue,int step=1):m_counts(StartValue),m_step(step)
    {

    }
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

	cCounter operator ++() //increment (prefix)
	{
		m_counts += m_step;
		return cCounter(m_counts);
	}

	cCounter operator --() //increment (prefix)
	{
		m_counts -= m_step;
		return cCounter(m_counts);
	}

	void display()
	{
		cout << "Number of counts : " << m_counts << endl;
	}

	
};



int main(void)
{
	cCounter c1(0,1);
    cCounter c2;
    ++c1;
    ++c1;
    c2=--c1;
    c2.display();


	return 0;
}