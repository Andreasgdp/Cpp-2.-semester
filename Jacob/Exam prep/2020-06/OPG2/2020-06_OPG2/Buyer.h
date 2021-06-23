#ifndef BUYER_H
#define BUYER_H
#include <string>
#include <vector>
#include "Bid.h"
#include "Plot.h"

class Buyer {
public:
    Buyer() {}
    Buyer(const std::string& name) : mName(name) {}

    void setName(const std::string& name) { mName = name; }
    const std::string& getName() const { return mName; }

    // Laver et bud (Bid) på grunden plot med prisen price
    // Gem bud i mBids vector (bemærk pointer)
    // Skal sortere alle bud afhængig af prioritet, så
    // højeste prioritet er (1.) er forrest i listen.
    // HINT: std::sort med brug af lambda-funktion
    void addBid(Plot* plot, double price, int priority);

    // Returner alle bud lavet af denne køber/budgiver
    std::vector<Bid*> getBids();

private:
    std::string mName;
    std::vector<Bid*> mBids;
};
#endif // BUYER_H
