// Способы инициализации класса

#include <iostream>
#include <vector>

using namespace std;


class Incognizable {
    public:
        Incognizable() {}

        Incognizable(int n1) {
            numb1 = n1;
        }

        Incognizable(int n1, int n2) {
            numb1 = n1;
            numb2 = n2;
        }

    private :
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
