#ifndef DOLLARAMOUNT_H
#define DOLLARAMOUNT_H

#include <cmath>
#include <string>
#include <iostream>

class DollarAmount
{
public:
    explicit DollarAmount(int64_t value) : amount{value} {}

    void add(DollarAmount right) {
        amount += right.amount;
    }

    void setAmount(int amount) {
        DollarAmount::amount = amount;
    }

    void subtract(DollarAmount right) {
        amount -= right.amount;
    }

    void addInterest(int rate, int divisor) {
        DollarAmount interest{(amount * rate + divisor / 2) / divisor};
        add(interest);
        int dollars{std::abs((amount / 100))};
        int cents{std::abs(amount % 100)};
        if (cents != 0) {
            if (cents == 50) {
                if (dollars % 2 != 0) {
                    dollars += 1;
                }
            }
            else if (cents > 50) {
                dollars += 1;
            }
            int newAmount = dollars * 100;
            setAmount(newAmount);
        }
    }

    std::string toString() const {
        std::string dollars{std::to_string(amount / 100)};
        std::string cents{std::to_string(std::abs(amount % 100))};
        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    }

private:
    int64_t amount{0};
};

#endif // DOLLARAMOUNT_H
