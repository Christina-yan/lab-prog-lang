// Дабагян Кристина ФИТ-251
// Лаб. 1 ЯП
//описание авиабилетов
#include <iostream>
#include "time.h"
#include <iostream>

using namespace std;


int main()
{
    Ticket t;
    string filename = "tickets.txt";
    vector<Ticket> ticket_list = t.LoadTicket(filename);

    cout << "Initial data" << endl;
    t.Print(ticket_list);

    t.SortByPrice(ticket_list);
    t.Print(ticket_list);

    t.SortByDestination(ticket_list);
    t.Print(ticket_list);

    return 0;
}
