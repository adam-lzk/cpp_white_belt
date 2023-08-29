#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int a = 5;

int funct(int a = 4)
{
    a++;
    return a;
}

int main()
{
    a = 4;
    funct(a);
    cout << a << endl;

    return 0;
}
