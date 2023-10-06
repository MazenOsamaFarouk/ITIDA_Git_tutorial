#include <iostream>

using namespace std;

class cCounter
{
	int m_counts;
public:
	cCounter():
	m_counts(0)
	{/* nothing to do */}

	cCounter& increment()
	{
		m_counts++;
		return (*this);
	}

	cCounter& decrement()
	{
		m_counts--;
		return (*this);
	}

	void display()
	{
		cout << "Number of counts : " << m_counts << endl;
	}

	
};



int main(void)
{
	cCounter count1;

	count1.increment().increment().increment().increment().decrement().display();

	return 0;
}