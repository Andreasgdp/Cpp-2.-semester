#include "../Headers/DollarAmount.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	DollarAmount d(1000);

	d.addInterest(1, 4);

	cout << d.toString() << endl;

	return 0;
}
