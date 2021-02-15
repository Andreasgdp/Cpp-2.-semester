#include <iostream>
#include "Person.h"
#include "PhoneBook.h"
#include <array>

using namespace std;

int main()
{
    Person p1("P1", "11111111");
    Person p2("P2", "22222222");
    Person p3("P3", "33333333");

    PhoneBook pBook;

    pBook.addPerson(p1);
    pBook.addPerson(p2);
    pBook.addPerson(p3);

    string sTerm = "1";
    Person foundP = pBook.getPerson(sTerm);

    cout << "You found '" << foundP.getName()
         << "' with " << sTerm << ". The phonenumber for this person is: "
         << foundP.getPhoneNumber() << "." << endl;

    return 0;
}
