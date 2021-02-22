#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Person.h"

#include <array>
#include <vector>

class PhoneBook
{
private:
	std::vector<Person> mPhoneBook;
public:
	PhoneBook(/* args */);
	~PhoneBook();

	void addPerson(Person p);

	Person getPerson(std::string searchStr) const;

};

#endif // !PHONEBOOK_H