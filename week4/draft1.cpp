// компиляция - g++ -std=c++11 draft1.cpp -o draft1

#include <iostream>

using namespace std;

struct Day {
    int value;

    explicit Day(int newValue) {
        value = newValue;
    }
};

struct Month {
    int value;

    explicit Month(int newValue) {
        value = newValue;
    }
};

struct Year {
    int value;

    explicit Year(int newValue) {
        value = newValue;
    }
};

struct Date {
    int day;
    int month;
    int year;

    Date(Day newDay, Month newMonth, Year newYear) {
        day = newDay.value;
        month = newMonth.value;
        year = newYear.value;
    }
};

void PrintDate(const Date& date)
{
    cout << date.day << "." << date.month << "." << date.year << endl;
}

int main()
{
    Date date = { Day{19}, Month{3}, Year{2022} }; // также компилируется с {{19}, {3}, {2022}}, но не компилируется с {19, 3, 2022} (благодаря explicit)

    PrintDate(date);

    return 0;
}
