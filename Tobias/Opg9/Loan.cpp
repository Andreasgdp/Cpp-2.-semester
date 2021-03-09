#include "Loan.h"
#include <math.h>
Loan::Loan() {}


Loan::Loan ( double debt , int years , int paymentsPerYear , double interestRate )
{
    _debt = debt;
    _years = years;
    _paymentsPerYear = paymentsPerYear;
    _interestRate = interestRate;
};

// Returns the number of years the loan lasts
int Loan::getYears () const {
    return _years;
}
void Loan::setYears (int years ) {
    _years = years;
}

// Amount of payments per year ( terminer )
int Loan::getPaymentsPerYear () const {
    return _paymentsPerYear;
}
void Loan::setPaymentsPerYear ( int paymentsPerYear ) {
    _paymentsPerYear = paymentsPerYear;
}

// Debt
double Loan::getDebt () const {
    return _debt;
}
void Loan::setDebt ( double debt ) {
    _debt = debt;
}

// Rente
double Loan::getInterestRate () const {
    return _interestRate;
}
void Loan::setInterestRate ( double rate ) {
    _interestRate = rate;
}

double Loan::totalInterest() const {
    return round(Loan::totalPayment() - _debt);
}

double Loan::totalPayment() const {
    double G, r, y;
    int n;
    G = _debt;
    r = _interestRate / _paymentsPerYear / 100;
    n = _paymentsPerYear * _years;
    y = G * r /( 1 - pow(1 + r, -n)); // Dette retunerer hvor meget der skal betales per ydelse.

    return y * n;
}

double Loan::totalInterestTaxDeducted(double taxDeductionRate) const {
    return Loan::totalInterest() * (taxDeductionRate/100);
}

void Loan::outputPeriodicalPayments(std::ostream &ost) const {
    size_t n;
    n = _paymentsPerYear * _years;

    for (size_t i = 0; i < n ; i++ ) {

    }

}




