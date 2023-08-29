// Сортировка элементов в порядке возрастания их абсолютной величины
// компиляция - g++ -std=c++11 task1.cpp -o task1

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int requestNumber;
    cin >> requestNumber;

    map<int, vector<int> > result;

    for (int i = 0; i < requestNumber; i ++)
    {
        int a;
        cin >> a;
        result[abs(a)].push_back(a);
    }

    for (const auto& item : result)
    {
        for (const auto& element : item.second)
            cout << element << " ";
    }

    cout << endl;

    return 0;
}
