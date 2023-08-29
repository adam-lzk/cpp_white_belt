// Поиск количества уникальных строк в наборе

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int requestsNumber;
    cin >> requestsNumber;

    set<string> words;
    string str;

    for (int i = 0; i < requestsNumber; i++)
    {
        cin >> str;
        words.insert(str);
    }

    cout << words.size() << endl;

    return 0;
}
