#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
public:
    Person();
    Person(std::string name, std::string phoneNumber);

    std::string getName() const;
    std::string getPhoneNumber() const;

private:
    std::string mName;
    std::string mPhoneNumber;
};

#endif // PERSON_H
