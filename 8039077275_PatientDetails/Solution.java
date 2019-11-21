import java.util.*;
import java.io.*;

public class HealthProfile {
    private String firstname;
    private String secondname;
    private String DOB;
    private int day;
    private int month;
    private int year;
    private int weight;
    private int height;
    private String gender;

    public HealthProfile(String firstname, String secondname, int day, int month, int year, int weight, int height,
            String gender) {
        this.setFirstname(firstname);
        this.setSecondname(secondname);
        this.setDOB(day, month, year);
        this.setWeight(weight);
        this.setHeight(height);
        this.setGender(gender);
    }

    public String getDOB() {
        return DOB;
    }

    public void setDOB(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
        DOB = this.day + " " + this.month + " " + this.year;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getSecondname() {
        return secondname;
    }

    public void setSecondname(String secondname) {
        this.secondname = secondname;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public double BMI() {
        this.getWeight();
        this.getHeight();
        double bmi = (getWeight() * 703) + (getHeight() * getHeight());
        return bmi;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public int age() {
        int age = 2013 - this.year;
        return age;
    }

    public double MaxHeartRate() {
        int range = age() - 220;
        return range;
    }

    public double TargetHeartRate() {
        int range = (50 / 100) - (80 / 100);
        double target = range * MaxHeartRate();
        return target;
    }
}


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
        System.out.println("The patient's Max Heart Rate is : " + MaxHeartRate);
        System.out.println("The patient's Target Heart Rate is : " + TargetHeartRate);
        System.out.println("The patient's Age is : " + age);
        System.out.println("The patient's Gender is : " + gender);
        System.out.println("The patient's height in inches: "+height);
        System.out.println("The patient's weight in Pounds: "+weight);
        System.out.println("The patient's DOB(mm/dd/yyyy) is : " + month +"/"+ day +"/"+ year);
    }
    
    void Calculation() {
        age = currYear - year;
        MaxHeartRate = 220 - age;
        TargetHeartRate = MaxHeartRate * 0.85;
        BMI = (weight * 703) / (65 * 2);
    }
}

class HealthProfileTest {
    public static void main(String[] args) {
        Patient p = new Patient();
        Scanner input = new Scanner(System.in);

        p.getPatientDetails();
        p.Calculation();
        p.displayDetails();
    }
}