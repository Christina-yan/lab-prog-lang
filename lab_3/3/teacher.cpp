#include "Teacher.h"
#include <sstream>
#include <algorithm>

using namespace std;

Teacher::Teacher() : Human(), position(Position::Unknown), subjects() {}

Teacher::Teacher(string surname, string name, string patronymic, Position position, vector<string> subjects)
    : Human(surname, name, patronymic), position(position), subjects(subjects) {
}

void Teacher::addSubject(string subject) {
    subjects.push_back(subject);
}

string Teacher::positionToString(Position pos) {
    switch (pos) {
    case Position::Assistant: return "ассистент";
    case Position::SeniorLecturer: return "старший преподаватель";
    case Position::Docent: return "доцент";
    case Position::Professor: return "профессор";
    default: return "Неизвестно";
    }
}

string Teacher::getShortTeacherInfo() const {
    stringstream ss;
    ss << getSurnameAndInitials() << " " << positionToString(position) << ": " << subjects.size();
    return ss.str();
}

string Teacher::getFullTeacherInfo() const {
    stringstream ss;
    ss << getFullName() << " " << positionToString(position) << ": ";

    for (size_t i = 0; i < subjects.size(); ++i) {
        ss << subjects[i];
        if (i < subjects.size() - 1) ss << ", ";
    }

    return ss.str();
}