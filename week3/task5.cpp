// Хранение и нахождение имени, фамилии и истории имён и фамилий человека по состоянию на конец года year
// компиляция - g++ -std=c++11 task5.cpp -o task5

#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {  // добавить факт изменения имени на first_name в год year
            yearAndFirstName[year] = first_name;
        }


        void ChangeLastName(int year, const string& last_name) {  // добавить факт изменения фамилии на last_name в год year
            yearAndLastName[year] = last_name;
        }


        string GetFullName(int year) {  // получить имя и фамилию по состоянию на конец года year (реализовано в task4.cpp)
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


        string GetFullNameWithHistory(int year) {  // получить имя, фамилию и историю имен и фамилий по состоянию на конец года year
            vector<string> firstNamesUntilThisYear;
            vector<string> lastNamesUntilThisYear;
            vector<string> necessaryFirstNames;
            vector<string> necessaryLastNames;
            string firstNameWithHistory;
            string lastNameWithHistory;

            // first names
            for (const auto& item : yearAndFirstName)  // создание вектора из всех имен до этого года
            {
                if (item.first <= year)
                {
                    firstNamesUntilThisYear.push_back(item.second);
                }
                else break;
            }

            if (firstNamesUntilThisYear.size() > 0)  // sorting
            {
                necessaryFirstNames.push_back(firstNamesUntilThisYear[0]);
                for (int i = 0; i < firstNamesUntilThisYear.size() - 1; i++)
                {
                    if (firstNamesUntilThisYear[i] != firstNamesUntilThisYear[i+1])
                    {
                        necessaryFirstNames.push_back(firstNamesUntilThisYear[i+1]);
                    }
                }
            }


            // last names
            for (const auto& item : yearAndLastName)  // создание вектора из всех фамилий до этого года
            {
                if (item.first <= year)
                {
                    lastNamesUntilThisYear.push_back(item.second);
                }
                else break;
            }

            if (lastNamesUntilThisYear.size() > 0)  // sorting
            {
                necessaryLastNames.push_back(lastNamesUntilThisYear[0]);
                for (int i = 0; i < lastNamesUntilThisYear.size() - 1; i++)
                {
                    if (lastNamesUntilThisYear[i] != lastNamesUntilThisYear[i+1])
                    {
                        necessaryLastNames.push_back(lastNamesUntilThisYear[i+1]);
                    }
                }
            }


            // connection
            if (necessaryFirstNames.size() == 1)
            {
                firstNameWithHistory = necessaryFirstNames[0];
            }
            else if (necessaryFirstNames.size() > 1)
            {
                firstNameWithHistory = necessaryFirstNames[necessaryFirstNames.size() - 1] + " (";

                for (int i = necessaryFirstNames.size() - 2; i > 0; i--)
                {
                    firstNameWithHistory += necessaryFirstNames[i] + ", ";
                }
                firstNameWithHistory += necessaryFirstNames[0] + ")";
            }

            if (necessaryLastNames.size() == 1)
            {
                lastNameWithHistory = necessaryLastNames[0];
            }
            else if (necessaryLastNames.size() > 1)
            {
                lastNameWithHistory = necessaryLastNames[necessaryLastNames.size() - 1] + " (";

                for (int i = necessaryLastNames.size() - 2; i > 0; i--)
                {
                    lastNameWithHistory += necessaryLastNames[i] + ", ";
                }
                lastNameWithHistory += necessaryLastNames[0] + ")";
            }


            // return
            if (necessaryFirstNames.empty() && necessaryLastNames.empty())
                return "Incognito";

            if (necessaryFirstNames.empty())
                return lastNameWithHistory + " with unknown first name";

            if (necessaryLastNames.empty())
                return firstNameWithHistory + " with unknown last name";

            return firstNameWithHistory + " " + lastNameWithHistory;
        }


    private:
        map<int, string> yearAndFirstName;
        map<int, string> yearAndLastName;
};


int main()
{
    Person person1;

    cout << "  person 1\n";
    person1.ChangeFirstName(1900, "Eugene");
    person1.ChangeLastName(1900, "Sokolov");
    person1.ChangeLastName(1910, "Sokolov");
    person1.ChangeFirstName(1920, "Evgeny");
    person1.ChangeLastName(1930, "Sokolov");
    cout << person1.GetFullNameWithHistory(1940) << endl << endl;


    Person person;

    cout << "  person 2\n";
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
