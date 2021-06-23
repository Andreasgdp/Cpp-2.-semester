#ifndef MATERIAL_H
#define MATERIAL_H
#include "TimeAndMaterials.h"


class Material : public TimeAndMaterials {
public:
    Material();
    Material(std::string description, double enhedspris);

    void setPrice(double price);
    void setDescription(const std::string &description);

    double getPrice() const override;
    std::string getText() const override;

private:
    std::string _description;
    double _enhedspris;
};

#endif // MATERIAL_H
