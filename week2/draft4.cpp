#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> k(10);
    k[0] = 1;
    for (int i = 0; i < k.size(); i++)
        cout << k[i] << " ";

    cout << endl;

    k.resize(13);
    for (int i = 0; i < k.size(); i++)
        cout << k[i] << " ";

    cout << endl;

    k.resize(8);
    for (int i = 0; i < k.size(); i++)
        cout << k[i] << " ";

    cout << endl;



    vector<int> v = {1, 2, 3};

    cout << v.size() << endl;

    v[3] = 10;

    for (int i = 0; i < 4; i++)
        cout << v[i] << " ";

    cout << endl;

    cout << v.size() << endl;

    return 0;
}