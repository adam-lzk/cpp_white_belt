#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> str(n);

    for (auto& word : str)
        cin >> word;

    for (string& word : str)
    {
        for (char& chr : word)
        {
            chr = tolower(chr);
        }
    }

    for (const string& word : str)
        cout << word << " ";
    
    cout << endl;

    return 0;
}
