// Сортирует строки в лексикографическом порядке по возрастанию, игнорируя регистр букв
// компиляция - g++ -std=c++11 task2.cpp -o task2

#include <iostream>
#include <vector>
#include <map>

using namespace std;


void MapPrint(const map<string, vector<string> >& base)
{
    for (const auto& item : base)
    {
        for (const string& word : item.second)
        {
            cout << word << " ";
        }
    }

    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    map<string, vector<string> > base;

    vector<string> strs(n);
    for (string& word : strs)
        cin >> word;

    vector<string> strs2 = strs;

    for (string& word : strs2)  // замена всех заглавных букв в словах вектора strs2 строчными
    {
        for (char& ch : word)
        {
            ch = tolower(ch);
        }
    }  // strs - вектор введенных слов; strs2 - вектор strs, где все слова состоят из строчных букв

    for (int i = 0; i < n; i++)
    {
        base[strs2[i]].push_back(strs[i]);  // каждому слову их строчных букв соотносится вектор 
    }                                       // из таких же слов, но некоторые буквы в них - заглавные

    MapPrint(base);

    return 0;
}
