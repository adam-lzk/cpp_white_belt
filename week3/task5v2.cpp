// Хранение и нахождение имени, фамилии и истории имён и фамилий человека по состоянию на конец года year
// код короче, написан с использованием функций
// компиляция - g++ -std=c++11 task5v2.cpp -o task5v2

#include <iostream>
#include <map>
#include <vector>

using namespace std;


vector<string> CreateVectorOfNecessaryNamesUntilThisYear(const map<int, string>& yearAndName, int year)
{
    vector<string> allNamesUntilThisYear;
    vector<string> necessaryNames;

    for (const auto& item : yearAndName)  // создание вектора из всех имен/фамилий до этого года
    {
        if (item.first <= year)
        {
            allNamesUntilThisYear.push_back(item.second);
        }
        else break;
    }

    if (allNamesUntilThisYear.size() > 0)  // создание вектора из необходимых (не повторяющихся подряд) имен/фамилий до этого года
    {
        necessaryNames.push_back(allNamesUntilThisYear[0]);
        for (int i = 0; i < allNamesUntilThisYear.size() - 1; i++)
        {
            if (allNamesUntilThisYear[i] != allNamesUntilThisYear[i+1])
            {
                necessaryNames.push_back(allNamesUntilThisYear[i+1]);
            }
        }
    }

    return necessaryNames;
}


string CreateHistoryOfNames(const vector<string>& necessaryNames)
{
    string nameWithHistory;

    if (necessaryNames.size() == 1)
    {
        nameWithHistory = necessaryNames[0];
    }
    else if (necessaryNames.size() > 1)
    {
        nameWithHistory = necessaryNames[necessaryNames.size() - 1] + " (";

        for (int i = necessaryNames.size() - 2; i > 0; i--)
        {
            nameWithHistory += necessaryNames[i] + ", ";
        }
        nameWithHistory += necessaryNames[0] + ")";
    }

    return nameWithHistory;
}


class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {  // добавить факт изменения имени на first_name в год year
            yearsAndFirstNames[year] = first_name;
        }


        void ChangeLastName(int year, const string& last_name) {  // добавить факт изменения фамилии на last_name в год year
            yearsAndLastNames[year] = last_name;
        }


        string GetFullName(int year) {  // получить имя и фамилию по состоянию на конец года year (реализовано в task4.cpp)
            string rightFirstName = " with unknown first name";
            string rightLastName = " with unknown last name";

            for (const auto& item : yearsAndFirstNames)
            {
                if (item.first <= year)
                {
                    rightFirstName = item.second;
                }
                else break;
            }

            for (const auto& item : yearsAndLastNames)
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
            vector<string> necessaryFirstNames = CreateVectorOfNecessaryNamesUntilThisYear(yearsAndFirstNames, year);
            vector<string> necessaryLastNames = CreateVectorOfNecessaryNamesUntilThisYear(yearsAndLastNames, year);

            // connection
            string firstNameWithHistory = CreateHistoryOfNames(necessaryFirstNames);
            string lastNameWithHistory = CreateHistoryOfNames(necessaryLastNames);

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
        map<int, string> yearsAndFirstNames;
        map<int, string> yearsAndLastNames;
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
