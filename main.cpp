// Jonathan Contreras-Jimenez
// 10/5/2026
// Bank account manager

#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;


void myCin(int &x) {
    // this handles non-int inputs
    if (!(cin >> x)) {
	// these two lines clears the buffer and ensures that the user can input again.
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool myCin(double &x) {
    // this handles non-int inputs
    if (!(cin >> x)) {
	// these two lines clears the buffer and ensures that the user can input again.
	cout << "Amount must be a number." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return false;
    }
    return true;
}


bool is_accounts_nonemtpy(vector<BankAccount>& accounts) {
    if (accounts.empty()) {
	cout << "No accounts have been made." << endl;
	return false;
    }
    return true;
}

void display_menu(int& userChoice) {
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. View Account Details" << endl;
    cout << "5. View All Accounts" << endl;
    cout << "6. Get Richest Account" << endl;
    cout << "7. Get Poorest Account" << endl;
    cout << "8. Print Sorted Accounts" << endl;
    cout << "9. Quit" << endl;
    myCin(userChoice);
}

/**
 * Prompts the user for an account number and searches the list of accounts for a match.
 * If no account matches, an error message is printed.
 *
 * @param accounts the vector of all bank accounts to search through
 * @return the index of the matching account in the vector, or -1 if no account
 *         with the entered account number exists
 */
int getAccount(const vector<BankAccount>& accounts) {
    string accountNum;
    cin >> accountNum;
    for (int i = 0; i < accounts.size(); ++i) {
	if (accounts.at(i).getAccountNumber() == accountNum) {
	    return i;
	}
    }
    cout << "Account '" << accountNum << "' not found" << endl;
    return -1;
}

/**
 * Creates a new account from user input and adds it to the list of accounts.
 * If an account with the same account number already exists, an error message
 * is printed and the new account is not added.
 *
 * @param accounts the vector of all bank accounts; the new account is appended to it
 *                 if its account number is unique
 */
void addAccount(vector<BankAccount>& accounts) {
    BankAccount candAccount = BankAccount::createAccountFromInput();  // candAccount = candidate account
    for (const BankAccount& account : accounts) {
	if (candAccount.getAccountNumber() == account.getAccountNumber()) {
	    cout << "Account with account number '" << candAccount.getAccountNumber() << "' already exists." << endl;
	    return;
	}
    }
    accounts.push_back(candAccount);
}

/**
 * Prompts the user for an account number and a deposit amount, then adds the
 * amount to that account's balance. Prints an error message if the amount is
 * invalid (non-numeric or negative). Does nothing further if the account is not found.
 *
 * @param accounts the vector of all bank accounts; the selected account's balance
 *                 is modified in place
 */
void deposit(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	cout << "Account number: ";
	int accountIdx = getAccount(accounts);
	if (accountIdx != -1) {
	    // without the '&' it creates a copy of the account object, and thus will not see any change after this function.
	    BankAccount& account = accounts.at(accountIdx);
	    double amount;
	    cout << "Deposit amount: $";
	    if (myCin(amount) && amount >= 0) {
		account += amount;
	    }
	    else {
		cout << "Invalid amount" << endl;
	    }
	}
    }
}

/**
 * Prompts the user for an account number and a withdrawal amount, then subtracts
 * the amount from that account's balance. Prints an error message if the amount
 * is invalid (non-numeric or negative) or if the account has insufficient funds.
 * Does nothing further if the account is not found.
 *
 * @param accounts the vector of all bank accounts; the selected account's balance
 *                 is modified in place
 */
void withdraw(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	cout << "Account number: ";
	int accountIdx = getAccount(accounts);
	if (accountIdx != -1) {
	    BankAccount& account = accounts.at(accountIdx);
	    double amount;
	    cout << "Withdraw amount: $";
	    if (myCin(amount) && amount >= 0) {
		if (account.getBalance() >= amount) {
		    account -= amount;
		    cout << "Successfully withdrew specified amount from account." << endl << endl;
		}
		else {
		    cout << "Insufficient funds in account to withdraw specified amount." << endl << endl;
		}
	    }
	    else {
		cout << "Invalid amount" << endl;
	    }
	}
    }
}


/**
 * Prompts the user for an account number and prints the details of that account.
 * Does nothing further if the account is not found.
 *
 * @param accounts the vector of all bank accounts to search through
 */
void getAccountDetails(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	cout << "Account number: ";
	int accountIdx = getAccount(accounts);
	if (accountIdx != -1) {
	    BankAccount account = accounts.at(accountIdx);
	    BankAccount::printAccount(account);
	}
    }
}


/**
 * Prints the details of every account in the list.
 * Does nothing if the list of accounts is empty.
 *
 * @param accounts the vector of all bank accounts to display
 */
void getAllAccountDetails(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	for (const BankAccount& account : accounts) {
	    BankAccount::printAccount(account);
	}
    }
}


/**
 * Finds the account with the highest balance and prints its details.
 * If multiple accounts share the highest balance, the one that appears
 * first in the vector is reported. Does nothing if the list is empty.
 *
 * @param accounts the vector of all bank accounts to search through
 */
void getRichestAccount(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	BankAccount richestAccount = accounts.at(0);
	for (const BankAccount& account : accounts) {
	    if (account.getBalance() > richestAccount.getBalance()) {
		richestAccount = account;
	    }
	}
	cout << "Richest Account details:";
	BankAccount::printAccount(richestAccount);
    }
}


/**
 * Finds the account with the lowest balance and prints its details.
 * If multiple accounts share the lowest balance, the one that appears
 * first in the vector is reported. Does nothing if the list is empty.
 *
 * @param accounts the vector of all bank accounts to search through
 */
void getPoorestAccount(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	BankAccount poorestAccount = accounts.at(0);
	for (const BankAccount& account : accounts) {
	    if (account.getBalance() < poorestAccount.getBalance()) {
		poorestAccount = account;
	    }
	}
	cout << "Poorest Account details:";
	BankAccount::printAccount(poorestAccount);
    }
}


/**
 * Sorts the accounts using the overloaded < operator, then prints the details
 * of every account in sorted order. Note that this reorders the vector
 * permanently, so the accounts will stay in sorted order for all later
 * operations. Does nothing if the list is empty.
 *
 * @param accounts the vector of all bank accounts; sorted in place
 */
void printSortedAccounts(vector<BankAccount>& accounts) {
    if (is_accounts_nonemtpy(accounts)) {
	sort(accounts.begin(), accounts.end());
	getAllAccountDetails(accounts);
    }
}


int main() {
    int userChoice;
    vector<BankAccount> accounts;
    do {
	display_menu(userChoice);
	switch (userChoice) {
	    case 1:
		addAccount(accounts);
		break;
	    case 2:
		deposit(accounts);
		break;
	    case 3:
		withdraw(accounts);
		break;
	    case 4:
		getAccountDetails(accounts);
		break;
	    case 5:
		getAllAccountDetails(accounts);
		break;
	    case 6:
		getRichestAccount(accounts);
		break;
	    case 7:
		getPoorestAccount(accounts);
		break;
	    case 8:
		printSortedAccounts(accounts);
		break;
	    case 9:
		break;
	    default:
		cout << "Only 1-9 options are avaliable." << endl;
		break;
	}
	cout << endl;
    }
    while (userChoice != 9);
    return 0;
}
