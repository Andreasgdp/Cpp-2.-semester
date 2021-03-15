#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <array>
#include "Person.h"

class PhoneBook
{
public:
    PhoneBook();

    void addPerson(Person person);
    Person getPerson(std::string searchStr) const;

private:
    std::array<Person, 100> mPhoneBook;
    int mNumInPhoneBook = 0;
};

#endif // PHONEBOOK_H
