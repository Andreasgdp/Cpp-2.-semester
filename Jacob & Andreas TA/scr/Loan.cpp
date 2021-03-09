#include "../Headers/Loan.h"
#include <iomanip>
#include <cmath>

double Loan::totalInterest() const
{
	// Implementing Bankers rounding on Øre not Krone
	double number = (totalPayment() - mDebt) * 100;
	return lrint(number) / 100.0;
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

	// Creating 2D-pointer-pointer-array
	double **array;
	array = new double *[testTerms + 1];
	for (int i = 0; i < testTerms + 1; i++)
		array[i] = new double[3];

	// Using index to iterate over array
	// printArray(array, testTerms, ost);

	// Using pointer to itterate over the array instead of index.
	printArray2(array, testTerms, ost);

	for (int i = 0; i < testTerms + 1; i++)
		delete[] array[i];
	delete[] array;
}

void Loan::printArray(double **arr, size_t terms, std::ostream &ost) const
{
	double ydelse = payment(terms);
	double rentePrTermin = (mInterestRate / mPaymentsPerYear);
	double rente = mDebt * rentePrTermin;
	double afdrag = 0;
	double restGeld = mDebt;

	ost << std::setw(22) << "Restgæld: "
		<< " | " << std::setw(13) << "Renteudgift:"
		<< " | " << std::setw(17) << " Tilbagebetaling:"
		<< " | " << std::endl;

	// Using index to iterate over array
	for (size_t i = 0; i <= terms; i++)
	{
		// Restgæld

		*(*(arr + i) + 0) = restGeld = restGeld - afdrag;
		// Renteudgift
		*(*(arr + i) + 1) = restGeld * rentePrTermin;
		// Tilbagebetaling
		*(*(arr + i) + 2) = *(*(arr + i) + 1) * 0.306;

		afdrag = ydelse - *(*(arr + i) + 1);

		ost << std::fixed << std::setprecision(2) << std::setw(5) << i << ": " << std::setw(14) << *(*(arr + i) + 0) << " | " << std::setw(13) << *(*(arr + i) + 1) << " | " << std::setw(17) << *(*(arr + i) + 2) << " | " << std::endl;
	}
}

void Loan::printArray2(double **arr, size_t terms, std::ostream &ost) const
{
	double ydelse = payment(terms);
	double rentePrTermin = (mInterestRate / mPaymentsPerYear);
	double rente = mDebt * rentePrTermin;
	double afdrag = 0;
	double sidsteRestgeld = mDebt;

	ost << std::setw(22) << "Restgæld: "
		<< " | " << std::setw(13) << "Renteudgift:"
		<< " | " << std::setw(17) << " Tilbagebetaling:"
		<< " | " << std::endl;

	// Using pointer to itterate over the array instead of index.
	double **end = &arr[terms];
	int counter = 0;
	for (double **curr = arr; curr != end + 1; ++curr)
	{
		// Restgæld
		*(*curr + 0) = sidsteRestgeld = sidsteRestgeld - afdrag;
		// Renteudgift
		*(*curr + 1) = sidsteRestgeld * rentePrTermin;
		// Tilbagebetaling
		*(*curr + 2) = *(*curr + 1) * 0.306;

		afdrag = ydelse - *(*curr + 1);

		ost << std::fixed << std::setprecision(2) << std::setw(5) << counter++ << ": " << std::setw(14) << *(*curr + 0) << " | " << std::setw(13) << *(*curr + 1) << " | " << std::setw(17) << *(*curr + 2) << " | " << std::endl;
	}
}