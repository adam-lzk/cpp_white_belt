// Поиск минимальной строки (not my code)

#include <iostream>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    if (a <= b && a <= c) {  // если все буквы строки строчные (заглавные), то они сравниваются по порядковому номеру в алфавите
        cout << a << endl;
    } else if (b <= a && b <= c) {
        cout << b << endl;
    } else {
        cout << c << endl;
    }

    return 0;
}
