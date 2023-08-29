// Проверка пар слов на анаграммность
// слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом
// компиляция - (g++ -std=c++11 task10.cpp -o task10)

#include <iostream>
#include <vector>
#include <map>

using namespace std;


vector<bool> BuildCharCounters(const vector<vector<string>>& anagrams)
{
    map<char, int> checkWord1;  // хранит буквы, встречающиеся во введенных словах и количество повторов этих букв
    map<char, int> checkWord2;
    vector<bool> result;

    for (const vector<string>& vectWords : anagrams)  // проходит по каждому вектору слов
    {
        string word1 = vectWords[0];
        string word2 = vectWords[1];

        for (int k = 0; k < word1.size(); k++)  // проходит по первому слову вектора
            checkWord1[word1[k]]++;

        for (int k = 0; k < word2.size(); k++)  // проходит по второму слову вектора
            checkWord2[word2[k]]++;

        if (checkWord1 == checkWord2)
        {
            result.push_back(true);
        }
        else result.push_back(false);

        checkWord1.clear();
        checkWord2.clear();
    }

    return result;
}


int main()
{
    int requestsNumber;
    cin >> requestsNumber;

    vector<vector<string>> anagrams(requestsNumber);

    for (vector<string>& vectWords : anagrams)  // заполнение вектора из вектора слов
    {
        for (int i = 0; i < 2; i++)  // каждый вектор vectWords имеет в себе 2 слова
        {
            string str;
            cin >> str;
            vectWords.push_back(str);
        }
    }  // на выходе имеем вектор из requestsNumber штук векторов, в каждом из которых по 2 слова


    vector<bool> result = BuildCharCounters(anagrams);

    for (auto item : result)
    {
        if (item == 1)
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}
