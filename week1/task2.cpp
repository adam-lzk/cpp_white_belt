// Поиск минимальной строки

#include <iostream>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 1; i++)  // одна итерация
    {
        if (a <= b && a <= c)  // если все буквы строки строчные (заглавные), то они сравниваются по порядковому номеру в алфавите
        {
            cout << a << endl;
            break;
        }

        if (b <= a && b <= c)
        {
            cout << b << endl;
            break;
        }

        if (c <= a && c <= b)
        {
            cout << c << endl;
            break;
        }
    }

    return 0;
}
