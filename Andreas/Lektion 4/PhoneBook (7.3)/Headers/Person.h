#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
	std::string mName;
	std::string mPhoneNumber;

public:
	Person();
	Person(std::string name, std::string phoneNum);
	std::string getName() const;
	std::string getPhoneNum() const;

	~Person();
};

#endif // !PHONEBOOK_H