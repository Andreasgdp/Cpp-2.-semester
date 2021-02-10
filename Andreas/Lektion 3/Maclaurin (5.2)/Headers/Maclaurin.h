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

	long double calcFactorial(int order);

	long double calcAproxOfEx();
	long double calcAproxOfEx(int x, int order);
};

#endif // !MACLAURIN_h