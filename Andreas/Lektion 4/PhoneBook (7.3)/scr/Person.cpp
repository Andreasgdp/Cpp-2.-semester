#include "../Headers/Person.h"

using namespace std;

Person::Person(/* args */)
{
}

Person::Person(string name, string phoneNum)
{
	mName = name;
	mPhoneNumber = phoneNum;
}

string Person::getName() const
{
	return mName;
}

string Person::getPhoneNum() const
{
	return mPhoneNumber;
}

Person::~Person()
{
}
