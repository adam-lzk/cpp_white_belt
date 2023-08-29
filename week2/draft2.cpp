#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a = "asdfgh";

    cout << a.size() << endl;
    cout << a[0] << endl;

    if (a.size() >= 6)
        cout << "more\n";
    //if ((a[0]).size() >= 6)
    //    cout << "more";



    vector<string> b;
    b.push_back("asd");
    b.push_back("sdf");
    b.push_back("dfg");
    cout << b.size() << endl;
    cout << b[0] << endl;
    cout << b[0].size() << endl;
    

    return 0;
}