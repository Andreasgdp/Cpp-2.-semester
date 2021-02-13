#include "../Headers/AInt.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AInt arr;

	arr.fillArray(1, 100);
	arr.printArray();
	cout << "Occurs of '5': " << arr.countOccurs(5) << endl
		 << endl;
	arr.swapElems();
	arr.printArray();

	return 0;
}
