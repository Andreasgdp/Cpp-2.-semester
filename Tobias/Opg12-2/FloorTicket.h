#ifndef FLOORTICKET_H
#define FLOORTICKET_H
#include "BasicTicket.h"


class FloorTicket: public BasicTicket
{
public:
    FloorTicket();
    FloorTicket(int seat, int ticketNo, std::string city,std::string opera);
    double price() const override;
};

#endif // FLOORTICKET_H
