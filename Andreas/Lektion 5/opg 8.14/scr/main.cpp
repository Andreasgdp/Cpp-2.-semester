// Ex. 8.13: ex08_13.cpp
// ? What does this program do?
// ! Answear:
// *

// Ex. 8.14: ex08_14.cpp
// ? What does this program do?
// ! Answear:
// *
#include <iostream>
using namespace std;

int mystery2(const char *); // prototype

int main()
{
	char string1[80];

	cout << "Enter a string: ";
	cin >> string1;
	cout << mystery2(string1) << endl;
}

// ? What does this function do?
// ! Answear:
// * Look at the top of the document.

int mystery2(const char *s)
{
	unsigned int x;

	for (x = 0; *s != '\0'; ++s)
	{
		++x;
	}

	return x;
}