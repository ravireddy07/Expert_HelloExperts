import java.util.*;
import java.io.*;

class Patient {
    String firstName, lastName, gender;
    double weight, height, BMI, MaxHeartRate, TargetHeartRate ;
    int day, month, year, currYear, age;
    Scanner input = new Scanner(System.in);

    void getPatientDetails() {
        System.out.println("Please enter the current year: ");
        currYear = input.nextInt();
        System.out.println("Please enter the patient's last name: ");
        lastName = input.next();
        System.out.println("Please enter the patient's first name: ");
        firstName = input.next();
        System.out.println("Please enter the Gender: ");
        gender = input.next();
        System.out.println("Please enter the patient's birthday as mm/dd/yyyy: ");
        System.out.println("First enter the month(mm): ");
        month = input.nextInt();
        System.out.println("then enter the day(dd): ");
        day = input.nextInt();
        System.out.println("Now enter the birth year(yyyy): ");
        year = input.nextInt();
        System.out.println("Please enter the patient's height in inches: ");
        height = input.nextDouble();
        System.out.println("Please enter the patient's weight in poundes: ");
        weight = input.nextDouble();
    }

    void displayDetails() {
        System.out.println("The patient's Name is: " + firstName +" "+ lastName);
        System.out.println("The patient's Max Heart Rate is : " + (int)MaxHeartRate);
        System.out.println("The patient's Target Heart Rate is : " + (int)TargetHeartRate);
        System.out.println("The patient's BMI is : " + BMI);
        System.out.println("The patient's Age is : " + age);
        System.out.println("The patient's Gender is : " + gender);
        System.out.println("The patient's height in inches: "+(int)height);
        System.out.println("The patient's weight in Pounds: "+(int)weight);
        System.out.println("The patient's DOB(mm/dd/yyyy) is : " + month +"/"+ day +"/"+ year);
    }
    
    void Calculation() {
        age = currYear - year;
        MaxHeartRate = 220 - age;
        TargetHeartRate = MaxHeartRate * 0.85;
        BMI = (((weight * 703)/65)/65);
    }
}

//Main Code(Driver code)
class HealthProfileTest {
    public static void main(String[] args) {
        Patient p = new Patient();
        Scanner input = new Scanner(System.in);

        p.getPatientDetails();
        p.Calculation();
        p.displayDetails();
    }
}