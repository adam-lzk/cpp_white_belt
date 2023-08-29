// Деление a на b нацело

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b == 0)
        cout << "Impossible\n";
    else
        cout << a/b << endl;

    return 0;
}
