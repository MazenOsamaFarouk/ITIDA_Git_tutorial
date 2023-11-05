#include <iostream>
#include <fstream> // used for file io on disk
#include <sstream> // string stream --> parsing problems
#include <string>

#define MAX_LINES   100
#define MAX_CHARS_PER_LINE   1000

struct FileContentsArr_t
{
    std::string arr[MAX_LINES];
};



class CsvReader
{
public:
    CsvReader(std::string file_path):
    m_reader(file_path),
    m_writer(file_path),
    m_file_no_lines(0)
    {

    }
    void read() // read enitre file contents
    {
        int i=0;
        while(!m_reader.eof())
        {
            std::getline(m_reader,m_file_contents.arr[i]);
            i++ ;
        }
        m_file_no_lines = i ;
    }

    void write() // write entire file contents
    {
        for(int i=0; i< m_file_no_lines; i++)
        {
            m_writer << m_file_contents.arr[i];
        }
    }

    FileContentsArr_t getContents()
    {
        return m_file_contents ;
    }

private:
    std::ifstream m_reader;
    std::ofstream m_writer;
    FileContentsArr_t m_file_contents ;
    unsigned int m_file_no_lines;

};

enum Class
{
    Class_A,
    Class_B,
    Class_C,
    Class_D,
    Class_E,
    Class_F,
    
};




class Student
{
    Student(std::string name, int age, Class c ):
    m_age(age),
    m_name(name),
    m_class(c)
    {}

    int& Age(){ return m_age; }
    std::string& Name( ){ return m_name; }
    Class& StudentClass() { return m_class; }

    std::string ClassToString(Class c)
    {
        switch(c)
        {
            case Class_A:
                return "Class_A" ;
            break;

            case Class_B:
                return "Class_A" ;
            break;
            case Class_C:
                            return "Class_A" ;
                        break;
            case Class_D:
                            return "Class_A" ;
                        break;
            case Class_E:
                            return "Class_A" ;
                        break;
            case Class_F:
                            return "Class_A" ;
                        break;
        }
    }

    std::string Print()
    {
        std::string output;
        output = m_name + "," + std::to_string(m_age) + "," + ClassToString(m_class) + "\n"; // "Class_A"
    }

private:
    int m_age;
    std::string m_name;
    Class m_class; // A,B,C,D,F
};



int main(void)
{
    std::string str = "This is a sentence written int eh code\n";

    // std::ofstream fout("file.txt");

    // fout << str ;
    // fout << "addtional strings in nthe file \n";

    std::ifstream fin("file.txt");
    // int arr[10] ;
    
    // float f;
    // for(int i=0; i<4; i++)
    // {
    //     fin >> arr[i] ; 
    // }
    // fin >> str >> f ;

    // std::cout << "File contents: \n" ;
    // for(int i=0; i<4; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }

    // std::cout << "\n " << str << "\n" << f << std::endl;

    std::string file_contents ;
    // EOF: End oif file flag: in Windows (CTRL+Z+Enter), inn Linux (CTRL+D)
    while( !fin.eof())
    {
        std::string temp;
        fin >> temp ;
        file_contents = (file_contents +  " " + temp); 
    }
    std::cout << file_contents << std::endl;









    return 0;
}