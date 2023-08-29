// Хранение и нахождение имени, фамилии и истории имён и фамилий человека по состоянию на конец года year, где первый введенный год - год рождения человека
// используются конструкторы и константность методов
// компиляция - g++ -std=c++11 task7.cpp -o task7

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
        Person(const string& firstName, const string& lastName, int year) {  // конструктор
            if (changeNameCounter == 0)
                yearOfBirth = year;  // первый объявленный год - год рождения

            ChangeFirstName(year, firstName);
            ChangeLastName(year, lastName);

            changeNameCounter++;
        }


        void ChangeFirstName(int year, const string& first_name) {  // добавить факт изменения имени на first_name в год year
            if (year >= yearOfBirth)
                yearsAndFirstNames[year] = first_name;
        }


        void ChangeLastName(int year, const string& last_name) {  // добавить факт изменения фамилии на last_name в год year
            if (year >= yearOfBirth)
                yearsAndLastNames[year] = last_name;
        }


        string GetFullName(int year) const {  // получить имя и фамилию по состоянию на конец года year (реализовано в task4.cpp)
            if (year < yearOfBirth)
                return "No person";

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


        string GetFullNameWithHistory(int year) const {  // получить имя, фамилию и историю имен и фамилий по состоянию на конец года year
            if (year < yearOfBirth)
                return "No person";

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
        int changeNameCounter = 0;
        int yearOfBirth;
};


int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960})
        cout << person.GetFullNameWithHistory(year) << endl;

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967})
        cout << person.GetFullNameWithHistory(year) << endl;

    return 0;
}
