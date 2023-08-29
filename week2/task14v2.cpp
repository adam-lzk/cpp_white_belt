// Синонимы (иное исполнение кода в CHECK)
// компиляция - (g++ -std=c++11 task14v2.cpp -o task14v2)
/*
ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
COUNT word — узнать количество синонимов слова word.
CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами.
Слова word1 и word2 считаются синонимами,
если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
Для упрощения, будем считать, что если A - синоним B, а B - синоним C, то из этого НЕ следует, что A - синоним C.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
    map<string, set<string>> wordsBase;  // каждому слову сопоставляется set из слов его синонимов

    int requestsNumber;
    cin >> requestsNumber;

    for (int i = 0; i < requestsNumber; i++)
    {
        string request;
        cin >> request;


        if (request == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;

            wordsBase[word1].insert(word2);  // wordsBase[word1] - set из строк
            wordsBase[word2].insert(word1);  // word 1 - синоним слова word2 и word2 - синоним слова word1

            continue;
        }


        if (request == "COUNT")
        {
            string word;
            cin >> word;

            cout << wordsBase[word].size() << endl;

            continue;
        }


        if (request == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;

            if (wordsBase[word1].count(word2) == 1)
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;

            continue;
        }
    }

    return 0;
}
