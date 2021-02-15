#include "Person.h"

Person::Person() {

}

Person::Person(std::string name, std::string phoneNumber) {
    mName = name;
    mPhoneNumber = phoneNumber;
}

std::string Person::getName() const {
    return mName;
}

std::string Person::getPhoneNumber() const {
    return mPhoneNumber;
}
