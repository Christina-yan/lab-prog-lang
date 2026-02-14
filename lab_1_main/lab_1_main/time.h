#ifndef TIME_H
#define TIME_H

#include <vector>
using namespace std;

struct Ticket {

    string destination;
    int flight_number = 0;
    double price = 0.0;
    char gate_number = ' ';

    vector<Ticket> LoadTicket(const string& filename);
    void SortByPrice(vector<Ticket>& tickets);
    void SortByDestination(vector<Ticket>& tickets);
    void Print(const vector<Ticket>& tickets);
};

#endif
