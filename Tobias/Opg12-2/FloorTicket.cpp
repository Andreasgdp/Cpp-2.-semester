#include "FloorTicket.h"

FloorTicket::FloorTicket()
{

}

FloorTicket::FloorTicket(int seat, int ticketNo, std::string city, std::string opera)
{
    _seat = seat;
    _ticketNo = ticketNo;
    _city = city;
    _opera = opera;
}

double FloorTicket::price() const
{
    return (BasicTicket::price() * 1.3);
}
