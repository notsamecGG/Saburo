#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout<<"Hello World";

    string str= "hello";
    {
        unique_ptr up = make_unique<string>(str);
        
        cout << *up << endl;
    }
    
    cout << str << endl;

    return 0;
}