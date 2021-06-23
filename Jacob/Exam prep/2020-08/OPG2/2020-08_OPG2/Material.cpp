#include "Material.h"

Material::Material() {
    _description = "";
    _enhedspris = 0;
}

Material::Material(std::string description, double enhedspris) {
    _description = description;
    _enhedspris = enhedspris;
}

void Material::setDescription(const std::string &description) {
    _description = description;
}

double Material::getPrice() const {
    return _enhedspris;
}

std::string Material::getText() const {
    return _description;
}

void Material::setPrice(double Price) {
    _enhedspris = Price;
}
