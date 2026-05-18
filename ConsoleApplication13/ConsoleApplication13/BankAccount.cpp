#include "BankAccount.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

BankAccount::BankAccount(const char* ownerName, int number, double initialBalance) {
    size_t len = strlen(ownerName);
    owner = new char[len + 1];
    strcpy_s(owner, len + 1, ownerName);

    accountNumber = number;

    if (initialBalance < 0) {
        balance = 0;
        cout << "Предупреждение: баланс не может быть отрицательным! Установлен 0.\n";
    }
    else {
        balance = initialBalance;
    }
}

BankAccount::~BankAccount() {
    delete[] owner;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Ошибка: сумма должна быть > 0!\n";
    }
    else {
        balance += amount;
        cout << "Пополнение на " << fixed << setprecision(2) << amount << " руб.\n";
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Ошибка: сумма должна быть > 0!\n";
        return false;
    }
    if (amount > balance) {
        cout << "Ошибка: не хватает денег. Нужно " << amount << ", есть " << balance << "\n";
        return false;
    }
    balance -= amount;
    cout << "Снято " << fixed << setprecision(2) << amount << " руб.\n";
    return true;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::printInfo() {
    cout << "\n=== СЧЁТ ===\n";
    cout << "Владелец: " << owner << endl;
    cout << "Номер: " << accountNumber << endl;
    cout << "Баланс: " << fixed << setprecision(2) << balance << " руб.\n";
}