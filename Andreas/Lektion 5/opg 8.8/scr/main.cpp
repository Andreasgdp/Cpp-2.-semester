#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	// For each of the following, write C++ statements that perform the
	// specified task. Assume that unsigned integers are stored in four bytes and that the starting address
	// of the built-in array is at location 1002500 in memory.

	// a) Declare a built-in array of type unsigned int called values with five elements, and
	// initialize the elements to the even integers from 2 to 10. Assume that the constant SIZE
	// has been defined as 5.
	const int SIZE = 5;

	int arr[SIZE] = {2, 4, 6, 8, 10};

	// b) Declare a pointer vPtr that points to an object of type unsigned int.
	int *vPtr;

	// c) Use a for statement to display the elements of built-in array values using array subscript notation ("array subscript notation" er arr[i] med brug af "[]").
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	// d) Write two separate statements that assign the starting address of built-in array values
	// to pointer variable vPtr.
	vPtr = arr;
	vPtr = &arr[0];

	// e) Use a for statement to display the elements of built-in array values using pointer/offset
	// notation.
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << *(vPtr + i) << endl;
	}

	// f) Use a for statement to display the elements of built-in array values using pointer/offset
	// notation with the built-in array’s name as the pointer.
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << *(arr + i) << endl;
	}

	// g) Use a for statement to display the elements of built-in array values by subscripting the
	// pointer to the built-in array.
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << vPtr[i] << endl;
	}

	// h) Refer to the fifth element of values using array subscript notation, pointer/offset notation with the built-in array name’s as the pointer, pointer subscript notation and pointer/offset notation.
	cout << *(arr + 4) << endl;
	cout << arr[4] << endl;
	cout << *(vPtr + 4) << endl;
	cout << vPtr[4] << endl;

	// ? i) What address is referenced by vPtr + 3? What value is stored at that location?
	// ! Answear:
	// * The address referenced by vPtr + 3 is the variable arr[3] and the value stored at that location is 8.

	return 0;
}
