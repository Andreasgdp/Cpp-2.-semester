#ifndef LOAN_H
#define LOAN_H

#include <ostream>

class Loan
{
public:
    Loan() : Loan(1.0, 30, 1, 1.0) {}
    // Skal initialisere Loan til at have
    Loan(double debt, int years, int paymentsPerYear, double interestRate) : _debt(debt), _interestRate(interestRate), _years(years), _paymentsPerYear(paymentsPerYear) {}

    // Returns the number of years the loan lasts
    int getYears() const { return _years; };
    void setYears(int years) { _years = years; }

    // Amount of payments per year (terminer)
    int getPaymentsPerYear() const { return _paymentsPerYear; };
    void setPaymentsPerYear(int paymentsPerYear) { _paymentsPerYear = paymentsPerYear; };

    // Debt
    double getDebt() const { return _debt; };
    void setDebt(double debt) { _debt = debt; }

    // Rente
    double getInterestRate() const { return _interestRate; };
    void setInterestRate(double rate) { _interestRate = rate; };

    // Calculate the total interest of a loan for all the years
    double totalInterest() const;

    // Calculate the total repayment of a loan including the interests
    double totalPayment() const;

    // Calculate the repayment of a loan including the interests
    double payment(int terms) const;

    // Calculate the total net interest of a loan after tax refund
    double totalInterestTaxDeducted(double taxDeductionRate) const;

    // Output the periodical payments with unpaid balance paid interest and repayment of each payment to stream object ost
    void outputPeriodicalPayments(std::ostream &ost) const;

    void printArray(double **arr, size_t length, std::ostream &ost) const;

    void printArray2(double **arr, size_t length, std::ostream &ost) const;

    void printLoanInformation(std::ostream &ost) const;

private:
    double _debt, _interestRate;
    int _years, _paymentsPerYear;
};

#endif // LOAN_H
