// Способы инициализации структуры (не компилируется)

#include <iostream>
#include <vector>

using namespace std;

struct Incognizable {
    int numb1 = 0;
    int numb2 = 0;
};

int main()
{
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
