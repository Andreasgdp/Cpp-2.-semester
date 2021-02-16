#include "../Headers/Person.h"
#include "../Headers/PhoneBook.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Person p1("James", "69420666");
	Person p2("Lilly", "22222222");
	Person p3("Harry", "11111111");

	PhoneBook pBook;

	pBook.addPerson(p1);
	pBook.addPerson(p2);
	pBook.addPerson(p3);

	string sTerm = "a";
	Person foundP = pBook.getPerson(sTerm);

	cout << "You found '" << foundP.getName()
		 << "' with search term '" << sTerm << "'. The phonenumber for this person is: "
		 << foundP.getPhoneNum() << "." << endl;

	return 0;
}
