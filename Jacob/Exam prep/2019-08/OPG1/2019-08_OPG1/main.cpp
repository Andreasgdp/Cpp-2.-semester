#include <iostream>
#include <vector>
#include <iomanip>
#include "Ticket.h"

using namespace std;

int main()
{
    std::cout << "Create tickets" << std::endl;
    std::vector<Ticket> tickets(2);
    std::cout << "Set ticket information" << std::endl;
    tickets[0].setTicketNo(1);
    std::cout << "Set date" << std::endl;
    tickets[0].setDate("13-08-2019");
    std::cout << "Set time" << std::endl;
    tickets[0].setTime("09:00");
    std::cout << "Set seat" << std::endl;
    tickets[0].setSeat("A12");
    std::cout << "Set movie" << std::endl;
    tickets[0].setMovie("Eksamen");
    std::cout << "Set price" << std::endl;
    tickets[0].setPrice(100);
    std::cout << "Set theater" << std::endl;
    tickets[0].setTheater(141);

    tickets[1].setTicketNo(2);
    tickets[1].setDate("01-09-2019");
    tickets[1].setTime("08:15");
    tickets[1].setSeat("A14");
    tickets[1].setMovie("Studiestart");
    tickets[1].setPrice(2000);
    tickets[1].setTheater(180);

    for(Ticket& t : tickets) {
    std::cout << std::right << std::setw(4) << t.getTicketNo()
            << std::right << std::setw(12) << t.getDate()
            << std::right << std::setw(7) << t.getTime()
            << std::right << std::setw(5) << t.getSeat()
            << " " << std::left << std::setw(40) << t.getMovie()
            << std::right << std::setw(5) << t.getPrice()
            << std::right << std::setw(5) << t.getTheater()
            << std::endl;
    }

    std::cout << "Create extra ticket" << std::endl;
    Ticket t;
    t.setTicketNo(3);
    t.setDate("14-08-2019");
    t.setTime("20:30");
    t.setMovie("Fast and Furious - Hobbs and Shaw");
    t.setPrice(105);
    t.setTheater(1);

    std::cout << "Copy and move constructors" << std::endl;
    tickets.push_back(t); // Copy constructor
    tickets.emplace_back(std::move(tickets[0])); // Move constructor

    std::cout << "Create an empty ticket" << std::endl;
    Ticket t1;
    tickets.push_back(t1);
    tickets.push_back(t1);

    std::cout << "Copy and move assignment" << std::endl;
    tickets[4] = t; // Copy assignment
    tickets[5] = std::move(tickets[1]); // Move assignment

    for(Ticket& t : tickets) {
    std::cout << std::right << std::setw(4) << t.getTicketNo()
            << std::right << std::setw(12) << t.getDate()
            << std::right << std::setw(7) << t.getTime()
            << std::right << std::setw(5) << t.getSeat()
            << " " << std::left << std::setw(40) << t.getMovie()
            << std::right << std::setw(5) << t.getPrice()
            << std::right << std::setw(5) << t.getTheater()
            << std::endl;
    }
}
