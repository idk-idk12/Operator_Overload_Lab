#include "BankAccount.h"
#include <iostream>

using namespace std;


BankAccount::BankAccount(string accountNumber, string accountHolderName, double balance) {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
}

BankAccount::BankAccount(const BankAccount& other) {
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
    return *this;  // returns the current object instance
}

BankAccount::~BankAccount() {}

void BankAccount::setAccountNumberName(string accountHolderName) {
    this->accountHolderName = accountHolderName;
}

string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getAccountNumberName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

BankAccount& BankAccount::operator+=(double amount) {
    this->balance += amount;
    return *this;
}

BankAccount& BankAccount::operator-=(double amount) {
    this->balance -= amount;
    return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return this->accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {
    return this->balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {
    return this->balance > other.balance;
}

void BankAccount::printAccount(const BankAccount& account) {
    cout << endl;
    cout << "Account number: " << account.getAccountNumber() << endl;
    cout << "Account name: " << account.getAccountNumberName() << endl;
    cout << "Account balance: $" << account.getBalance() << endl;
}

BankAccount BankAccount::createAccountFromInput() {
    string accountId;
    string accountName;
    double initialBalance;
    cout << "Account number: ";
    cin >> accountId;
    cout << "Account name: ";
    cin >> accountName;
    cout << "Initial balance: ";
    cin >> initialBalance;
    BankAccount account(accountId, accountName, initialBalance);
    return account;
}

