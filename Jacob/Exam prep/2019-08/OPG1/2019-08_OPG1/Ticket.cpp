#include "Ticket.h"
#include <cstring>
#include <algorithm>

Ticket::Ticket() {
    mTheater = 0;
    mTicketNo = 0;
    mPrice = 0;
    std::strcpy(mDate, "00-00-0000");
    std::strcpy(mTime, "00:00");
    mSeat = new char[1];
    mSeat[0] = '\0';
    mMovie = new char[1];
    mMovie[0] = '\0';
    m3D = false;
}

Ticket::Ticket(const Ticket &t) {
    mTheater = t.mTheater;
    mTicketNo = t.mTicketNo;
    mPrice = t.mPrice;
    strcpy(mDate, t.mDate);
    strcpy(mTime, t.mTime);
    mSeat = new char[strlen(t.mSeat) + 1];
    strcpy(mSeat, t.mSeat);
    mMovie = new char[strlen(t.mMovie) + 1];
    strcpy(mMovie, t.mMovie);
    m3D = t.m3D;
}

Ticket::Ticket(Ticket &&t) {
    mTheater = std::move(t.mTheater);
    mTicketNo = std::move(t.mTicketNo);
    mPrice = std::move(t.mPrice);
    setDate(std::move(t.mDate));
    setTime(std::move(t.mTime));
    mSeat = std::move(t.mSeat);
    mMovie = std::move(t.mMovie);
    m3D = std::move(t.m3D);
}

Ticket::~Ticket() {
    if (mSeat != nullptr)
        delete[] mSeat;

    if (mMovie != nullptr)
        delete[] mMovie;
}

Ticket& Ticket::operator=(const Ticket &rhs) {
    mTheater = rhs.mTheater;
    mTicketNo = rhs.mTicketNo;
    mPrice = rhs.mPrice;
    strcpy(mDate, rhs.mDate);
    strcpy(mTime, rhs.mTime);
    mSeat = new char[strlen(rhs.mSeat) + 1];
    strcpy(mSeat, rhs.mSeat);
    mMovie = new char[strlen(rhs.mMovie) + 1];
    strcpy(mMovie, rhs.mMovie);
    m3D = rhs.m3D;

    return *this;
}

Ticket& Ticket::operator=(Ticket &&rhs) {
    mTheater = std::move(rhs.mTheater);
    mTicketNo = std::move(rhs.mTicketNo);
    mPrice = std::move(rhs.mPrice);
    setDate(std::move(rhs.mDate));
    setDate(std::move(rhs.mTime));
    mSeat = std::move(rhs.mSeat);
    mMovie = std::move(rhs.mMovie);
    m3D = std::move(rhs.m3D);

    return *this;
}

int Ticket::getTheater() const {
    return mTheater;
}

void Ticket::setTheater(int theater) {
    mTheater = theater;
}

int Ticket::getTicketNo() const {
    return mTicketNo;
}

void Ticket::setTicketNo(int ticketNo) {
    mTicketNo = ticketNo;
}

double Ticket::getPrice() const {
    return mPrice;
}

void Ticket::setPrice(double price) {
    mPrice = price;
}

const char *Ticket::getDate() const {
    return mDate;
}

void Ticket::setDate(const char *date) {
    if (date == nullptr)
        return;
    if (std::strlen(date) != 10)
        return;
    if (date[2] != '-' && date[5] != '-')
        return;
    std::strcpy(mDate, date);
}

const char *Ticket::getTime() const {
    return mTime;
}

void Ticket::setTime(const char *time) {
    if (time == nullptr)
        return;
    if (std::strlen(time) != 5)
        return;
    if (time[2] != ':')
        return;
    std::strcpy(mTime, time);
}

const char *Ticket::getSeat() const {
    return mSeat;
}

void Ticket::setSeat(const char *seat) {
    if (mSeat != nullptr)
        delete[] mSeat;
    if (seat != nullptr && std::strlen(seat) > 0) {
        mSeat = new char[std::strlen(seat)+1];
        std::strcpy(mSeat, seat);
    } else {
        mSeat = new char[1];
        mSeat[0] = '\0';
    }
}

const char *Ticket::getMovie() const {
    return mMovie;
}

void Ticket::setMovie(const char *movie) {
    if (mMovie != nullptr)
        delete[] mMovie;
    if (movie != nullptr && std::strlen(movie) > 0) {
        mMovie = new char[std::strlen(movie)+1];
        std::strcpy(mMovie, movie);
    } else {
        mMovie = new char[1];
        mMovie[0] = '\0';
    }
}

bool Ticket::get3D() const {
    return m3D;
}

void Ticket::set3D(bool value) {
    m3D = value;
}
