#include <iostream>

using namespace std;

#include "header_file.h"

int main() {
// declare list of account here. The size of the list is not fixed.
Account accounts;
    vector<Account> bankAccounts;
    int input = 0;


// run loop to continue program until terminated by user
    while(1){
        menu(&input);
        switch (input) {
// cases: call functions to perform tasks
            case 1:
                makeAccount(bankAccounts);
                break;
            case 2:
                depositAccount(bankAccounts);
                break;
            case 3:
                withdrawAccount(bankAccounts);
                break;
            case 4:
                transfer(bankAccounts);
                break;
            case 5:
                printAccount(bankAccounts);
                break;
            case 6:
                ActiveDeactive(bankAccounts);
                break;
            case 7:
                deleteAccount(bankAccounts);
                break;
            case 8:
                PrintAllAccount(bankAccounts);
                break;
            case 9:
                break;
            default:
                break;
        }

    }

}