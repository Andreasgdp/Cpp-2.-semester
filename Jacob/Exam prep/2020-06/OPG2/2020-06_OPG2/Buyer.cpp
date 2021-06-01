#include "Buyer.h"
#include <algorithm>

void Buyer::addBid(Plot *plot, double price, int priority) {
    mBids.push_back(new Bid(this, plot, price, priority));
    std::sort(mBids.begin(), mBids.end(), [](Bid* a, Bid* b) {
        return a->getPriority() < b->getPriority();
    });
}

std::vector<Bid *> Buyer::getBids() {
    return mBids;
}
