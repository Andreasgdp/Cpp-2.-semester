#ifndef TICKET_H
#define TICKET_H


class Ticket
{
public:
    Ticket();

    Ticket(const Ticket& p); // Copy constructor
    Ticket(Ticket&& p); // Move constructor

    ~Ticket();

    Ticket& operator=(const Ticket &rhs); // Copy assignment
    Ticket& operator=(Ticket &&rhs);    // Move assignment

    int getTheater() const;
    void setTheater(int theater);

    int getTicketNo() const;
    void setTicketNo(int ticketNo);

    double getPrice() const;
    void setPrice(double price);

    const char *getDate() const;
    void setDate(const char *date);

    const char *getTime() const;
    void setTime(const char *time);

    const char *getSeat() const;
    void setSeat(const char *seat);

    const char *getMovie() const;
    void setMovie(const char *movie);

    bool get3D() const;
    void set3D(bool value);

private:
    int mTheater;
    int mTicketNo;
    double mPrice;
    char mDate[11];
    char mTime[6];
    char* mSeat;
    char* mMovie;
    bool m3D;
};

#endif // TICKET_H
