// Хранение и нахождение имени и фамилии человека по состоянию на конец года year
// компиляция - g++ -std=c++11 task4.cpp -o task4

#include <iostream>
#include <map>

using namespace std;


class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {  // добавить факт изменения имени на first_name в год year
            yearAndFirstName[year] = first_name;
        }

        void ChangeLastName(int year, const string& last_name) {  // добавить факт изменения фамилии на last_name в год year
            yearAndLastName[year] = last_name;
        }

        string GetFullName(int year) {  // получить имя и фамилию по состоянию на конец года year
            string rightFirstName = " with unknown first name";
            string rightLastName = " with unknown last name";

            for (const auto& item : yearAndFirstName)
            {
                if (item.first <= year)
                {
                    rightFirstName = item.second;
                }
                else break;
            }

            for (const auto& item : yearAndLastName)
            {
                if (item.first <= year)
                {
                    rightLastName = item.second;
                }
                else break;
            }

            if (rightFirstName == " with unknown first name" && rightLastName == " with unknown last name")
                return "Incognito";

            if (rightFirstName == " with unknown first name")
                return rightLastName + " " + rightFirstName;

            if (rightLastName == " with unknown last name")
                return rightFirstName + " " + rightLastName;

            return rightFirstName + " " + rightLastName;
        }

    private:
        map<int, string> yearAndFirstName;
        map<int, string> yearAndLastName;
};


int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990})
        cout << person.GetFullName(year) << endl;

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970})
        cout << person.GetFullName(year) << endl;

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970})
        cout << person.GetFullName(year) << endl;

    return 0;
}
