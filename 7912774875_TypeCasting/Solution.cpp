/*                        Question
Exercise 1 : Why is the typecast operator needed to compute the mean in the statement mean = static_cast(float)(total)/value? 
             What do you think will happen if it is removed? Modify the code and try it. Record what happens. 
			 Make sure that you try both even and odd cases. Now put static_cast<float> total back in the program.
Exercise 2 : What happens if you enter a float such as 2.99 instead of an integer for value? Try it and record the results.
Exercise 3 : Modify the code so that it computes the mean of the consecutive positive integers n, n+1, n+2, …, m, where the use choose n and m, 
             For example, if the use picks 3 and 9, then the program should find the mean of 3, 4, 5, 6, 7, 8, and 9, which is 6.
*/
/*                      Explanation

Why is the typecast operator needed to compute the mean in the statement mean = static_cast(float)(total)/value?
  Answer: Because, mean = (float)total/value;.
          In this statement, variables total and value is of integer data type. when we do operations on same data type, 
		  that results the output in similar data type.
		  Example: 10 +ve numbers, total=55. So,
		  when we do total/value, 55/10=5. But, actuall result is 5.5. 
		  Here .5 will not be counted, that's why we use type casting to cobnvert the integer output to folat to store that .5 also. 
		  
*/

#include<iostream>
using namespace std;

int main() {
	int value,count=0, total = 0,total1 = 0, start, end;
	float mean,mean1;
	
	//Excercise -3    
    cout<<endl<<"Please enter a beginning positive integer"<<endl;
	cin>>start;
	cout<<"Please enter a ending positive integer"<<endl;
	cin>>end;

    for(int number=start;number<=end;number++) {
    	total1 += number;
    	count++;
    }
	mean1 = (float)total1/count;
	cout<<"The mean average of the Consecutive positive integers from "<<start<<" to "<<end<<" is "<<mean1<<endl;

	// Exercise -1 and 2
	cout<<endl<<endl<<endl;
	cout<<"Please enter a positive integer"<<endl;
	cin>>value;

    if(value>0) {
    	for(int number=1;number<=value;number++) {
    		total += number;
		}
		//mean = total/value;           //output will be 5
		mean = (float)total/value;      //output will be 5.5
		cout<<"The mean average of the first "<<value<<" positive integers is "<<mean<<endl;
    }
    else {
    	cout<<"Invalid input - integer must be positive"<<endl;
    }
   return 0;
}
