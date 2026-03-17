#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Human.h"

using namespace std;

enum class Position {
    Unknown,
    Assistant,
    SeniorLecturer,
    Docent,
    Professor
};

class Teacher : public Human {
private:
    Position position;
    vector<string> subjects;

public:
    
    Teacher();
    Teacher(string surname, string name, string patronymic, Position position, vector<string> subjects);

    ~Teacher() override = default;

    
    void addSubject(string subject);
    string getShortTeacherInfo() const;
    string getFullTeacherInfo() const;

    
    Position getPosition() const { return position; }
    const vector<string>& getSubjects() const { return subjects; }
    int getSubjectsCount() const { return subjects.size(); }

    
    static string positionToString(Position pos);
};

#endif