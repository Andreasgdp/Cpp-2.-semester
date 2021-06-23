#include "ProductionCalculator.h"
#include <sstream>
#include <iomanip>

ProductionCalculator::ProductionCalculator() {}

void ProductionCalculator::readData(std::istream &is) {
    while (!is.eof()) {
        std::string line;
        std::getline(is, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string idAndVar;
        std::getline(sline, idAndVar, ',');

        std::string::size_type sz;
        std::string first = idAndVar.substr(0, idAndVar.find(","));
        int id = std::stoi(first, &sz);
        std::string variant = first.substr(sz);

        std::string size;
        std::getline(sline, size, '#');

        std::string amount;
        std::getline(sline, amount, 'E');

        std::string tmp;
        std::getline(sline, tmp, 'U');
        std::getline(sline, tmp, 'R');

        std::string price;
        std::getline(sline, price);

        _vecExpenseItem.push_back(ExpenseItem(id,
                    std::stoi(size),
                    std::stoi(amount),
                    std::stod(price),
                    variant));
    }
}

double ProductionCalculator::totalProductionCost() {
    double total = 0;
    for (size_t i = 0; i < _vecExpenseItem.size(); i++) {
        total +=_vecExpenseItem[i].getTotalPrice();
    }
    return total;
}

std::ostream &operator<<(std::ostream &out, const ProductionCalculator &p) {
    int width = 10;
    out << std::right << std::fixed << std::setw(width) << "ID"
        << std::setw(width) << "Variant"
        << std::setw(width) << "Size"
        << std::setw(width) << "No"
        << std::setw(width) << "Price"
        << std::endl;

    for (ExpenseItem ei : p._vecExpenseItem) {
        out << std::right << std::fixed << std::setw(width) << ei.getId()
            << std::setw(width) << ei.getVariant()
            << std::setw(width) << ei.getSize()
            << std::setw(width) << ei.getAmount()
            << std::setw(width) << std::setprecision(2) << ei.getPrice()
            << std::endl;
    }
    return out;
}

