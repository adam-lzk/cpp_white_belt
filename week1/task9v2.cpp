// Перевод чисел из 10-чной в 2-чную систему счисления (через остаток от деления) (not my code)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numb;
    vector <int> bits;

    cin >> numb;

    while (numb > 0)
    {
        bits.push_back(numb % 2);  // добавление значения numb % 2 в конец вектора bits
        numb /= 2;
    }

    for (int i = bits.size() - 1; i >= 0; --i)
        cout << bits[i];

    cout << endl;

    return 0;
}
