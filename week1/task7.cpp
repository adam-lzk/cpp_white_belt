// Нахождение в строке второе вхождение буквы f

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int count = 0;

    for (int i = 0; i < str.size() ; i++)  // str.size() - длина строки str (кол-во символов)
    {
        if (str[i] == 'f')
            count++;

        if (count == 2)
        {
            cout << i << endl;
            break;
        }
    }

    if (count == 1)
        cout << -1 << endl;

    if (count == 0)
        cout << -2 << endl;

    return 0;
}
