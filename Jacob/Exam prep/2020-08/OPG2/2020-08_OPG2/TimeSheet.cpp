#include "TimeSheet.h"
#include <iomanip>
#include <algorithm>
#include "Material.h"
#include <iostream>
#include "WorkHours.h"

TimeSheet::TimeSheet() {}

TimeSheet::~TimeSheet() {
    for (TimeAndMaterials *t : mItems) {
        delete t;
    }
}

void TimeSheet::addTimeAndMaterial(TimeAndMaterials *tm) {
    mItems.push_back(tm);
}

void TimeSheet::sortByType() {
    std::sort(mItems.begin(), mItems.end(), [](const TimeAndMaterials* const lhs, const TimeAndMaterials* const rhs)
        {
            if (dynamic_cast<const Material* const>(lhs))
                return true;
            if (dynamic_cast<const Material* const>(rhs))
                return false;
            return false;
        }
    );
}

std::ostream &operator<<(std::ostream& out, const TimeSheet& ts) {
    out << std::right << std::setw(8) << "Antal" << " T "
              << std::left << std::setw(40) << "Udf\x9Brt arbejde og materialeforbrug"
              << std::right << std::setw(10) << "Pris"
              << std::setw(10) << "I alt" << std::endl;

    for (const TimeAndMaterials* tm : ts.mItems) {
            char c;
            if (dynamic_cast<const WorkHours*>(tm))
                c = 'W';
            else if (dynamic_cast<const Material*>(tm))
                c = 'M';
            else
                c = '?';

            out << std::right << std::setw(8) << tm->getAmount() << " "
                << std::setw(1) << c << " "
                << std::left << std::setw(40) << tm->getText()
                << std::right << std::setw(10) << tm->getPrice()
                << std::setw(10) << tm->totalPrice()
                << std::endl;
    }
    return out;
}
