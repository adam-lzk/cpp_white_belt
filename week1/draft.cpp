#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;     // пустой вектор
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(10);
    for (int n : numbers)
        cout << n << "\t";      // 5       3       10

    cout << endl;
    return 0;
}