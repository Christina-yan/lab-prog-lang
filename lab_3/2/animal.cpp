#include <sstream>
#include "animal.h"

using namespace std;

string Animal::to_string() {
    stringstream ss;
    
    ss << "{"
        << "\n\t"
        << "\"animal_type\": "
        << animal_type
        << "\n\t"
        << "\"breath\": " << this->breath()
        << "\n\t"
        << "\"eat\": " << this->eat();

    if (animal_type == "fish") {
        ss << "\n\t"
            << "\"swim\": " << this->swim()
            << "\n"
            << "}";
    }
    else if (animal_type == "bird") {
        ss << "\n\t"
            << "\"lay eggs\": " << this->lay_eggs()
            << "\n"
            << "}";
    }
    else if (animal_type == "flyingbird") {
        ss << "\n\t"
            << "\"lay eggs\": " << this->lay_eggs() 
            << "\n\t"
            << "\"fly\": " << this->fly()
            << "\n"
            << "}";
    }
    else {
        ss << "\n"
           << "}";
    }
    

    return ss.str();
}
string Animal::swim(){
    return "";
   }

string Animal::lay_eggs() {
    return "";
}

string Animal::fly() {
    return "";
}
