// task 3 (g++ -std=c++11 your_file.cpp -o your_program)

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> PalindromFilter (vector<string> words, int minLength)
{
    vector<string> filtredWords;

    for (string element : words)  // (int i = 0; i < words.size(); i++)
    {
        bool check = 0;

        if (element.size() >= minLength)
        {
            for (int i = 0; i <= element.size() / 2; i++)  // проверка строки element на палиндром (код из task2)
            {
                if (element[i] != element[(element.size() - 1) - i])  // если element НЕ палиндром
                {
                    check = 1;
                    break;
                }
            }

            if (check == 0)  // заполнение вектора строками-палиндромами длиной не менее minLength
                filtredWords.push_back(element);
        }
    }

    return filtredWords;
}


int main()
{
    int minLength;

    cout << "minLength = ";
    cin >> minLength;

    string str;
    vector<string> words;

    for (int i = 0; i < 3; i++)  // заполнение вектора words 3-мя словами
    {
        cout << "words " << i << " = ";
        cin >> str;
        words.push_back(str);
    }

    vector<string> filtredWords = PalindromFilter (words, minLength);

    for (string a : filtredWords)
        cout << a << " ";

    cout << endl;

    return 0;
}
