//Modify the grade book application so that it drops each students lowest score when determining the test score averages and letter grades.

//grade book application:
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

char letterGrade(double score);

int main() {
	char names[5][25]; //student names
	char grades[5]; //letter grades
	double scores[5][4]; //test scores
	double avgScore[5]; //average of 4 test scores
	double lowestScores[5], min;
	
	for(int i=0;i<5;i++) {
		cout<<"\nEnter student "<<(i+1)<<" name: ";
		cin>>names[i];
		cout<<"Enter his 4 scores: ";
		for(int j=0;j<4;j++) {
			cin>>scores[i][j];
			while(scores[i][j] > 100 || scores[i][j] <0) {
				cout<<"\ntest score should between 0 and 100"<<endl;
				cout<<"enter test score: ";
				cin>>scores[i][j];
			}
		}
	}
	//finding lowest Scores of all students and storing in an array, so that we can drop while calculating avg and grades
	
	for(int i=0;i<5;i++) {
		min=scores[i][0];
		for(int j=0;j<4;j++) {
			if(scores[i][j] <= min) {
				min = scores[i][j];
				lowestScores[i] = min;
			}
		}
	}
	cout<<endl;
	
	for(int i=0;i<5;i++) {
		cout<<endl<<"Lowest Score of Student "<<(i+1)<<" is: "<<lowestScores[i];
	}
	cout<<endl<<endl;
	
	//finding average score of each student and letter grade
	
	for(int i=0;i<5;i++) {
		avgScore[i] = 0;
		for(int j=0;j<4;j++) {
			if(scores[i][j] != lowestScores[i]) {
				avgScore[i] += scores[i][j];
			}
		}
		avgScore[i] = avgScore[i]/3;
		grades[i] = letterGrade(avgScore[i]);
	}
	
	//displaying average test score and letter grade
	
	cout<<"\nStudent Name\tAverage Score\tLetter Grade"<<endl;
	
	for(int i=0;i<5;i++) {
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout<<names[i]<<"\t\t"<<setprecision(2)<<avgScore[i]<<"\t\t"<<grades[i]<<endl;
	}
	
	return 0;
}

//return letter grade based on the test score passed as parameter

char letterGrade(double score) {
	if(score >= 90 && score <=100) {
		return 'A';
	}
	else if(score >= 80 && score <90) {
		return 'B';
	}
	else if(score >= 70 && score <80) {
		return 'C';
	}
	else if(score >= 60 && score <70) {
		return 'D';
	}
	else {
		return 'F';
	}
}
