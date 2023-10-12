#include <iostream>
#include <string>


int main(void)
{
    std::string input=" This  is   a   very long string   that has many  words " ;
	
	//getline(std::cin, input);
	
	int s_pos ;
	int e_pos ;
	bool isWord=false ;
	
	std::string words[100] ;
	unsigned int word_counter =0 ; 
	
	
	s_pos = input.find_first_not_of(" "); // s_pos = 1, e_pos=5
	
	
	while(s_pos < input.length() )
	{
		e_pos = input.find_first_of(" ", s_pos);
		
		if(e_pos >= 0)
		{
			std::cout << "s_pos: "<<s_pos<<" e_pos: "<<e_pos<<std::endl;
			
			words[word_counter] = input.substr(s_pos, e_pos-s_pos);
			word_counter++ ;
			s_pos = e_pos;
			s_pos = input.find_first_not_of(" ",s_pos );
			
			e_pos = s_pos ;
			
			std::cout << "s_pos: "<<s_pos<<" e_pos: "<<e_pos<<std::endl;
			
			std::cin.ignore();
		}
		else
		{
			std::cin.ignore();
			break;
		}
	}



    return 0;
}