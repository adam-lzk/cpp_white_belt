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

    ofstream output(path, ios::app);  // ios::app для записи в конец файла, без удаления предыдущей информации (append)
    output << " world!" << endl;

    ReadAll(path);

    return 0;
}
