//
// Created by Anthony on 3/14/2018.
//

#include <iostream>
#include "header_file.h"

using std::rand;
using std::srand;

#include <ctime>
using std::time;

using namespace std;

#include <algorithm>


void menu(int *num) {
    int select = 0;
    cout << "Welcome! Select options below:" << endl;
    cout << "\t1. Make new account."
            << "\n\t2. Deposit to an account." << "\n\t3. Withdraw from an account."<< "\n\t4. Transfer money."
            << "\n\t5. Print account." << "\n\t6. Activate/Deactivate an account."<<
            "\n\t7. Delete an account." << "\n\t8. Display all accounts."
            << "\n\t9. Quit." << endl;
    cout << "Selection:\t";
    cin >> select;
    *num = select;
}


void makeAccount(vector<Account> &Accounts) {
    struct Account accounts;
    srand(time(0));
    accounts.accountNumber= 1000+(rand()%9000);

    cout << "Creating bank account number " << accounts.accountNumber << endl;

    cout << "Enter first name: " << endl;
    cin >> accounts.firstName;

    cout << "Enter last name: " << endl;
    cin >> accounts.lastName;

    cout << "Enter starting balance: " << endl;
    cin >> accounts.accountBalance;
    while(accounts.accountBalance<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountBalance;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountBalance;
            //num;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountBalance;
        while(accounts.accountBalance<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountBalance;
        }
    }
    Accounts.push_back(accounts);
    sortAccounts(Accounts);
}


void sortAccounts(vector<Account> &Accounts){
    struct Account accounts;
   int next;

    for (next = 0; next<Accounts.size()-1 ; next++) {
        int from = 0, to, i;
        int min_pos=from;
        for (i = from+1; i<to; i++) {
            if (Accounts[i].accountNumber<Accounts[min_pos].accountNumber){
                min_pos=i;
            }
            Account temp;
            temp = Accounts[from];
            Accounts[from]=Accounts[min_pos];
            Accounts[min_pos]=temp;
        }

    }
}

void transfer(vector<Account> &Accounts)
{
    struct Account accounts;
    double withdraw_amount;
    int acc1=accounts.accountNumber;
    int acc2=accounts.accountNumber;
    cout<<"Enter account number for the sender: "<<endl;
    cin>>acc1;

    while(acc1<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>acc1;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>acc1;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>acc1;
        while(acc1<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>acc1;
        }

    }

    cout<<"Enter account number for the receiver: "<<endl;
    cin>>acc2;

    while(acc2<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>acc2;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>acc2;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>acc2;
        while(acc2<0){
            cout<<"Enter a positive number: "<<endl;
            acc2;
        }

    }

    cout<<"Enter amount to be transferred: "<<endl;
    cin>>withdraw_amount;

    while(withdraw_amount<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>withdraw_amount;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>withdraw_amount;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>withdraw_amount;
        while(withdraw_amount<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>withdraw_amount;
        }
    }

    if (accounts.active){
        for (int i = 0; i < Accounts.size(); i++){
            if (acc1==Accounts.at(i).accountNumber){
                if (Accounts.at(i).accountBalance>withdraw_amount){
                    Accounts.at(i).accountBalance -= withdraw_amount;
                }
                else{
                    cout<<"Not enough money."<<endl;
                }

            }

            if (acc2==Accounts.at(i).accountNumber){
                Accounts.at(i).accountBalance += withdraw_amount;
            }
        }
    }
    else{
        cout<<"At least one of the accounts is not active. Process cannot be done! \nFirst, you need to activate the deactivated account."<<endl;
    }
    Accounts.push_back(accounts);
}

void depositAccount(vector<Account> &Accounts)
{
    struct Account accounts;
    double deposit_amount;

    cout<<"Enter account number for deposit: "<<endl;
    cin>>accounts.accountNumber;

    while(accounts.accountNumber<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountNumber;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountNumber;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountNumber;
        while(accounts.accountNumber<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountNumber;
        }
    }

    cout<<"Enter amount to be deposited: "<<endl;
    cin>>deposit_amount;

    while(deposit_amount<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>deposit_amount;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>deposit_amount;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>deposit_amount;
        while(deposit_amount<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>deposit_amount;
        }
    }
    for (int i = 0; i < Accounts.size(); i++) {
        if (accounts.accountNumber == Accounts.at(i).accountNumber) {
            if (accounts.active) {
                cout << "The new balance is: " << (accounts.accountBalance += deposit_amount) << endl;
                Accounts.push_back(accounts);
            }
            else{
                cout << "Account is not active.Process cannot be done! First, you need to activate this account." << endl;
            }
        }
        else {
            cout << "The account does not exist! Try Again." << endl;
        }
    }
}

void withdrawAccount(vector<Account> &Accounts)
{
    struct Account accounts;
    double withdraw_amount;

    cout<<"Enter account number for withdrawal: "<<endl;
    cin>>accounts.accountNumber;

    while(accounts.accountNumber<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountNumber;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountNumber;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountNumber;
        while(accounts.accountNumber<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountNumber;
        }
    }

    cout<<"Enter amount to be withdrawn: "<<endl;
    cin>>withdraw_amount;

    while(withdraw_amount<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>withdraw_amount;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>withdraw_amount;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>withdraw_amount;
        while(withdraw_amount<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>withdraw_amount;
        }
    }

    for (int i = 0; i < Accounts.size(); i++) {
        if (accounts.accountNumber==Accounts.at(i).accountNumber) {
            if (accounts.active) {
                cout << "The new balance is: " << (accounts.accountBalance -= withdraw_amount) << endl;
                Accounts.push_back(accounts);
            } else if (!accounts.active) {
                cout << "Account is not active.Process cannot be done! First, you need to activate this account."
                     << endl;
            }
        }
        else{
            cout << "The account does not exist! Try Again." << endl;
        }
    }


}

void PrintAllAccount(vector<Account> &Accounts)
{
if (Accounts.empty()){
    cout<<"Sorry, no accounts exist in the database. \nPress 1 to get started."<<endl;
}
    else{
    for(int i=0; i<Accounts.size();i++) {
        cout << "Account number: " << Accounts[i].accountNumber << "\t\t\tBalance: " << Accounts[i].accountBalance
             << "\n\t\tLast name: " << Accounts[i].lastName << "\t\t\tFirst name: " << Accounts[i].firstName << endl;
    }
}

}
void deleteAccount(vector<Account> &Accounts) {
    struct Account accounts;
    cout << "Enter account number to be deleted: " << endl;
    cin >> accounts.accountNumber;

    while(accounts.accountNumber<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountNumber;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountNumber;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountNumber;
        while(accounts.accountNumber<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountNumber;
        }
    }

    for (int i = 0; i < Accounts.size(); i++) {
        if (accounts.accountNumber == Accounts.at(i).accountNumber) {
            Accounts.erase(Accounts.begin()+i);
            i--;

        }
        else{
            cout<<"The account does not exist! Try Again."<<endl;
        }

    }

}

void ActiveDeactive(vector<Account> &Accounts)
{
    struct Account accounts;
    accounts.active= true;
    int choice;
    cout<<"Enter account number for activation/deactivation: "<<endl;
    cin>>accounts.accountNumber;

    while(accounts.accountNumber<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountNumber;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountNumber;
            //num;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountNumber;
        while(accounts.accountNumber<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountNumber;
        }
    }

    cout<<"Press 1 to activate, 0 to deactivate: "<<endl;
    cin>>choice;

    while(choice!=0 && choice!=1){
        cout<<"Choose 0 or 1: "<<endl;
        cin>>choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number of 0 or 1: "<<endl;
            cin>>choice;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number of 0 or 1: "<<endl;
        cin>>choice;
        while(choice!=0 && choice!=1){
            cout<<"Choose 0 or 1: "<<endl;
            cin>>choice;
        }
    }

    for (int i = 0; i < Accounts.size(); i++) {
        if (accounts.accountNumber == Accounts.at(i).accountNumber) {
            if (choice==0)
            {
                accounts.active= false;
            }
            else if (choice==1){
                accounts.active= true;
            }
        }
        else{
            cout<<"The account does not exist! Try Again."<<endl;
        }
    }

}

void printAccount(vector<Account> &Accounts){
    struct Account accounts;
    cout << "Enter account number to be printed: " << endl;
    cin >> accounts.accountNumber;

    while(accounts.accountNumber<0){
        cout<<"Enter a positive number: "<<endl;
        cin>>accounts.accountNumber;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input. Enter a number: "<<endl;
            cin>>accounts.accountNumber;
        }

    }
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid Input. Enter a number: "<<endl;
        cin>>accounts.accountNumber;
        while(accounts.accountNumber<0){
            cout<<"Enter a positive number: "<<endl;
            cin>>accounts.accountNumber;
        }
    }

    for (int i = 0; i < Accounts.size(); i++) {
        if (accounts.accountNumber == Accounts.at(i).accountNumber) {
            cout << "Account number: " << Accounts[i].accountNumber << "\t\t\tBalance: " << Accounts[i].accountBalance
                 << "\n\t\tLast name: " << Accounts[i].lastName << "\t\t\tFirst name: " << Accounts[i].firstName
                 << endl;
        } else if (accounts.accountNumber != Accounts.at(i).accountNumber) {
            cout << "Account does not exist! Try Again." << endl;

        }
    }
}