#include<iostream>
#include<fstream>
#include<strstream>
#include<string>
class CsvReader
{
public:
void read()
{
std::fstream fin("file.txt");
}
void write(std::string str,int x ,int y)
{
std::ofstream fout("file.txt");
fout<<str<<x<<y;
}

};
class student : public CsvReader
{
int age;
std:: string name;
int cls;
public:
void print(){};
};
int main ()
{
student one ;
one.write("Aone",1,2);
/*std::string str ("strings in the file");
std::ofstream fout("file.txt");
fout<<str;
fout<<"hello line2";
//std::fstream fin("file.txt");
//fin>>str;*/
return 0 ;
}