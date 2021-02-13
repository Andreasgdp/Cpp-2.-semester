#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Person.h"

#include <array>

class PhoneBook
{
private:
	std::array<Person, 100> mPhoneBook;
	int mNumInPhoneBook = 0;

public:
	PhoneBook(/* args */);
	~PhoneBook();

	void addPerson(Person p);

	Person getPerson(std::string searchStr) const;

};

#endif // !PHONEBOOK_H