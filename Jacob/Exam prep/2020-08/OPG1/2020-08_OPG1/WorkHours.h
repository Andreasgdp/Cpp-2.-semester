#ifndef WORKHOURS_H
#define WORKHOURS_H
#include "TimeAndMaterials.h"

class WorkHours : public TimeAndMaterials {
public:
    WorkHours(double standardPrice = 0);
    WorkHours(double standardPrice, double extraPrice);
    WorkHours(double standardPrice, double extraPrice, double amount);

    double getPrice() const override;
    std::string getText() const override;

    void setStandardPrice(double standardPrice);
    void setExtraPrice(double extraPrice);
    void setDescription(const std::string &value);

private:
    double _standardPrice, _extraPrice;
    std::string _text;
};

#endif // WORKHOURS_H
