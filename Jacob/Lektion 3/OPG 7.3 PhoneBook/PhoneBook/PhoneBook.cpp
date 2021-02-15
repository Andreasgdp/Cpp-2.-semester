#include "PhoneBook.h"
#include <string>
#include <iostream>

PhoneBook::PhoneBook() {

}

void PhoneBook::addPerson(Person person) {
    mPhoneBook[mNumInPhoneBook] = person;
    mNumInPhoneBook += 1;
}


Person PhoneBook::getPerson(std::string searchStr) const {
    std::array<Person, 100> peopleFound;
        int numPeopleFound = 0;

        for (int i = 0; i < mNumInPhoneBook; i++) {
            if (mPhoneBook[i].getName().find(searchStr) != std::string::npos) {
                std::cout << "Person w. name: '" << mPhoneBook[i].getName()
                     << "' and phone number '" << mPhoneBook[i].getPhoneNumber()
                     << "' was found w. search string '" << searchStr << "'." << std::endl;
                peopleFound[numPeopleFound] = mPhoneBook[i];
                numPeopleFound += 1;
            }
        }

        Person foundPerson;

        for (int i = 0; i < numPeopleFound; i++) {
            if (peopleFound[i].getName().compare(searchStr) == 0) {
                return peopleFound[i];
            } else {
                foundPerson = peopleFound[i];
            }
        }
        return foundPerson;
}
