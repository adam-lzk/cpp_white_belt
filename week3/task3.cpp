// Создание и сорировка вектора слов в классе через методы
// компиляция - g++ -std=c++11 task3.cpp -o task3

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
    public:
        void AddString(const string& s) {  // добавить строку s в набор
            vectorStr.push_back(s);
        }
        vector<string> GetSortedStrings() {  // получить набор из всех добавленных строк в отсортированном порядке
            sort(begin(vectorStr), end(vectorStr));
            return vectorStr;
        }

    private:
        vector<string> vectorStr;
};

void PrintSortedStrings(SortedStrings& strings)
{
    for (const string& s : strings.GetSortedStrings())
        cout << s << " ";

    cout << endl;
}

int main()
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
