#ifndef PI_H
#define PI_H
#include <math.h>

class Pi
{

    //Funktioner
public:
    Pi();
    Pi(int order);
        ~Pi();

        double calcPi();

    //Variable
private:
    double mPi;
    int    mOrder;

};





#endif // PI_H





