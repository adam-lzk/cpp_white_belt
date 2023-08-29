#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("text.txt");
    string str;

    if (input.is_open())  // проверка на то, существует (открыт) ли этот файл == if (input)
    {
        while (getline(input, str))
            cout << str << endl;

        cout << "done\n";
    }
    else cout << "error\n";

    return 0;
}
