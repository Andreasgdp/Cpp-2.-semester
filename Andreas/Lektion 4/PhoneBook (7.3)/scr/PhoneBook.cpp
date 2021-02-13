#include "../Headers/PhoneBook.h"
#include <iostream>

using namespace std;

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addPerson(Person p)
{
	mPhoneBook[mNumInPhoneBook] = p;
	mNumInPhoneBook += 1;
}

Person PhoneBook::getPerson(string searchStr) const
{
	std::array<Person, 100> peopleFound;
	int numPeopleFound = 0;

	for (int i = 0; i < mNumInPhoneBook; i++)
	{
		if (mPhoneBook[i].getName().find(searchStr) != string::npos)
		{
			cout << "Person w. name: '" << mPhoneBook[i].getName()
				 << "' and phone number '" << mPhoneBook[i].getPhoneNum()
				 << "' was found w. search string '" << searchStr << "'." << endl;
			peopleFound[numPeopleFound] = mPhoneBook[i];
			numPeopleFound += 1;
		}
	}

	Person foundPerson;

	for (int i = 0; i < numPeopleFound; i++)
	{
		if (peopleFound[i].getName().compare(searchStr) == 0)
		{
			return peopleFound[i];
		}
		else
		{
			foundPerson = peopleFound[i];
		}
	}

	return foundPerson;
}
