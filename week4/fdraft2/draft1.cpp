#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("date.txt");

    string year;
    string month;
    string day;

    if (input.is_open())
    {
        getline(input, year, '-');  // будет читать до знака '-'
        getline(input, month, '-');
        getline(input, day);

        cout << year << '.' << month << '.' << day << endl;
    }
    else cout << "error\n";

    return 0;
}
