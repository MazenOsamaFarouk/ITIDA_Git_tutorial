#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
using namespace std;
template<class T>
class CsvReader
{
    private:
        fstream out;
        istream fin;
    public:
        CsvReader(string file_name):out(file_name){}
        void write(T input)
        {
            out>>input;
            out>>" ";
        }
        void read(T item)
        {
            while(! fin.eof())
            {
                fin>>*ptr;
            }
        }
};
class Student
{
    private:
        int age;
        string name;
        int class_of_student;
        CsvReader<int> csvReader; 
    public:
        Student(int cp_age,string cp_name,int cp_class_of_student):age(cp_age),name(cp_name),class_of_student(cp_class_of_student){}
        void set_student_data()
        {
            csvReader.write(age);
            csvReader.write(class_of_student);
        }
        void read_student_data()
        {
            cout<<age<<" "<<class_of_student<<endl;
        }    
}
int main()
{

    return 0;
}