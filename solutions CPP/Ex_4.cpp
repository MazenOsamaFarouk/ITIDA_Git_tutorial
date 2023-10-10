#include <iostream>
using namespace std;

class cCounter
{
	private:
	int m_count;
	public:
	cCounter():m_count(0){}
	cCounter& increment()
	{
		this->m_count++;
		return(*this);
	}
	cCounter& decrement()
	{
		this->m_count--;
		return(*this);
	}
	int getcount()const
	{
		return m_count;
	}
};
int main(void)
{
	cCounter c1;
	c1.increment().increment().increment().increment().decrement();
	cout<<c1.getcount()<<endl;
	

	return 0;
}