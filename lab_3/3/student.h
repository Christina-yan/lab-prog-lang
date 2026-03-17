#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Human.h"

using namespace std;

class Student : public Human {
private:
    vector<int> scores;

public:
    
    Student();
    Student(string surname, string name, string patronymic, vector<int> scores);

    ~Student() override = default;

    
    void addScore(int score);
    double getAverageScore() const;
    string getShortStudentInfo() const;
    string getFullStudentInfo() const;

    
    const vector<int>& getScores() const { return scores; }
    int getScoresCount() const { return scores.size(); }
};

#endif