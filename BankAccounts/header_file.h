//
// Created by Anthony on 3/14/2018.
//

#ifndef BANKACCOUNTS_HEADER_FILE_H
#define BANKACCOUNTS_HEADER_FILE_H


#include <cstring>
#include<iostream>
#include <vector>
using namespace std;


struct Account{
    int accountNumber;
    string lastName;
    string firstName;
    double accountBalance;
    bool active;
};
#endif //BANKACCOUNTS_HEADER_FILE_H


void menu(int*);
void makeAccount(vector<Account>&);
void printAccount(vector<Account>&);
void transfer(vector<Account>&);
void PrintAllAccount(vector<Account>&);
void depositAccount(vector<Account>&);
void ActiveDeactive(vector<Account>&);
void withdrawAccount(vector<Account>&);
void sortAccounts(vector<Account>&); // sort the accounts using the account numbers
void deleteAccount(vector<Account>&);