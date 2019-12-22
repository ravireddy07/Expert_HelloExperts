#include<iostream>
using namespace std;

void withdrawal(int bal) {
    int amt;
    cout<<endl<<"Enter Withdrawal amount: ";
    cin>>amt;
    if(amt>bal) {
        cout<<endl<<"Insufficient Funds in account."<<endl;
    }
    else {
        bal = bal - amt;
        cout<<endl<<"Available BAlance: "<<bal;
    }
    return;
}

void deposit(int bal) {
    int amt;
    cout<<endl<<"Enter amount to Deposit: ";
    cin>>amt;
    
    bal = bal + amt;
    cout<<endl<<"Available BAlance: "<<bal;

    return;
}

int main() {
    int accNum, initialbal, repeat;
    char choice;

    do{
        cout<<"Enter Account Number: ";
        cin>>accNum;
        cout<<endl<<"Enter Initial Balance: ";
        cin>>initialbal;
        
        
        cout<<endl<<"SAVINGS ACCOUNT TRANSACTION";
        cout<<endl<<"(W)ithdrawal";
        cout<<endl<<"(D)eposit";
        cout<<endl<<"(Z)to end account transaction";
        cout<<endl<<"Enter first letter of the transaction type(W,D,Z): ";
        cin>>choice;

        if(choice == 'W' || choice == 'w') {
            withdrawal(initialbal);
        }
        else if(choice == 'D' || choice == 'd') {
            deposit(initialbal);
        }
        else if (choice == 'Z' || choice == 'z') {
            return 0;
        }
        else {
            cout<<endl<<"Incorrect option. Try again.";
        }
        cout<<endl<<"Want to repeat the process..!!!";
        cout<<endl<<"Press 1 to continue,";
        cout<<endl<<"Press 0 to Quit/Exit,";
        cin>>repeat;
    } while(repeat != 0);
}