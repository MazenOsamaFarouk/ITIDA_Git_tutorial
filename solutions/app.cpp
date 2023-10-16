#include <iostream>
#include <string>
using namespace std;

int main() {
    int start,end;
	string str;

    char arr[500]={0};
    std::cin.getline(arr,500);
    str=string(arr);
    start=str.find_first_not_of(".,? :!;");
    

    while(start<=str.size())
    {
        end=str.find_first_of(".,? :!;",start);
        cout<<str.substr(start,end-start)<<endl;
        start=end;
        start=str.find_first_not_of(".,? :!;",start);
    }

    return 0;
}