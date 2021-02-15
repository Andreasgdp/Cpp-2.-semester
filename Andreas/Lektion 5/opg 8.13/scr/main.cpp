// Ex. 8.13: ex08_13.cpp
// ? What does this program do?
// ! Answear:
// * Prints the value of the first string followed by the second string.
// * Then it runs mystery1() that goes through string1 in a while-loop from the first place in memory through to the last place in memory for that string,
// * untill the place in memory is \0 or in other words NULL.
// * The program then runs the for-loop that now runs the same as the while-loop, however the condition here is, that *s1 and *s2 has to be the same.
// * They will be the same for as many char's they have in common (only the amount of chars, not the value of the chars).
// * This is because string2 was created right after string1, so they have been placed in memory right after each other.
// * The for-loop runs, as the while-loop pushed the value of string1 on top of string2,
// * so for the num of chars they have in common, the for loop wil run and increment both of the strings memory pointers.

// * The difference between the two is, that the while-loop saves the changes to the pointer,
// * whereas the for-loop, as the incrementation is happening in the definition of the for-loop itself, is not saving the incrementation.

#include <iostream>
using namespace std;
void mystery1(char *, const char *); // prototype

int main()
{
	char string1[80];
	char string2[80];

	cout << "Enter two strings: ";
	cin >> string1 >> string2;
	mystery1(string1, string2);
	cout << string1 << endl;
	cout << string2 << endl;
} // end main

// ? What does this function do?
// ! Answear:
// * Look at the top of the document.

void mystery1(char *s1, const char *s2)
{
	while (*s1 != '\0')
		++s1;

	for (; (*s1 = *s2); ++s1, ++s2)
		; // empty statement
} // end function mystery1