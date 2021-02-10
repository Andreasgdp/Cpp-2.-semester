#ifndef MACLAURIN_h
#define MACLAURIN_h

class Maclaurin
{
    //Variable
private:
    int mOrder;
    int mX;

    //Funktioner
public:
    Maclaurin();
    Maclaurin(int x, int order);

    long double calcFactorial(int order);

    long double calcAproxOfEx();
    long double calcAproxOfEx(int x, int order);
};

#endif
