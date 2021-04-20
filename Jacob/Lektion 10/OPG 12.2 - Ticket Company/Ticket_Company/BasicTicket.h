#ifndef BASICTICKET_H
#define BASICTICKET_H

#include <string>

class BasicTicket
{
public:
    BasicTicket();

    void setSeat(const int seat) { _seat = seat; };
    void setTicketno(const int ticketno) { _ticketno = ticketno; };
    void setCity(const std::string city) { _city = city; };
    void setOpera(const std::string opera) { _opera = opera; };
    void setPrice(const double price) { _price = price; };

    int getSeat() const { return _seat; };
    int getTicketno() const { return _ticketno; };
    std::string getCity() const { return _city; };
    std::string getOpera() const { return _opera; };
    virtual double getPrice() const { return _price; };


private:
    int _seat;
    int _ticketno;
    std::string _city;
    std::string _opera;
    double _price;

};

#endif // BASICTICKET_H
