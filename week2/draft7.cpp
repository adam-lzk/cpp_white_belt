// vector - the last task

#include <iostream>
#include <vector>

using namespace std;


void AddTask(vector<vector<string>>& tasksForDays, int dayNumber, string task)
{
    tasksForDays[dayNumber].push_back(task);
}


void PrintTasks(const vector<vector<string>>& tasksForDays, int dayNumber)
{
    for (const auto& task : tasksForDays[dayNumber])
        cout << task << " ";
}


void NextMonth()
{
}


int main()
{
    int requestsNumber;
    cin >> requestsNumber;

    string request;
    cin >> request;

    vector<vector<string>> jan(32);
    vector<vector<string>> feb(29);
    vector<vector<string>> mar(32);
    vector<vector<string>> apr(31);
    vector<vector<string>> may(32);
    vector<vector<string>> jun(31);
    vector<vector<string>> jul(32);
    vector<vector<string>> aug(32);
    vector<vector<string>> sep(31);
    vector<vector<string>> oct(32);
    vector<vector<string>> nov(31);
    vector<vector<string>> dec(32);

    vector<vector<string>> tasksForDays;

    for (int i = 0; i < requestsNumber; i++)
    {
        if (request == "ADD")
        {
            int dayNumber;
            cin >> dayNumber;

            string task;
            cin >> task;

            AddTask(tasksForDays, dayNumber, task);
        }


        if (request == "DUMP")
        {
            int dayNumber;
            cin >> dayNumber;

            PrintTasks(tasksForDays, dayNumber);
        }


        if (request == "NEXT")
        {
        }
    }

    return 0;
}
