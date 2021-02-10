#ifndef MACLAURIN_h
#define MACLAURIN_h

class Maclaurin
{
private:
	int mOrder;
	int mX;

public:
	Maclaurin();
	Maclaurin(int x, int order);

	unsigned long long calcFactorial(int order);

	unsigned long long calcAproxOfEx();
	unsigned long long calcAproxOfEx(int x, int order);
};

#endif // !MACLAURIN_h