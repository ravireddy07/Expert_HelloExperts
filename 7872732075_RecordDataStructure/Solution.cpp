/*
Input Format:

Each line in file contains information for 1 student
Each line is of the format : <student_id> <score1> <score2> <score3>


Sample:
12345 50 67 77
12346 77 80 85
12347 65 78 90
12348 85 90 95
12349 77 65 60

*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

# define MAX 50

struct Record {
    int student_id;
    double scores[3];
    double avgScore;
    char letterGrade;
};


void displayRecords(Record records[], int n);
void computeAverage(Record records[], int n);
void computeLetterGrade(Record records[], int n);
double computeClassAverage(Record records[], int n);
double computeClassStandardDeviation(Record records[], int n);
void displayClassAvgSD(Record records[], int n);

int main() {
    Record records[MAX];
    string filename = “StudentData.txt”;
    ifstream fin(filename.c_str());
    int n;
    
    if(fin.is_open()) {
        n = 0;
        while(!fin.eof()) {
            fin>>records[n].student_id;
            for(int i=0;i<3;i++) {
                fin>>records[n].scores[i];
            }
            n++;
        }
        
        fin.close()
        computeAverage(records,n);
        computeLetterGrade(records,n);
        displayRecords(records,n);
        displayClassAvgSD(records,n);
    }
    else {
        cout<<"Unable to open file : "<<filename<<endl;
    }

    return 0;
}


void displayRecords(Record records[], int n) {
    cout<<left<<setw(15)<<“Student id”<<right<<setw(10)<<“Score 1″<<right<<setw(10)<<“Score 2″<<right<<setw(10)<<“Score 3″<<right<<setw(15)<<“Average Score”
<<right<<setw(15)<<“Letter Grade”<<endl;

cout<<fixed<<setprecision(2);
for(int i=0;i<n;i++)
{
cout<<left<<setw(15)<<records[i].student_id<<right<<setw(10)<<records[i].scores[0]<<right<<setw(10)<<records[i].scores[1]<<right<<setw(10)<<records[i].scores[2]
<<right<<setw(10)<<records[i].avgScore<<right<<setw(12)<<records[i].letterGrade<<endl;
}
cout<<endl;
}

/
void computeAverage(Record records[], int n)
{
for(int i=0;i<n;i++)
{
records[i].avgScore = 0;
for(int j=0;j<3;j++)
records[i].avgScore += records[i].scores[j];
records[i].avgScore = records[i].avgScore/3;
}
}


void computeLetterGrade(Record records[], int n)
{
for(int i=0;i<n;i++)
{
if(records[i].avgScore >= 90)
records[i].letterGrade = ‘A’;
else if(records[i].avgScore >= 80)
records[i].letterGrade = ‘B’;
else if(records[i].avgScore >= 65)
records[i].letterGrade = ‘C’;
else if(records[i].avgScore >= 50)
records[i].letterGrade = ‘D’;
else
records[i].letterGrade = ‘F’;
}
}


double computeClassAverage(Record records[], int n)
{
if(n <= 0)
return 0;
double avg = 0;
for(int i=0;i<n;i++)
avg += records[i].avgScore;

avg = avg/n; 
return avg;
}


double computeClassStandardDeviation(Record records[], int n)
{
if(n <= 0)
return 0;

double avg = computeClassAverage(records,n);
double sd = 0;

for(int i=0;i<n;i++)
sd += pow(avg-records[i].avgScore,2);

sd = sqrt(sd/n);

return sd;
}


void displayClassAvgSD(Record records[], int n)
{
double avg = computeClassAverage(records,n); 
double sd = computeClassStandardDeviation(records, n); 
cout<<fixed<<setprecision(2);
cout<<“Class Average : “<<avg<<endl;
cout<<“Class Standard Deviation : “<<sd<<endl;
}
