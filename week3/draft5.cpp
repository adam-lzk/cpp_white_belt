#include <iostream>

using namespace std;

void f(int x)
{
    cout << x;
    return;
    cout << x;
}

int main()
{
    f(5);
    return 0;
}