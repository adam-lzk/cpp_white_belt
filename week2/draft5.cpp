#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int a : v)
        cout << a << " " << endl;

    return 0;
}