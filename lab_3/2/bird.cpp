#include "bird.h"
#include "sstream"

using namespace std;

Bird::Bird() : Animal("bird") {}

string Bird::breath() {
    stringstream ss;

    ss << "double breathing through the nose";

    return ss.str();
}

string Bird::eat() {
    stringstream ss;

    ss << "worms, grains, small rodents";

    return ss.str();
}

string Bird::lay_eggs() {
    stringstream ss;

    ss << "lay eggs for reproduce";

    return ss.str();
}

string Bird::fly() {
    return "";
}