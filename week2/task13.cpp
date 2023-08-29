// Принимает на вход словарь map<int, string> и возвращает множество значений этого словаря
// компиляция - (g++ -std=c++11 task13.cpp -o task13)

#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(map<int, string> map1)
{
    set<string> result;

    for (const auto& item : map1)
        result.insert(item.second);

    return result;
}

int main()
{
    set<string> result = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (auto str : result)
        cout << str << endl;

    return 0;
}
