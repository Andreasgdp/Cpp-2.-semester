#include "../Headers/AInt.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AInt arr;

	arr.fillArray(1, 20);
	arr.printArray();
	cout << "\n";
	arr.swapElems();
	arr.printArray();

	return 0;
}
