#include "FlyingBird.h"
#include "sstream"

using namespace std;

FlyingBird::FlyingBird() {
    animal_type = "flyingbird";  
}

//string FlyingBird::breath() {
//    stringstream ss;
//
//    ss << "double breathing through the nose";
//
//    return ss.str();
//}
//
//string FlyingBird::eat() {
//    stringstream ss;
//
//    ss << "worms, grains, small rodents";
//
//    return ss.str();
//}

string FlyingBird::fly() {
    stringstream ss;

    ss << "fly with wings";

    return ss.str();
}