#include "Student.h"
#include <sstream>
#include <numeric>
#include <iomanip>

using namespace std;

Student::Student() : Human(), scores() {}

Student::Student(string surname, string name, string patronymic, vector<int> scores)
    : Human(surname, name, patronymic), scores(scores) {
}

void Student::addScore(int score) {
    scores.push_back(score);
}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;

    double sum = accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

string Student::getShortStudentInfo() const {
    stringstream ss;
    ss << getSurnameAndInitials() << ": " << fixed << setprecision(2) << getAverageScore();
    return ss.str();
}

string Student::getFullStudentInfo() const {
    stringstream ss;
    ss << getFullName() << ": ";

    for (size_t i = 0; i < scores.size(); ++i) {
        ss << scores[i];
        if (i < scores.size() - 1) ss << " ";
    }

    ss << " – " << fixed << setprecision(2) << getAverageScore();
    return ss.str();
}