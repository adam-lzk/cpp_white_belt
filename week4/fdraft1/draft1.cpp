#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("text.txt");  // объект типа ifstream, название input, аргумент - путь к читаемому файлу
    string str;

    getline(input, str);  // прочитать из input, записать в str
    cout << str << endl;  // данные в строке файла читаются до переноса строки

    getline(input, str);
    cout << str << endl;

    getline(input, str);
    cout << str << endl;

    return 0;
}
