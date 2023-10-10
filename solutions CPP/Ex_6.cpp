#include <iostream>
#include <string>

int main(void)
{
	std::string input;
	std::cin>>input;
	int size =input.size();
	for (int i=size,j=0;i>=0;i--,j++)
	{
		if(j%3==0 && i!=0 && i!=size)
		{
			input.insert(i,",");
		}
	
	}
	std::cout<<input;
	return 0;
}