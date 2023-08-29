// Вывод количества и индексов дней, когда температура была выше средней
// компиляция - (g++ -std=c++11 task8.cpp -o task8)

#include <iostream>
#include <vector>

using namespace std;


void MoreThanAverageTemp(const vector<int>& temp)  // передача по константной ссылке
{
    int averageTemp = 0;

    for (int a : temp)
        averageTemp += a;  // сумма темератур

    averageTemp /= temp.size();

    int count = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] > averageTemp)
            count++;
    }
    cout << count << endl;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] > averageTemp)
            cout << i << " ";
    }

    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    vector<int> temp(n);

    for (int& a : temp)
        cin >> a;

    MoreThanAverageTemp(temp);

    return 0;
}
