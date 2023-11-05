#include <iostream>
#include <fstream> // used for file io on disk
#include <sstream> // string stream --> parsing problems
#include <string>

#include "Student.hpp"
#include "CsvReader.hpp"

using namespace std;
using namespace X;
    

namespace X
{
   void  function(void)
   {
    cout << "Hello\n" ;
   }
}



int main(void)
{

    cout << "Hello2\n";

    X::function();

    FileReader::Csv csv("student.db") ;
    
    csv.read();

    FileContentsArr_t file = csv.getContents();

    Student* school = new Student [csv.getFileSize()]; 

    for(int i=0; i<csv.getFileSize(); i++)
    {
        for(int n=0; n<file.arr[i].length(); n++)
        {
            if(file.arr[i][n] == ',')
            {
                file.arr[i][n] =  ' ' ;
            }
        }
      
        std::stringstream  ss(file.arr[i]) ;   // Mazen,20,5
        ss >>  school[i].Name() >> school[i].Age() >> school[i].StudentClass() ;     
        std::cout << school[i].Print();    
    }

    return 0;
}