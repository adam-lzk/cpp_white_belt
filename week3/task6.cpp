// Реверс и вывод строки
// компиляция - g++ -std=c++11 task6.cpp -o task6

#include <iostream>
#include <algorithm>

using namespace std;


class ReversibleString {
    public:
        ReversibleString(){};  // конструктор по умолчанию

        ReversibleString(const string& typedWord) {  // конструктор
            word = typedWord;
        }

        void Reverse() {
            reverse(word.begin(), word.end());
        }

        string ToString() const{
            return word;
        }

    private:
        string word;
};


int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
