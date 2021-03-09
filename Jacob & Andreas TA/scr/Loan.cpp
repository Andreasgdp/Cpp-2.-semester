#include "../Headers/Loan.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

double Loan::totalInterest() const
{
	// Using bankers rounding w. lrint()
	return lrint(totalPayment() - mDebt);
}

double Loan::payment(int terms) const
{
	double const r = mInterestRate / mPaymentsPerYear;
	return (mDebt * (r / (1 - pow(1 + r, -terms))));
}

double Loan::totalPayment() const
{
	int const terms = mYears * mPaymentsPerYear;

	return payment(terms) * terms;
}

double Loan::totalInterestTaxDeducted(double taxDeductionRate) const
{
	return totalInterest() * (taxDeductionRate / 100);
}

void Loan::outputPeriodicalPayments(std::ostream &ost) const
{

	int const terms = mYears * mPaymentsPerYear;
	int const testTerms = (10 * 4);

	double **array;
	array = new double *[testTerms + 1];
	for (int i = 0; i < testTerms + 1; i++)
		array[i] = new double[3];

	// constructArray(array, testTerms);
	constructArray2(array, testTerms);

	ost << std::setw(22) << "Restgæld: "
		<< " | " << std::setw(13) << "Renteudgift:"
		<< " | " << std::setw(17) << " Tilbagebetaling:"
		<< " | " << std::endl;
	for (size_t i = 0; i < testTerms + 1; i++)
	{
		ost << std::setw(5) << i << ": " << std::setw(14) << *(*(array + i) + 0) << " | " << std::setw(13) << *(*(array + i) + 1) << " | " << std::setw(17) << *(*(array + i) + 2) << " | " << std::endl;
	}

	for (int i = 0; i < testTerms + 1; i++)
		delete[] array[i];
	delete[] array;
}

void Loan::constructArray(double **arr, size_t terms) const
{
	double ydelse = payment(terms);
	double rentePrTermin = (mInterestRate / mPaymentsPerYear);
	double rente = mDebt * rentePrTermin;
	double afdrag = ydelse - rente;

	// Restgæld
	*(*(arr + 0) + 0) = mDebt;
	// Renteudgift
	*(*(arr + 0) + 1) = mDebt * rentePrTermin;
	// Tilbagebetaling
	*(*(arr + 0) + 2) = *(*(arr + 0) + 1) * 0.36;

	for (size_t i = 1; i <= terms; i++)
	{
		// Restgæld
		*(*(arr + i) + 0) = *(*(arr + i - 1) + 0) - afdrag;
		// Renteudgift
		*(*(arr + i) + 1) = *(*(arr + i) + 0) * rentePrTermin;
		afdrag = ydelse - *(*(arr + i) + 1);
		// Tilbagebetaling
		*(*(arr + i) + 2) = *(*(arr + i) + 1) * 0.36;
	}
}

void Loan::constructArray2(double **arr, size_t terms) const
{
	double ydelse = payment(terms);
	double rentePrTermin = (mInterestRate / mPaymentsPerYear);
	double rente = mDebt * rentePrTermin;
	double afdrag = ydelse - rente;
	double sidsteRestgeld;

	// Restgæld
	*(*(arr + 0) + 0) = sidsteRestgeld = mDebt;
	// Renteudgift
	*(*(arr + 0) + 1) = mDebt * rentePrTermin;
	// Tilbagebetaling
	*(*(arr + 0) + 2) = *(*(arr + 0) + 1) * 0.36;

	bool first = true;
	double **end = &arr[terms];
	for (double **curr = arr; curr != end; ++curr)
	{
		if (!first)
		{
			// Restgæld
			*(*curr + 0) = sidsteRestgeld = sidsteRestgeld - afdrag;
			// Renteudgift
			*(*curr + 1) = *(*curr + 0) * rentePrTermin;
			afdrag = ydelse - *(*curr + 1);
			// Tilbagebetaling
			*(*curr + 2) = *(*curr + 1) * 0.36;
		}
		first = false;
	}
}