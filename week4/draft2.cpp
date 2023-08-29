//
// компиляция - g++ -std=c++11 draft2.cpp -o draft2

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void Print(const vector<string>& names, const vector<double>& values, int width)
{
    for (const auto& n : names)
        cout << setw(width) << n;  // set width

    cout << endl;

    cout << fixed;  // для вывода всех чисел с десятичной точкой (не в экспоненциальном виде)
    cout << setprecision(2);  // для вывода 2-х знаков после запятой
    for (const auto& v : values)
        cout << setw(width) << v;
}

int main()
{
    vector<string> names = {"a", "b", "c"};
    vector<double> values = {5, 0.01, 0.000003};

    cout << endl << "-------------------------------------------------" << endl;

    for (const auto& n : names)  //неаккуратный вывод
        cout << n << " ";

    cout << endl;

    for (const auto& v : values)
        cout << v << " ";

    cout << endl << "-------------------------------------------------" << endl;


    Print(names, values, 10);
    cout << endl << "-------------------------------------------------" << endl;


    cout << setfill('.');  // заполнитель для setw - заполнение пустого пространства знакоми '.'
    cout << left;  // выравнивание по левому краю
    Print(names, values, 10);
    cout << endl << "-------------------------------------------------" << endl << endl;

    return 0;
}
