/*
 * Dette program tager to strings som input, disse strings bruges som parametre i funktionen mystery1().
 * Funkitonen laver pointers til stringsne. While-loopet lægger 1 til pointeren for string1 indtil den finder slutningen af strengen (\0),
 * dermed peger s1 på slutningen af string1. I for-loopet sættes værdien som s1 peger på (*s1) lig med værdien som s2 peger på (*s2).
 * Det vil sige at første gang for-loopet køre bliver \0 til det første karakter i string2. Så lægges 1 til s1 og s2 og dermed fortsætter
 * for-loopet med at skrive string2 ind bagerst i string1, indtil den når string2's slut \0, hvor processen slutter og string1 udskrives.
 */

// Ex. 8.13: ex08_13.cpp
// What does this program do?
#include <iostream>
using namespace std;

void mystery1(char *, const char *); // prototype

int main() {
char string1[80];
char string2[80];

cout << "Enter two strings: ";
cin >> string1 >> string2;
mystery1(string1, string2);
cout << string1 << endl;
} // end main

// What does this function do?
void mystery1(char *s1, const char *s2) {
while (*s1 != '\0')
    ++s1;

for (; (*s1 = *s2); ++s1, ++s2)
    ; // empty statement
} // end function mystery1
