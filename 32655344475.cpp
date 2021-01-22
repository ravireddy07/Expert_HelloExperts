/*
Problem Discription:

University of Central Punjab (UCP) is arranging a competition of programming, in which IT department student can participate. In this competition student will be asked questions (True/False) and student will be given points, in the end student whose points are higher will be winner. Student whose marks are second highest is called runner up.
You are required to simulate this scenario using C++.
User will enter 3 options either True (T), False (F) or space for each question. As shown below
TFT TFTTFT
The answer to question 1 is true, the answer to question 2 is False, and student did not answer question 4. The exam has 10 questions.
Each correct answer is awarded two points, each wrong answer gets one point deducted, and no answer gets zero points.
Assume there are 10 students so you have to ask 10 strings of True false as seen above. Before entering answer ask user to write his/her serial number. So you have two array one contain roll number and one contains marks of each student. This concept is called parallel array. Note: please make sure using programming, that user should enter a unique serial#, if it selects a previously available serial#, tell /her to enter again.
Generate a random key that have correct answers in order to give students marks.
Tasks to be done:
Print winner and runner up serial# along with marks
Print all participants serial # and marks in descending order(parallel sorting)
Print average of marks of all students
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int students = 3;
    vector<int> marks;
    vector<int> serial;
    int takeSerialinput, score;
    string result="";
    for (int i = 0; i < students; ++i){
        try_again:
        cout << "Enter "<<i+1<<"st Student Serial Number #: ";
        cin >> takeSerialinput;
        auto it = find(serial.begin(), serial.end(), takeSerialinput);
        if(it != serial.end()){
            cout << "\nSorry this serial number is already present! try again:\n";
            goto try_again;
        }
        else{
            serial.push_back(takeSerialinput);
        }
        result="";
        cin.ignore();
        getline(cin, result, '\n');
        score=0;
        for (int j = 0; j < result.size();++j){
            if(result[j] == 'T'){
                score += 2;
            }
            else if(result[j] == 'F'){
                score -= 1;
            }
        }
        marks.push_back(score);
    }

    //Displaying data
    float avgMarks=0;
    cout<<"\n\nSerial : ";
    for(auto i : serial){
        cout<<i<<" ";
    }
    cout<<"\nMarks : ";
    for(auto i : marks){
        cout<<i<<" ";
        avgMarks+=i;
    }
    
    // Finding Winner:
    int index = max_element(marks.begin(), marks.end()) - marks.begin();
    cout << "\n\nWinner student is: " << serial[index] << " with marks " << marks[index] << "\n";

    marks.erase(marks.begin() + index);
    serial.erase(serial.begin() + index);
    // Runner
    index = max_element(marks.begin(), marks.end()) - marks.begin();
    cout << "Runner up student is: " << serial[index] << " with marks " << marks[index] << "\n\n";

    cout<<"Average of Marks: "<<(float)avgMarks/students<<"\n";
    
    return 0;
}
