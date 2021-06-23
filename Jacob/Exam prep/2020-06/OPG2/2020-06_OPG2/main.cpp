#include "Plot.h"
#include "Buyer.h"

#include <iostream>
#include <iomanip>
#include <vector>

void findWinningBids(std::vector<Buyer*> buyers) {
    std::vector<Buyer*> dBuyers;
    dBuyers = buyers;
    std::vector<Buyer*> dWinners;
    std::vector<Buyer*> dNone;

    dWinners.push_back(dBuyers[dBuyers.size()]);
    dBuyers.pop_back();

    int count = 0;
    while (dBuyers.size() > 0) {
        std::cout << count << std::endl;
        Buyer* buyer = dBuyers[0 + count];
        for (Bid* b : buyer->getBids()) {
            for (size_t i = 0; i < dWinners.size(); i++) {
                for (Bid* wb : dWinners[i]->getBids()) {
                    if (b->getPlot() == wb->getPlot() && b->getPrice() > wb->getPrice()) {
                        dBuyers.push_back(dWinners[i]);
                        dWinners.erase(dWinners.begin() + i);
                        dWinners.push_back(buyer);
                        dBuyers.erase(dBuyers.begin() + count);
                    }
                }
            }
        }
        count += 1;
    }
    dNone = dBuyers;
    dBuyers.clear();

    std::cout << "Winners: " << std::endl;
    for (size_t i = 0; i < dWinners.size(); i++) {
        std::cout << dWinners.at(i) << std::endl;
    }

    std::cout << "Loosers: " << std::endl;
    for (size_t i = 0; i < dNone.size(); i++) {
        std::cout << dNone.at(i) << std::endl;
    }

    std::cout << "Buyers: " << std::endl;
    for (size_t i = 0; i < dBuyers.size(); i++) {
        std::cout << dBuyers.at(i) << std::endl;
    }

    /*
        så længe der er budgivere i dBuyers
            sæt buyer = næste budgiver i dBuyers
            for hvert bud b fra buyer i prioriteret rækkefølge gøres
                hvis bud b er bedre end tidligere bud på grunden g
                    hvis grunden g var vundet af en anden køber oldBuyer
                        flyt oldBuyer fra køen dWinners til dBuyers
                    sæt bedste bud b på grunden g
                    flyt budgiver buyer fra dBuyers til dWinners
                    afbryd løkken
            hvis ingen bud fra buyer kan vinde en grund
                flyt buyer fra dBuyers til dNone
        udskriv vindere
        udskriv tabere
    */
}


int main()
{
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "-- Test Opgave 2a --" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::vector<Plot*> plots;
    plots.push_back(new Plot("Stendyssen 1"));
    plots.push_back(new Plot("Stendyssen 3"));
    plots.push_back(new Plot("Stendyssen 5"));
    plots.push_back(new Plot("Stendyssen 7"));
    plots.push_back(new Plot("Stendyssen 9"));
    plots.push_back(new Plot("Stendyssen 11"));
    plots.push_back(new Plot("Stendyssen 13"));
    plots.push_back(new Plot("Stendyssen 15"));
    plots.push_back(new Plot("Stendyssen 17"));
    std::vector<Buyer*> buyers;
    buyers.push_back(new Buyer("Preben"));
    buyers.push_back(new Buyer("Ole"));
    buyers.push_back(new Buyer("Henrik"));
    buyers.push_back(new Buyer("Christian"));
    buyers.push_back(new Buyer("Jan"));
    buyers[0]->addBid(plots[7], 996408, 1);
    buyers[0]->addBid(plots[8], 985400, 2);
    buyers[0]->addBid(plots[5], 990312, 3);
    buyers[1]->addBid(plots[7], 997315, 2);
    buyers[1]->addBid(plots[8], 985123, 1);
    buyers[1]->addBid(plots[5], 1001002, 3);
    buyers[2]->addBid(plots[7], 1002003, 1);
    buyers[2]->addBid(plots[4], 1000000, 2);
    buyers[3]->addBid(plots[5], 990123, 1);
    buyers[3]->addBid(plots[4], 999000, 2);
    buyers[4]->addBid(plots[5], 991322, 1);
    buyers[4]->addBid(plots[8], 990000, 2);
    for (Buyer* buyer : buyers) {
        for (Bid* bid : buyer->getBids()) {
            std::cout << std::left << std::setw(12)
                      << bid->getBuyer()->getName()
                      << std::setw(20) << bid->getPlot()->getAddress()
                      << std::right << std::setw(9)
                      << std::setprecision(10) << bid->getPrice()
                      << std::setw(5) << bid->getPriority() << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "-- Test Opgave 2b --" << std::endl;
    std::cout << "--------------------" << std::endl;
    findWinningBids(buyers);
    std::cout << std::endl;
    std::cout << std::left << std::setw(12) << "Navn" <<
    std::setw(20) << "Grund" <<
    std::right << std::setw(9) << "Pris" <<
    std::setw(5) << "Pr." << std::endl;
    for (Plot* g : plots) {
        Bid* bid = g->getBid();
        if (bid) {
            std::cout << std::left << std::setw(12) <<
            bid->getBuyer()->getName() <<
            std::setw(20) << bid->getPlot()->getAddress() <<
            std::right << std::setw(9) << bid->getPrice() <<
            std::setw(5) << bid->getPriority() << std::endl;
        } else {
            std::cout << std::left << std::setw(12) << "Ikke solgt" <<
            std::setw(20) << g->getAddress() << std::endl;
        }
    }
}
