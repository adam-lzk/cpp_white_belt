// Сортировка элементов в порядке возрастания их абсолютной величины (через sort) (not my code)
// компиляция - g++ -std=c++11 task1v2.cpp -o task1v2

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int& x : v)
        cin >> x;

    // сортируем
    sort(begin(v), end(v), [](int l, int r) {
        return abs(l) < abs(r);
    });  // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r

    // выводим отсорированный вектор
    for (int x : v)
        cout << x << " ";

    return 0;
}
