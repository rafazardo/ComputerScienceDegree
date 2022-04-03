#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

double SavingsAccount::_annualInterestRate = 3.00;

SavingsAccount::SavingsAccount(double addSavingsAccount) {
    _savingsBalance = addSavingsAccount;
}

double SavingsAccount::calculateMonthlyInterest() {
    _savingsBalance += _savingsBalance*(_annualInterestRate/12.00);
    return _savingsBalance;
}

