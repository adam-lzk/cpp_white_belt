#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str = "aBc";
    for (char& ch : str)
        ch = tolower(ch);

    cout << str;
    return 0;
}
