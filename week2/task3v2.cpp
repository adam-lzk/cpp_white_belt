// Вывод строк-палиндромов длиной не менее minLength (not my code)


#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool IsPalindrom(string s)  // определяет, является ли строка s палиндромом
{
    for (size_t i = 0; i < s.size() / 2; ++i)  // переберём все символы s[i] из первой половины строки
    {
        if (s[i] != s[s.size() - i - 1])
            return false;  // если они не совпадают, строка точно не палиндром
    }

    return true;
}


vector<string> PalindromFilter(vector<string> words, int min_length)
{
    vector<string> result;

    for (auto s : words)
    {
        if (s.size() >= min_length && IsPalindrom(s)) 
            result.push_back(s);
    }

    return result;
}
