#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <array>

class Loan
{
public:
	Loan() : Loan(1.0, 30, 1, 1.0) {}
	// Skal initialisere Loan til at have
	Loan(double debt, int years, int paymentsPerYear, double interestRate) : mDebt(debt), mInterestRate(interestRate), mYears(years), mPaymentsPerYear(paymentsPerYear) {}

	// Returns the number of years the loan lasts
	int getYears() const { return mYears; };
	void setYears(int years) { mYears = years; }

	// Amount of payments per year (terminer)
	int getPaymentsPerYear() const { return mPaymentsPerYear; };
	void setPaymentsPerYear(int paymentsPerYear) { mPaymentsPerYear = paymentsPerYear; };

	// Debt
	double getDebt() const { return mDebt; };
	void setDebt(double debt) { mDebt = debt; }

	// Rente
	double getInterestRate() const { return mInterestRate; };
	void setInterestRate(double rate) { mInterestRate = rate; };

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

	void constructArray(double **arr, size_t length) const;

	template <size_t N>
	void constructArray2(double (*arr)[N][3], size_t length) const;
	
	

private:
	double mDebt, mInterestRate;
	int mYears, mPaymentsPerYear;
};

#endif // LOAN_H