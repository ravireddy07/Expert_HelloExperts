#include <bits/stdc++.h>
using namespace std;
int main() {
    double totalAmount=0, purchaseAmount, countrySaleTax = 0.04, stateSaleTax = 0.02, totalSaleTax=0;
    cout<<"Enter the amount of Purchase: ";
    cin>>purchaseAmount;
    totalSaleTax = countrySaleTax + stateSaleTax;
    totalAmount = purchaseAmount - totalSaleTax;
    cout<<"Total Purchase Amount : "<<purchaseAmount<<endl;
    cout<<"Country Sale Tax : "<<countrySaleTax<<endl;
    cout<<"State Sale Tax : "<<stateSaleTax<<endl;
    cout<<"Total Sale Tax : "<<totalSaleTax<<endl;
    cout<<"Amount without Taxes : "<<totalAmount<<endl;
}

