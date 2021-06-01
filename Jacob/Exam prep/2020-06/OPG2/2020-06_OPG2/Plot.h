#ifndef PLOT_H
#define PLOT_H
#include <string>

class Bid;

class Plot
{
public:
    Plot() : mBid(nullptr) {}
    Plot(const std::string& address) : mAddress(address), mBid(nullptr) {}
    void setBid(Bid* bid) { mBid = bid; }
    Bid* getBid() { return mBid; }
    const Bid* getBid() const { return mBid; }
    void setAddress(const std::string& address) { mAddress = address; }
    const std::string& getAddress() const { return mAddress; }

private:
    std::string mAddress;
    Bid* mBid;
};
#endif // PLOT_H
