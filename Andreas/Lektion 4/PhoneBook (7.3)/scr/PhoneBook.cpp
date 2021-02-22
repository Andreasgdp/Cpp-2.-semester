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
	mPhoneBook.push_back(p);
}

Person PhoneBook::getPerson(string searchStr) const
{
	std::array<Person, 100> peopleFound;
	int numPeopleFound = 0;

	for (int i = 0; i < mPhoneBook.size(); i++)
	{
		if (mPhoneBook.at(i).getName().find(searchStr) != string::npos)
		{
			cout << "Person w. name: '" << mPhoneBook.at(i).getName()
				 << "' and phone number '" << mPhoneBook.at(i).getPhoneNum()
				 << "' was found w. search string '" << searchStr << "'." << endl;
			peopleFound[numPeopleFound] = mPhoneBook.at(i);
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
