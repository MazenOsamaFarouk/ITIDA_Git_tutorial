#include <iostream>
using namespace std;

class tollbooth
{
	private:
	unsigned int totalcars;
	double totalmoney;
	public:
	tollbooth()
	{
		totalcars=0;
		totalmoney=0.0;
	}
	void payingcar()
	{
		totalcars++;
		totalmoney+=0.50;
	}
	void nonpayingcar()
	{
		totalcars++;
	}
	void display() const
	{
		cout<<"totalcars are:"<<totalcars<<endl;
		cout<<"totalmoney are:"<<totalmoney<<endl;
	}
	
};
int main(void)
{
	char  input,flag=0;
	tollbooth obj;
	while (flag == 0)
	{
	cout<<"Please enter a key:";
	cin>>input;
	switch (input)
	{
	case 'n':
	obj.payingcar();
	break;
	case 'm':
	obj.nonpayingcar();
	break;
	case 'q':
	obj.display();
	flag=1;
	break;
	default:
	cout<<"Please enter a valid char"<<endl;
	}
	
	
	}
	return 0;
}