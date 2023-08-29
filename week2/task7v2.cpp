// Переставляет элементы вектора в обратном порядке (через константную ссылку) (not my code)
// компиляция - (g++ -std=c++11 task7v2.cpp -o task7v2)

#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& input)
{
    vector<int> result;

    for (int i = input.size() - 1; i >= 0; --i)
        result.push_back(input[i]);

    return result;
}


int main()
{
    vector<int> v = {1, 3, 5, 7, 9};

    vector<int> v2 = Reversed(v);

    for (auto a : v2)
        cout << a << " ";

    cout << endl;

    return 0;
}
