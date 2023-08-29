// Переставляет элементы вектора в обратном порядке (через константную ссылку)
// компиляция - (g++ -std=c++11 task7.cpp -o task7)

#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& input)
{
    vector<int> result = input;
    const int SIZE = result.size();
    int buff;

    for (int i = 0; i < SIZE / 2; i++)
    {
        buff = result[i];
        result[i] = result[SIZE - 1 - i];
        result[SIZE - 1 - i] = buff;  // swap(result[i], result[SIZE - 1 - i]);
    }

    return result;
}


int main()
{
    vector<int> input = {1, 3, 5, 7, 9};

    vector<int> result = Reversed(input);

    for (auto a : result)
        cout << a << " ";

    cout << endl;

    return 0;
}
