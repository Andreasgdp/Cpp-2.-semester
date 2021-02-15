#ifndef MACLAURINSERIES_H
#define MACLAURINSERIES_H

class MaclaurinSeries
{
public:
    MaclaurinSeries();
    MaclaurinSeries(int x, int n);

    long double calcFactorial(int order);
    long double calcAproxOfEx();

private:
    int mX, mN;
};

#endif // MACLAURINSERIES_H
