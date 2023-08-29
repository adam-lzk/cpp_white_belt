// Проверка строки на палиндром

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom (string str)
{
    bool check = 1;

    for (int i = 0; i <= int(str.size()) / 2; i++)  // str.size - кол-во элементов в str
    {                                              // str[str.size() - 1] - последний элемент str
        if(str[i] != str[(str.size() - 1) - i])   // если str НЕ палиндром, то зайдет в if
        {
            check = 0;
            break;
        }
    }

    return check;
}

int main()
{
    string word;
    cin >> word;

    cout << IsPalindrom(word) << endl;

    return 0;
}
