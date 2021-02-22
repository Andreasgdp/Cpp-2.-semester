#ifndef AINT_H
#define AINT_H
#include <array>

class AInt
{
private:
	std::array<int, 13> mArr{};

public:
	AInt(/* args */);
	~AInt();

	void fillArray(int aMinVal, int bMaxVal);
	int getMaxVal() const;
	void printArray() const;
	int countOccurs(int num) const;
	void swapElems();
};

#endif // !AINT_H
