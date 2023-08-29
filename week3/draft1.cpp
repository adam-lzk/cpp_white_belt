// компиляция - g++ -std=c++11 draft1.cpp -o draft1

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void Print(const vector<int>& a)
{
    for (const auto& item : a)
        cout << item << " ";

    cout << endl;
}

int main()
{
    vector<int> a = {3, 1, 4, 5, 2, 6, 9, 8, 7, 10};

    sort(begin(a), end(a));

    Print(a);

    //sort(begin(a), end(a), comp);

    return 0;
}
