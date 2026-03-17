#include "Human.h"
#include <sstream>

using namespace std;

Human::Human() : surname("unknown"), name("unknown"), patronymic("unknown") {}

Human::Human(string surname, string name, string patronymic)
    : surname(surname), name(name), patronymic(patronymic) {
}

string Human::getSurnameAndInitials() const {
    stringstream ss;
    ss << surname << " ";
    if (!name.empty() && name != "unknown") {
        ss << name[0] << ".";
    }
    if (!patronymic.empty() && patronymic != "unknown") {
        ss << patronymic[0] << ".";
    }
    return ss.str();
}

string Human::getFullName() const {
    stringstream ss;
    ss << surname << " " << name << " " << patronymic;
    return ss.str();
}