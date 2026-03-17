#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Student.h"
#include "Teacher.h"
#include <locale>

using namespace std;

void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << students.size() << endl;
    for (const auto& student : students) {
        file << student.getFullName() << endl;
        const auto& scores = student.getScores();
        file << scores.size() << endl;
        for (int score : scores) {
            file << score << " ";
        }
        file << endl;
    }
    file.close();
}

void loadStudentsFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    students.clear();
    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; ++i) {
        string surname, name, patronymic;
        file >> surname >> name >> patronymic;

        int scoresCount;
        file >> scoresCount;
        vector<int> scores;
        for (int j = 0; j < scoresCount; ++j) {
            int score;
            file >> score;
            scores.push_back(score);
        }

        students.emplace_back(surname, name, patronymic, scores);
    }
    file.close();
}

void saveTeachersToFile(const vector<Teacher>& teachers, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << teachers.size() << endl;
    for (const auto& teacher : teachers) {
        file << teacher.getFullName() << endl;
        file << static_cast<int>(teacher.getPosition()) << endl;
        const auto& subjects = teacher.getSubjects();
        file << subjects.size() << endl;
        for (const auto& subject : subjects) {
            file << subject << endl;
        }
    }
    file.close();
}

void loadTeachersFromFile(vector<Teacher>& teachers, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    teachers.clear();
    int count;
    file >> count;
    file.ignore();

    for (int i = 0; i < count; ++i) {
        string surname, name, patronymic;
        file >> surname >> name >> patronymic;

        int posInt;
        file >> posInt;
        Position pos = static_cast<Position>(posInt);

        int subjectsCount;
        file >> subjectsCount;
        file.ignore();
        vector<string> subjects;
        for (int j = 0; j < subjectsCount; ++j) {
            string subject;
            getline(file, subject);
            subjects.push_back(subject);
        }

        teachers.emplace_back(surname, name, patronymic, pos, subjects);
    }
    file.close();
}

int main() {
    system("chcp 1251 > nul");

    vector<Student> students;
    vector<Teacher> teachers;


    students = {
        Student("Иванов", "Иван", "Иванович", {5, 4, 5, 4, 5}),
        Student("Петров", "Петр", "Петрович", {3, 3, 4, 3, 2}),
        Student("Сидоров", "Сидор", "Сидорович", {5, 5, 5, 5, 5}),
        Student("Смирнов", "Алексей", "Алексеевич", {2, 2, 3, 2, 2}),
        Student("Кузнецов", "Дмитрий", "Дмитриевич", {4, 4, 4, 5, 4}),
        Student("Попов", "Андрей", "Андреевич", {3, 3, 3, 4, 3}),
        Student("Васильев", "Сергей", "Сергеевич", {5, 4, 4, 5, 5}),
        Student("Михайлов", "Михаил", "Михайлович", {2, 3, 2, 2, 3}),
        Student("Федоров", "Федор", "Федорович", {4, 5, 4, 4, 5}),
        Student("Алексеев", "Александр", "Александрович", {3, 4, 3, 4, 3})
    };

    teachers = {
        Teacher("Соколов", "Павел", "Павлович", Position::Professor, {"ОС", "Языки программирования", "Информатика"}),
        Teacher("Морозов", "Игорь", "Игоревич", Position::Docent, {"Математика", "Физика"}),
        Teacher("Волков", "Николай", "Николаевич", Position::Assistant, {"Информатика", "Программирование"}),
        Teacher("Зайцев", "Константин", "Константинович", Position::SeniorLecturer, {"История", "Философия"}),
        Teacher("Павлов", "Артем", "Артемович", Position::Professor, {"Базы данных", "Информатика", "Сети"}),
        Teacher("Семенов", "Виктор", "Викторович", Position::Docent, {"Физика", "Математика"}),
        Teacher("Егоров", "Денис", "Денисович", Position::Assistant, {"Программирование"}),
        Teacher("Козлов", "Роман", "Романович", Position::SeniorLecturer, {"Английский язык", "Немецкий язык"}),
        Teacher("Степанов", "Олег", "Олегович", Position::Professor, {"Информатика", "Искусственный интеллект"}),
        Teacher("Андреев", "Антон", "Антонович", Position::Docent, {"Математика", "Информатика"})
    };

    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");

    cout << "Данные сохранены в файлы." << endl;

    
    vector<Student> loadedStudents;
    vector<Teacher> loadedTeachers;

    loadStudentsFromFile(loadedStudents, "students.txt");
    loadTeachersFromFile(loadedTeachers, "teachers.txt");

    cout << "\nДанные загружены из файлов." << endl;

    
    cout << "\n1) Студенты со средним баллом > 4:" << endl;
    for (const auto& student : loadedStudents) {
        if (student.getAverageScore() > 4.0) {
            cout << "   " << student.getShortStudentInfo() << endl;
        }
    }

    
    cout << "\n2) Студенты со средним баллом < 3:" << endl;
    for (const auto& student : loadedStudents) {
        if (student.getAverageScore() < 3.0) {
            cout << "   " << student.getShortStudentInfo() << endl;
        }
    }

    
    cout << "\n3) Студент с наибольшим количеством оценок:" << endl;
    if (!loadedStudents.empty()) {
        auto maxScoresStudent = max_element(loadedStudents.begin(), loadedStudents.end(),
            [](const Student& a, const Student& b) {
                return a.getScoresCount() < b.getScoresCount();
            });
        cout << "   " << maxScoresStudent->getFullStudentInfo() << endl;
    }

    
    cout << "\n4) Все доценты:" << endl;
    for (const auto& teacher : loadedTeachers) {
        if (teacher.getPosition() == Position::Docent) {
            cout << "   " << teacher.getShortTeacherInfo() << endl;
        }
    }

    
    cout << "\n5) Профессор с наибольшим количеством предметов:" << endl;
    if (!loadedTeachers.empty()) {
        auto maxSubjectsProfessor = max_element(loadedTeachers.begin(), loadedTeachers.end(),
            [](const Teacher& a, const Teacher& b) {
                if (a.getPosition() != Position::Professor) return true;
                if (b.getPosition() != Position::Professor) return false;
                return a.getSubjectsCount() < b.getSubjectsCount();
            });

        if (maxSubjectsProfessor->getPosition() == Position::Professor) {
            cout << "   " << maxSubjectsProfessor->getFullTeacherInfo() << endl;
        }
    }

    
    cout << "\n6) Преподаватели, ведущие информатику:" << endl;
    for (const auto& teacher : loadedTeachers) {
        const auto& subjects = teacher.getSubjects();
        if (find(subjects.begin(), subjects.end(), "Информатика") != subjects.end()) {
            cout << "   " << teacher.getFullTeacherInfo() << endl;
        }
    }

    return 0;
}