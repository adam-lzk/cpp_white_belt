#include <iostream>
#include <string>
#include <vector>

using namespace std;

void AddWorld(string s) {
    s += " world";
}

void AddWorldVersion2(string& s) {
    s += " world";
}

int main()
{
    string h1 = "Hello";
    AddWorld(h1);
    cout << h1;
    cout << endl;


    string h2 = "Hello";
    AddWorldVersion2(h2);
    cout << h2;
    cout << endl;

    return 0;
}