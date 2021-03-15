#ifndef PI_H
#define PI_H

class Pi
{
public:
    Pi();
    Pi(int order);

    double calcPi();

private:
    int mOrder;
    double mPi;
};

#endif // PI_H
