#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    unsigned int counter = 1;
	int last1;
	int last2 = 1;
	do
	{
		cout << counter << endl;
		last1 = last2;
		last2 = counter;
		counter = last1 + last2;

	} while (true);
	cout << counter << endl;
	return 0;
}