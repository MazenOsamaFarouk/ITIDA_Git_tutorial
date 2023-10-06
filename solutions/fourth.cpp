#include <iostream>

using namespace std;

class cCounter
{
	private:
		unsigned int m_counter;
	public:
		cCounter():
			m_counter(0)
		{
			
		}
		void incrementCount()
		{
			m_counter++;
		}
		void decrementCount()
		{
			m_counter--;
		}
		void display()
		{
			cout << "Counter value is " << m_counter << endl;
		}
	
};


int main(void)
{
	cCounter count;
	
	
	int value;
	bool flag = true;
	
	while(flag){
		cout << "Please enter 1 to increment and 0 to decrement \n";
		cin >> value;
		if(value == 1)
		{
			count.incrementCount();
		}
		else if(value == 0)
		{
			count.decrementCount();
		}
		else
		{
			cout << " wrong choice \n";
			flag = false;
		}
	}
	count.display();
	
}