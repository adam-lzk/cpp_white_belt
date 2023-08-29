// Поиск корней квадратных уравнений

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 1; i++) // одна итерация
    {
        if (a != 0 && b != 0 && c != 0)
        {
            double discr = b*b - 4*a*c;

            if (discr > 0)
            {
                cout << (-b + sqrt(discr)) / (2*a) << " " << (-b - sqrt(discr)) / (2*a) << endl;
                break;
            } else if (discr == 0)
            {
                cout << -b / (2*a) << endl;
                break;
            } else break;
        }

        if (a == 0 && b != 0 && c != 0)
        {
            cout << -c/b << endl;
            break;
        }

        if (a != 0 && b == 0 && c != 0)
        {
            if (-c/a > 0)
                cout << sqrt(-c/a) << " " << -sqrt(-c/a) << endl;
            break;
        }

        if (a != 0 && b != 0 && c == 0)
        {
            cout << 0 << " " << -b/a << endl;
            break;
        }

        if (a == 0 && b == 0 && c != 0)
        {
            break;
        }

        if (a == 0 && b != 0 && c == 0)
        {
            cout << 0 << endl;
            break;
        }

        if (a != 0 && b == 0 && c == 0)
        {
            cout << 0 << endl;
            break;
        }
    }

    return 0;
}
