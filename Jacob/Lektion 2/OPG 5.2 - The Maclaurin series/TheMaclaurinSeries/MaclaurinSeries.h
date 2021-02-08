#ifndef MACLAURINSERIES_H
#define MACLAURINSERIES_H

class MaclaurinSeries
{
public:
    MaclaurinSeries();
    MaclaurinSeries(int x, int n);

    long long calcFactorial(int order);
    long long calcAproxOfEx();

private:
    int mX, mN;
};

#endif // MACLAURINSERIES_H
