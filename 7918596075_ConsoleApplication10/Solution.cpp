#include<iostream>
#include<string>


using namespace std;


struct Grades
{
string name;//Student's name
int studentID; //Student's Identification Number
double test [3];
double average;
char grade;

};
/* You can declare a array of structs like this :
 Grades variable_name[array_size]; and access it with variable_name[index].member.
 Example Grades details[4]; details[n].name;
 Check your functions and where and when you call them.
*/

// Function Prototypes.
int GetGrades(int, int, int);
int FindAverage(int, int);


int main()
{
Grades student;

Grades grd;
//Get Student name
cout << "Enter the Student name :";
cin.ignore();
getline(cin, grd.name);

//Get Student's ID
cout << "Enter the Student's Identification Number: ";
cin >> student.studentID;

//Get scores
cout << "Enter three test scores: ";


}

int grade()/* Try making this return a char of letterGrade instead of a int of zero and accept a variable of sum scores*/
{
const int numberOfGrades = 3;

int /*numberOfGrades,*/ letterGrade;
int totalPoints, average;

GetGrades(numberOfGrades, totalPoints, average); /* You are trying to call a function thats doesn't exist in the code*/

while (totalPoints >= 0)
{
if (totalPoints >= 90 && totalPoints == 100) // 90 and above
letterGrade = 'A';
else if (totalPoints >= 80 && totalPoints == 89) //80-89
letterGrade = 'B';
else if (totalPoints >= 70 && totalPoints == 79) //70-79
letterGrade = 'C';
else if (totalPoints >= 60 && totalPoints == 69) //60-69
letterGrade = 'D';
else if (totalPoints >= 0 && totalPoints == 59) //0-59
letterGrade = 'F';

}
return 0;
}


int FindAverage(int numericGrade, int numberOfGrades)
{
/* Display the average(to what or where)*/
return (numericGrade) / numberOfGrades;
}