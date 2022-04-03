class SavingsAccount {

private:
    double _savingsBalance;

public:
    static double _annualInterestRate;
    SavingsAccount(double addSavingsAccount);
    double calculateMonthlyInterest();
    static void modifyInterestRate(double addModifyInterestRate) {
        _annualInterestRate = addModifyInterestRate;
    }
};

