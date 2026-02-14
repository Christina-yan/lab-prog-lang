#include <iostream>
#include "time.h"
#include <fstream>
#include <iomanip>

using namespace std;

vector<Ticket> Ticket::LoadTicket(const string& filename) {
    vector<Ticket> tickets;
    ifstream file(filename);

    if (!file.is_open()){
        cout << "Error. File is not open.";
        return tickets;
    }
    Ticket temp; 
    while (file >> temp.destination >> temp.flight_number >> temp.price >> temp.gate_number) {
        tickets.push_back(temp);
    }
    file.close();
    return tickets;
}
// сортировка по методу пузырька (убывание)
void Ticket::SortByPrice(vector<Ticket>& tickets) {
    int ts = tickets.size();
    for (int i = 0; i < ts - 1; i++) {
        for (int j = 0; j < ts - i - 1; j++) {
            if (tickets[j].price < tickets[j + 1].price) {
                swap(tickets[j], tickets[j + 1]);
            }
        }
    }
    cout << "Sorted by price descending" << endl;
}
//сортировка по методу пузырька (возрастание)
void Ticket::SortByDestination(vector<Ticket>& tickets) {
    int ts = tickets.size();
    for (int i = 0; i < ts - 1; i++) {
        for (int j = 0; j < ts - i - 1; j++) {
            if (tickets[j].destination > tickets[j + 1].destination) {
                swap(tickets[j], tickets[j + 1]);
            }
        }
    }
    cout << "Sorted by destination ascending" << endl;
}

void Ticket::Print(const vector<Ticket>& tickets) {
    cout << "-------------------------------------------" << endl;
    cout << left << setw(15) << "Dectination"
        << setw(10) << "Flight"
        << setw(10) << "Price"
        << setw(5) << "Gate" << endl;
    cout << "-------------------------------------------" << endl;
    for (const auto& t : tickets) {
        cout << left << setw(15) << t.destination
            << setw(10) << t.flight_number
            << setw(10) << fixed << setprecision(2) << t.price
            << setw(5) << t.gate_number << endl;
    }
    cout << "-------------------------------------------" << endl << endl;
}

