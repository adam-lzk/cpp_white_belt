#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("text.txt");
    string str;

    while (getline(input, str))  // вывод всех строк файла
        cout << str << endl;

    return 0;
}
