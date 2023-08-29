// Дописывает все строки из первого вектора в конец второго
// компиляция - (g++ -std=c++11 task5.cpp -o task5)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings (vector<string>& source, vector<string>& destination)
{
    for (string a : source)  // дописываю все строки из первого вектора в конец второго
        destination.push_back(a);

    source.clear();  // очищаю первый вектор
}

int main()
{
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};

    MoveStrings(source, destination);

    for (string a : source)  // вывод первого вектора (пустого)
        cout << a << " ";

    cout << endl;

    for (string b : destination)  // вывод второго вектора
        cout << b << " ";

    cout << endl;

    return 0;
}
