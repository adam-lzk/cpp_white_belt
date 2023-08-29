// Подсчёт количества волнующихся людей в очереди
// компиляция - (g++ -std=c++11 task9.cpp -o task9)

/*
Количество операций Q
WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
*/

#include <iostream>
#include <vector>

using namespace std;


void COME(vector<bool>& peopleInQueue, const int& comingPeople)
{
    peopleInQueue.resize(peopleInQueue.size() + comingPeople);
}


void WORRY(vector<bool>& peopleInQueue, const int& worriedPersonIndex)
{
    for (int i = 0; i < peopleInQueue.size(); i++)
    {
        if (i == worriedPersonIndex)
            peopleInQueue[i] = 1;
    }
}


void QUIET(vector<bool>& peopleInQueue, const int& quietPersonIndex)
{
    for (int i = 0; i < peopleInQueue.size(); i++)
    {
        if (i == quietPersonIndex)
            peopleInQueue[i] = 0;
    }
}


void WORRY_COUNT(const vector<bool>& peopleInQueue, int& numberOfWorriedPeople)
{
    for (auto a : peopleInQueue)
    {
        if (a == 1)
            numberOfWorriedPeople++;
    }
}


int main()
{
    int operationsNumber;
    cin >> operationsNumber;

    vector<bool> peopleInQueue;

    for (int i = 0; i < operationsNumber; i++)
    {
        string str;
        cin >> str;


        if (str == "COME")
        {
            int comingPeople;
            cin >> comingPeople;

            COME(peopleInQueue, comingPeople);

            continue;
        }


        if (str == "WORRY")
        {
            unsigned int worriedPersonIndex;
            cin >> worriedPersonIndex;

            WORRY(peopleInQueue, worriedPersonIndex);

            continue;
        }


        if (str == "QUIET")
        {
            unsigned int quietPersonIndex;
            cin >> quietPersonIndex;

            QUIET(peopleInQueue, quietPersonIndex);

            continue;
        }


        if (str == "WORRY_COUNT")
        {
            int numberOfWorriedPeople = 0;

            WORRY_COUNT(peopleInQueue, numberOfWorriedPeople);

            cout << numberOfWorriedPeople << endl;

            continue;
        }
    }

    return 0;
}
