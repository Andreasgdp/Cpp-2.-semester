#include "WorkHours.h"

WorkHours::WorkHours(double standardPrice) {
    _standardPrice = standardPrice;
}

WorkHours::WorkHours(double standardPrice, double extraPrice) {
    _standardPrice = standardPrice;
    _extraPrice = extraPrice;
}

WorkHours::WorkHours(double standardPrice, double extraPrice, double amount) : TimeAndMaterials(amount) {
    _standardPrice = standardPrice;
    _extraPrice = extraPrice;
}

double WorkHours::getPrice() const {
    return _standardPrice + _extraPrice;
}

std::string WorkHours::getText() const {
    return _text;
}

void WorkHours::setStandardPrice(double standardPrice) {
    _standardPrice = standardPrice;
}

void WorkHours::setExtraPrice(double extraPrice) {
    _extraPrice = extraPrice;
}

void WorkHours::setDescription(const std::string &value) {
    _text = value;
}
