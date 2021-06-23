#ifndef LOT_H
#define LOT_H
#include <string>

class Lot
{
public:
    Lot();
    Lot(const std::string& Address, double MinPrice, int Size);

    std::string getAddress() const;
    void setAddress(const std::string &address);

    double getMinimumPrice() const;
    void setMinimumPrice(double minPrice);

    int getSize() const;
    void setSize(int size);

    friend std::ostream& operator<<(std::ostream& out, const Lot& l);
    friend std::istream& operator>>(std::istream& in, Lot& l);

private:
    std::string mAddress;
    double mMinPrice;
    int mSize;

};

#endif // LOT_H
