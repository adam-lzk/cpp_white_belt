// Нахождение НОД 2-х чисел

#include <iostream>
using namespace std;

int main()
{
    int a, b, min;
    cin >> a >> b;

    if (a <= b)
        min = a;
    else min = b;  // нахожу минимальное из 2-х чисел

    for (int i = min; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
