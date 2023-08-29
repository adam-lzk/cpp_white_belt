#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string a = "";
    string b;

    cout << a << endl << b << endl;

    if (a == "")
        cout << "a" << endl;

    if (b == "")
        cout << "b" << endl;

    map <int, vector<string> > m;

    m[1].push_back("abc");
    cout << m[1][0] << endl;
    cout << m[1][1] << endl;
    cout << m[2][1] << endl;  // segmentation fault

    return 0;
}
