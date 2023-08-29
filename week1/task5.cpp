// Нахождение цены товара с учетом скидки

#include <iostream>
using namespace std;

int main()
{
    double productPrice, price1, price2, discont1, discont2;
    cin >> productPrice >> price1 >> price2 >> discont1 >> discont2;  // price1 < price2, discont1 <= 100, discont2 <= 100

    if (productPrice > price2)
        productPrice -= productPrice * (discont2 / 100);
    else if (productPrice > price1)
        productPrice -= productPrice * (discont1 / 100);

    cout << productPrice << endl;

    return 0;
}
