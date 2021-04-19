#include <iostream>
#include "BasicTicket.h"
#include "FloorTicket.h"

using namespace std;

int main()
{
    BasicTicket ticket(1, 1, "Odense", "Tryllefløjten");
    std::cout << ticket.price() << std::endl;

    FloorTicket fTicket(3, 3,"Odense", "Tryllefløjten");
    std::cout << fTicket.price() << std::endl;
}
