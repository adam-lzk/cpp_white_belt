// Переставляет элементы вектора в обратном порядке
// компиляция - (g++ -std=c++11 task6.cpp -o task6)

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& numbers)
{
    int buff;
    const int SIZE = numbers.size();

    for (int i = 0; i < SIZE / 2; i++)
    {
        buff = numbers[i];
        numbers[i] = numbers[SIZE - 1 - i];
        numbers[SIZE - 1 - i] = buff;  // swap(numbers[i], numbers[SIZE - 1 - i]);
    }
}


int main()
{
    vector<int> numbers = {1, 5, 3, 4, 2};

    Reverse(numbers);

    for (auto a : numbers)
        cout << a << " ";

    cout << endl;

    return 0;
}
