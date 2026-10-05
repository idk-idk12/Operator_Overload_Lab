# BankAccount

A class representing a bank account

## Data Dictionary

| Attribute    | Data Type    | Description|
|--------------|--------------|------------
| `accountNumber`      | `std::string` | Account ID for the user|
| `accountHolderName`  | `std::string` | The name to have the account under
| `balance`            | `int`         | The amount of money in the account


## Methods List

| Method Signature                                            | Return Type   | Description   |
|-------------------------------------------------------------|---------------|---------------|
| `BankAccount()`                                               | (Constructor)   | Default constructor |
| `BankAccount(accountNumber, accountHolderName, balance)`      | (Constructor)   | Parameterized constructor |
| `setAccountNumberName(accountNumberName)`                     | `void`          | sets the account's ID number |
| `getAccountNumber()`                                          | `string`        | gets the account's ID number |
| `getAccountNumberName()`                                      | `string`        | gets the account's name |
| `getBalance()`                                                | `double`        | gets the account's balance |
| `deposit(amount)`                                             | `void`          | deposits the given amount into the account
| `withdraw(amount)`                                            | `bool`          | withdraws the specified amount; returns true if withdrawal was successful, false otherwise.
