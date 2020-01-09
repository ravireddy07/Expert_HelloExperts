#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int dayNumber=0;
void shedule1();
void shedule2();

void weekday() {
    if(dayNumber == 1) {
        cout<<"Monday"<<endl;
        shedule1();
    }
    else if(dayNumber == 2) {
        cout<<"Tuesday"<<endl;
        shedule1();
    }
    else if(dayNumber == 3) {
        cout<<"Wednesday"<<endl;
        shedule1();
    }
    else if(dayNumber == 4) {
        cout<<"Thursday"<<endl;
        shedule1();
    }
    else if(dayNumber == 5){
        cout<<"Friday"<<endl;
        shedule1();
    }
    else if(dayNumber == 6) {
        cout<<"Saturday"<<endl;
        shedule1();
    }
}

void weekend() {
    cout<<"Sunday"<<endl;
    shedule2();
}

void shedule1() {
    cout<<"Go to School,"<<endl;
    cout<<"Go to Work,"<<endl;
    cout<<"Dinner with Family."<<endl;
}

void shedule2() {
    cout<<"No School,"<<endl;
    cout<<"No Work,"<<endl;
    cout<<"Enjoy with friends ad family"<<endl;
}

int main() {
    cout<<"Enter a day number (e.g.1(Monday), 2(Tuesday)) to display schedule: ";
    int day;
    cin>>day;
    dayNumber = day;
    if(dayNumber >= 1 || dayNumber <=6) {
        weekday();
    }
    else if(dayNumber == 7) {
        weekend();
    }
    return 0;
}

