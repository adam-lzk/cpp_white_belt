#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("date.txt");

    int year;
    int month;
    int day;

    if (input.is_open())
    {
        input >> year;
        input.ignore(1);  // проигнорировать один символ
        input >> month;
        input.ignore(1);
        input >> day;
        input.ignore(1);

        cout << year << '.' << month << '.' << day << endl;
    }
    else cout << "error\n";

    return 0;
}
