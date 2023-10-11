#include <iostream>

using namespace std;

class cCounter
{
	private:
		 int m_counter;
		 int m_step;
	public:
		/*cCounter():
			m_counter(0),m_step(1)
		{
			
		}*/
		cCounter(int _count=0, int step = 1):
				m_counter(_count), m_step(step)
		{
					
		}

		//method chain
		cCounter& incrementCount()
		{
			this->m_counter++;
			return (*this);
		}
		cCounter& decrementCount()
		{
			this -> m_counter--;
			return (*this);
		}
		
		int count()
		{
			return m_counter;
		}
		
		cCounter operator ++ ()
		{
			m_counter+=m_step;
			return cCounter(m_counter);
		}
		
		cCounter operator -- ()
		{
			m_counter-=m_step;
			return cCounter(m_counter);
		}
		void display()
		{
			cout << "Counter value is " << m_counter << endl;
		}
	
};


int main(void)
{
	
	cCounter c1;
	++c1;
	cCounter c2(5);
	++c2;
	cCounter c3(0,2);
	++c3;
	
	cout << c1.count() << "  " << c2.count() << "  " << c3.count() << endl;



	cCounter c4;
	--c4;
	cCounter c5(5);
	--c5;
	cCounter c6(2,2);
	--c6;
	cout << c4.count() << "  " << c5.count() << "  " << c6.count() << endl;


	cCounter c7, c8;
	c7 = ++c8;
	
	cout << c7.count() << endl;
	//cCounter count;
	//cCounter count2(3);
	//cout << ++count2 << endl;
	
	
	/*int value;
	bool flag = true;
	
	while(flag){
		cout << "Please enter 1 to increment and 0 to decrement \n";
		cin >> value;
		if(value == 1)
		{
			++count2;
		}
		else if(value == 0)
		{
			--count2;
		}
		else
		{
			cout << " wrong choice \n";
			flag = false;
		}
	}
	count2.display();
*/	
}