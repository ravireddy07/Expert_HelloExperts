//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct StudentInfo
{
	string name;			// student name
	unsigned int idNum;		// student ID number (Watch for overflow if id num is too long - can make it a string)
	int *tests;				// pointer to an array of test scores
	int average;			// average test score
	char grade;				// course grade
};


void compGrade(StudentInfo *, int);

int main() {
	int numScores, numStudents, total;			

	cout<<"How many test scores per student? ";
	cin>>numScores;
	cout<<"How many students? ";
	cin>>numStudents;
	
	StudentInfo *ptrStudents = nullptr;
	ptrStudents = new StudentInfo[numStudents];

	for(int count=0;count<numStudents;count++) {
		(ptrStudents + count)->tests = new int[numScores];
		
		cout<<"Enter the ID number for student "<<(count+1)<<": ";
		cin>>(ptrStudents + count)->idNum;
		
		cout<<"Enter the name for student "<<(count+1)<<": ";
		cin>>(ptrStudents+count)->name;
		
		total=0;
		
		for(int count2=0;count2<numScores;count2++) {
			do {
				cout<<"For student "<<(count+1)<<" enter score "<<(count2+1)<<": ";
				cin>>(*(ptrStudents+count)).tests[count2];
				
			}while((*(ptrStudents + count)).tests[count2]<0);
			
			total += (*(ptrStudents + count)).tests[count2];
		}
		
		(ptrStudents+count)->average = (total/numScores);
		compGrade(ptrStudents, count);	
	}
	
	cout<<"========================================\n\n";
	cout<<"\tInfo for all students\n";
	for(int count=0;count<numStudents;count++) {
		cout<<"Student "<<(count + 1)<<endl;
		cout<<"Name: "<<(ptrStudents+count)->name<<endl;
		cout<<"ID: "<<(ptrStudents+count)->idNum<<endl;
		cout<<"Average Test Score: "<<(ptrStudents+count)->average<<endl;
		cout<<"Course Grade: "<<(ptrStudents + count)->grade<<endl;

		cout<<"\n========================================\n";
	}

	delete[] ptrStudents;
	ptrStudents = nullptr;

	return 0;
}


void compGrade(StudentInfo *ptrSt, int student) {
	char grade;

	if ((ptrSt + student)->average >= 91 && (ptrSt + student)->average <= 100)
		(ptrSt + student)->grade = 'A';
	else if ((ptrSt + student)->average >= 81 && (ptrSt + student)->average <= 90)
		(ptrSt + student)->grade = 'B';
	else if ((ptrSt + student)->average >= 71 && (ptrSt + student)->average <= 80)
		(ptrSt + student)->grade = 'C';
	else if ((ptrSt + student)->average >= 61 && (ptrSt + student)->average <= 70)
		(ptrSt + student)->grade = 'D';
	else if ((ptrSt + student)->average <= 60)
		(ptrSt + student)->grade = 'F';
}
