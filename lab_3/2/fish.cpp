#include "fish.h"
#include "sstream"

using namespace std;

Fish::Fish() : Animal("fish") {}

string Fish::breath() {
    stringstream ss;

    ss << "gills";

    return ss.str();
}

string Fish::eat() {
    stringstream ss;

    ss << "plankton, algae, worms";

    return ss.str();
}

string Fish::swim(){
    stringstream ss;

    ss << "swims with the fins";

    return ss.str();
}