// Подсчёт факториала числа

#include <iostream>
using namespace std;

int Factorial (int x)
{
    if (x > 1)
    {
        for (int i = (x - 1); i > 1; i--)
            x *= i;
    }
    else x = 1;

    return x;
}

int main()
{
    int n;
    cin >> n;
    cout << Factorial(n) << endl;

    return 0;
}
