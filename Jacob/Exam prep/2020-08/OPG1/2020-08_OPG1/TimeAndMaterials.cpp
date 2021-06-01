#include "TimeAndMaterials.h"
#include <iomanip>

TimeAndMaterials::TimeAndMaterials() {
    mAmount = 0;
}

TimeAndMaterials::TimeAndMaterials(double amount) {
    mAmount = amount;
}

std::ostream &operator<<(std::ostream& out, const TimeAndMaterials& t) {
    out << std::right << std::setw(8) << t.getAmount() << " "
        << std::left << std::setw(40) << t.getText()
        << std::right << std::setw(10) << t.getPrice()
        << std::setw(10) << t.totalPrice();
    return out;
}
