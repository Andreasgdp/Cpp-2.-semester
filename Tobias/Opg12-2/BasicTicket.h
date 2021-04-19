#ifndef BASICTICKET_H
#define BASICTICKET_H
#include <string>


class BasicTicket
{
public:
    BasicTicket();
    BasicTicket(int seat, int ticketNo, std::string city,std::string opera);
    int seat() const;
    void setSeat(int seat);

    int ticketNo() const;
    void setTicketNo(int ticketNo);

    std::string city() const;
    void setCity(const std::string &city);

    std::string opera() const;
    void setOpera(const std::string &opera);

    virtual double price() const;
    void setPrice(double price);

protected:
    int _seat, _ticketNo;
    std::string _city, _opera;
    double _price = 10;
};

#endif // BASICTICKET_H
