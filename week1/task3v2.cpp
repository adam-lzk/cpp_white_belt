// Поиск корней квадратных уравнений (not my code)

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (a != 0)  // ax^2 + bx + c = 0 - квадратное
    {
        double discr = b*b - 4*a*c;

        if (discr > 0)
            cout << (-b + sqrt(discr)) / (2*a) << " " << (-b - sqrt(discr)) / (2*a) << endl;

        if (discr == 0)
            cout << -b / (2*a) << endl;
    }  // if (discr < 0) то нет корней

    if (a == 0)  // bx + c = 0 - линейное
    {
        if (b != 0)
        {
            cout << -c / b;
        }
    }  // if (b = 0) то нет корней

    return 0;
}
