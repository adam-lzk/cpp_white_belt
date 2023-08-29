#include <iostream>
#include <fstream>

using namespace std;

void ReadAll(const string& path)
{
    ifstream input(path);
    
    if (input.is_open())
    {
        string str;

        while (getline(input, str))
            cout << str << endl;

        cout << "done\n";
    }
    else cout << "error\n";
}

int main()
{
    const string path = "output.txt";

    ofstream output(path);
    output << "hello" << endl;  // удаление предыдущего содержимого файла и запись в него новой информации

    ReadAll(path);

    return 0;
}
