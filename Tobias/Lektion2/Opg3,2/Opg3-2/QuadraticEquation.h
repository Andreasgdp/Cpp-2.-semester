#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H


class QuadraticEquation
{
public:
    // constructor
    QuadraticEquation();
    QuadraticEquation(double a,double b,double c);

    // Setter
    void setA(double a);
    void setB(double b);
    void setC(double c);

    //funtioner
    double Solve();

private:
    double mA, mB,mC;
};

#endif // QUADRATICEQUATION_H
