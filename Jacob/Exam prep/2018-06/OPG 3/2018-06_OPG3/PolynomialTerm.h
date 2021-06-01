#ifndef POLYNOMIALTERM_H
#define POLYNOMIALTERM_H


class PolynomialTerm {
public:
 // Default constructor skal initialize
 // member variable til default værdier
 PolynomialTerm();

 // Constructor til initialisering af member variable
 // Der skal anvendes initializer lists
 // (constructor initialization section)
 PolynomialTerm(double coefficient, int power):_coeff(coefficient),  _power(power) {};

 // Get-funktioner for member variable
 int getPower() const;

 double getCoefficient() const;

 // Set-funktioner for member variable
 void setPower(int power);
 void setCoefficient(double coeff);

 // Beregn ledets værdi når værdien for x kendes (parameteren)
 double evaluate(double x);

private:
 double _coeff; // Member variabel for koefficienten
 int _power; // Member variable for potensen (power)
};

#endif // POLYNOMIALTERM_H
