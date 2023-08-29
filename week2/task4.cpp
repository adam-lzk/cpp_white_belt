// Если первое число больше второго, то поменять значение второго на значение первого

#include <iostream>

using namespace std;

void UpdateIfGreater(int first, int& second)  // меняется лишь значение second, поэтому згачение second передаем по ссылке
{
    if (first > second)
        second = first;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << a << " " << b << endl;

    UpdateIfGreater(a, b);

    cout << a << " " << b << endl;

    return 0;
}
