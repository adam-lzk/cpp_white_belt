// Перевод чисел из 10-чной в 2-чную систему счисления

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numb;
    cin >> numb;

    int maxBit;

    for (int i = 0; i < 64 ; i++)
    {
        if (numb >= pow(2,i) && numb < pow(2,(i+1)))  // введенное число находится в промежутке между 2^i и 2^(i+1)
        {
            maxBit = i;  // порядковый номер максимального бита числа
            break;
        }
    }

    for (int k = maxBit; k >= 0; k--)
    {
        if (numb > pow(2,k))
        {
            cout << 1;
            numb -= pow(2,k);
        }
        else if (numb < pow(2,k))
            {
                cout << 0;
            }
            else if (numb == pow(2,k))
                {
                    cout << 1;
                    for (int n = k; n > 0; n--)
                        cout << 0;
                    break;
                }
    }

    cout << endl;

    return 0;
}
