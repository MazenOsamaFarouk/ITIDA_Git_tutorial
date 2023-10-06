#include <iostream>

using namespace std;

class cCounter
{
	signed int m_counts;
public:
	cCounter():
	m_counts(0)
	{/* nothing to do */}

	void increment()
	{
		m_counts++;
	}

	void decrement()
	{
		m_counts--;
	}

	void display()
	{
		cout << "Number of counts : " << m_counts << endl;
	}

	
};



int main(void)
{
	cCounter count1;

	count1.increment();
	count1.increment();
	count1.decrement();
	count1.display();


	return 0;
}