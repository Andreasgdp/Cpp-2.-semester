#include "BasicTicket.h"

BasicTicket::BasicTicket()
{

}

BasicTicket::BasicTicket(int seat, int ticketNo, std::string city, std::string opera)
{
    _seat = seat;
    _ticketNo = ticketNo;
    _city = city;
    _opera = opera;
}

int BasicTicket::seat() const
{
    return _seat;
}

void BasicTicket::setSeat(int seat)
{
    _seat = seat;
}

int BasicTicket::ticketNo() const
{
    return _ticketNo;
}

void BasicTicket::setTicketNo(int ticketNo)
{
    _ticketNo = ticketNo;
}

std::string BasicTicket::city() const
{
    return _city;
}

void BasicTicket::setCity(const std::string &city)
{
    _city = city;
}

std::string BasicTicket::opera() const
{
    return _opera;
}

void BasicTicket::setOpera(const std::string &opera)
{
    _opera = opera;
}

double BasicTicket::price() const
{
    return _price;
}

void BasicTicket::setPrice(double price)
{
    _price = price;
}
