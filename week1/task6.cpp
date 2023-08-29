// Вывод четных чисел от a до b включительно

#include <iostream>
using namespace std;

int main() {

    int a, b;
    do
    {
        cin >> a >> b;
    } while (a > b || a < 1 || b > 30000);

    if (a % 2 == 1)
        a++;  // делаю a четным
    
    for (int i = a; i <= b; i += 2)
        cout << i << ' ';

    cout << endl;

    return 0;
}
