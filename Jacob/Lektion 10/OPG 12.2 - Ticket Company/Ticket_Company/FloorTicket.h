#ifndef FLOORTICKET_H
#define FLOORTICKET_H

#include <BasicTicket.h>

class FloorTicket : public BasicTicket
{
public:
    FloorTicket();

    double getPrice() const { return BasicTicket::getPrice() * 1.3; };
};

#endif // FLOORTICKET_H
