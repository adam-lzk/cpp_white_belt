// Создание структуры с explicit-полями (explicit - явно инициализированные, четко сформулированные)

#include <iostream>

using namespace std;


struct Specialization {
    string value;

    explicit Specialization(const string& newValue) {
        value = newValue;
    }
};


struct Course {
    string value;

    explicit Course(const string& newValue) {
        value = newValue;
    }
};


struct Week {
    string value;

    explicit Week(const string& newValue) {
        value = newValue;
    }
};


struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& newSpecialization, const Course& newCourse, const Week& newWeek) {
        specialization = newSpecialization.value;
        course = newCourse.value;
        week = newWeek.value;
    }
};


int main()
{
    // allowed
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    // forbidden
    /*
    LectureTitle title1("C++", "White belt", "4th");

    LectureTitle title2(string("C++"), string("White belt"), string("4th"));

    LectureTitle title3 = {"C++", "White belt", "4th"};

    LectureTitle title4 = {{"C++"}, {"White belt"}, {"4th"}};

    LectureTitle title5(
        Course("White belt"),
        Specialization("C++"),
        Week("4th")
    );

    LectureTitle title6(
        Specialization("C++"),
        Week("4th"),
        Course("White belt")
    );
    */

    return 0;
}
