#include "Loan.h"
#include <iostream>
#include <iomanip>
#include <cmath>

double Loan::totalInterest() const
{
    // Implementing Bankers rounding on Øre not Krone
    return lrint((totalPayment() - _debt) * 100) / 100.0;
}

double Loan::payment(int terms) const
{
    double const r = _interestRate / _paymentsPerYear;

    return (_debt * (r / (1 - pow(1 + r, -terms))));
}

double Loan::totalPayment() const
{
    int const terms = _years * _paymentsPerYear;

    return payment(terms) * terms;
}

double Loan::totalInterestTaxDeducted(double taxDeductionRate) const
{
    return totalInterest() * (taxDeductionRate / 100);
}

void Loan::outputPeriodicalPayments(std::ostream &ost) const
{

    int const testTerms = _years * _paymentsPerYear;

    // Creating 2D-pointer-pointer-array
    double **array;
    array = new double *[testTerms + 1];
    for (int i = 0; i < testTerms + 1; i++)
        array[i] = new double[3];

    ost << std::setw(21) << "Debt remaining: "
        << " | " << std::setw(13) << "Intrest expences:"
        << " | " << std::setw(17) << "Taxdeduction:"
        << " | " << std::endl;

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
    double paymentVar = payment(terms);
    double intrestPrTerm = (_interestRate / _paymentsPerYear);
    double repayment = 0;
    double lastRemainingDebt = _debt;

    // Using index to iterate over array
    for (size_t i = 0; i <= terms; i++)
    {
        // Restgæld
        *(*(arr + i) + 0) = lastRemainingDebt = lastRemainingDebt - repayment;
        // Renteudgift
        *(*(arr + i) + 1) = lastRemainingDebt * intrestPrTerm;
        repayment = paymentVar - *(*(arr + i) + 1);
        // Tilbagebetaling
        *(*(arr + i) + 2) = *(*(arr + i) + 1) * 0.306;

        ost << std::fixed << std::setprecision(2)
            << std::setw(5) << i << ": "
            << std::setw(14) << *(*(arr + i) + 0) << " | "
            << std::setw(17) << *(*(arr + i) + 1) << " | "
            << std::setw(17) << *(*(arr + i) + 2) << " | "
            << std::endl;
    }
}

void Loan::printArray2(double **arr, size_t terms, std::ostream &ost) const
{
    double paymentVar = payment(terms);
    double intrestPrTerm = (_interestRate / _paymentsPerYear);
    double repayment = 0;
    double lastRemainingDebt = _debt;

    // Using pointer to itterate over the array instead of index.
    double **end = &arr[terms];
    int counter = 0;
    for (double **curr = arr; curr != end + 1; ++curr)
    {
        // Restgæld
        *(*curr + 0) = lastRemainingDebt = (lrint(lastRemainingDebt - repayment) == 0) ? 0 : lastRemainingDebt - repayment;
        // Renteudgift
        *(*curr + 1) = lastRemainingDebt * intrestPrTerm;
        repayment = paymentVar - *(*curr + 1);
        // Tilbagebetaling
        *(*curr + 2) = *(*curr + 1) * 0.306;

        ost << std::fixed << std::setprecision(2)
            << std::setw(5) << counter++ << ": "
            << std::setw(14) << *(*curr + 0) << " | "
            << std::setw(17) << *(*curr + 1) << " | "
            << std::setw(17) << *(*curr + 2) << " | "
            << std::endl;
    }
}

void Loan::printLoanInformation(std::ostream &ost) const
{
    ost << "Loan information:" << std::endl;
    ost << "Debt: " << _debt << std::endl;
    ost << "InterestRate: " << _interestRate << std::endl;
    ost << "Years: " << _years << std::endl;
    ost << "PaymentsPerYear: " << _paymentsPerYear << std::endl
        << std::endl;
}
