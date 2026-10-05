#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;


class BankAccount {
public:
    BankAccount();
    BankAccount(string accountNumber, string accountHolderName, double balance);
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();
    // setters
    void setAccountNumberName(string accountNumberName);
    // getters
    // added const to the getters
    string getAccountNumber() const;
    string getAccountNumberName() const;
    double getBalance() const;
    // overloaded operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;
    // static functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
private:
    string accountNumber;
    string accountHolderName;
    double balance = 0.0;
};


#endif
