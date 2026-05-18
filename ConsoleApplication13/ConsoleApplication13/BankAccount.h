#pragma once

// Ѕанковский счЄт Ч инкапсул€ци€ + валидаци€
class BankAccount {
private:
    char* owner;
    int accountNumber;
    double balance;

public:
    BankAccount(const char* ownerName, int number, double initialBalance);
    ~BankAccount();

    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    void printInfo();
};