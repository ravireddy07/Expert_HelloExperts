public class PayrollCalc 
{
    private String name;
    private double hoursWorked;
    private double hourlyPayRate;
    private static final double FEDERAL_TAX_WITHHOLDING_RATE = 0.20;
    private static final double STATE_TAX_WITHHOLDING_RATE = 0.09;
 
 
    public PayrollCalc() {
    }
 
    public PayrollCalc(String n, double hw, double hpr) {
        this.name = n;
        this.hoursWorked = hw;
        this.hourlyPayRate = hpr;
    }
 
    public double grossPay(double hourlyRate, double hrsWorked) {
        double grossPay = (hourlyRate * hrsWorked);
        return grossPay;
    }
 
    public double federalTax(double gross) {
        return FEDERAL_TAX_WITHHOLDING_RATE * gross;
    }
 
    public double stateTax(double gross) {
        return STATE_TAX_WITHHOLDING_RATE * gross;
    }
 
 
    public String getName() {
        return name;
    }
 
 
    public void setName(String name) {
        this.name = name;
    }
 
 
    public double getHoursWorked() {
        return hoursWorked;
    }
 
 
    public void setHoursWorked(double hoursWorked) {
        this.hoursWorked = hoursWorked;
    }
 
 
    public double getHourlyPayRate() {
        return hourlyPayRate;
    }
 
 
    public void setHourlyPayRate(double hourlyPayRate) {
        this.hourlyPayRate = hourlyPayRate;
    }
 
}

// @Copyright: Swaran Bindra

import java.util.*;

public class PayrollDriver {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		PayrollCalc data = new PayrollCalc();

		System.out.println("Enter your name: ");
		data.setName(input.next());

		System.out.println("Number of Hours Worked: ");
		data.setHoursWorked(Double.parseDouble(input.next()));

		System.out.println("Hourly Pay Rate: ");
		data.setHourlyPayRate(Double.parseDouble(input.next()));

		double grossAmount = data.grossPay(data.getHourlyPayRate(), data.getHoursWorked());

		System.out.println();
		System.out.println("------------------------------------");
		System.out.println("Name: " + data.getName());
		System.out.println("Hours Worked: " + data.getHoursWorked() + "hrs");
		System.out.println("Pay Rate: $" + data.getHourlyPayRate());
		System.out.println("Gross Pay: $" + grossAmount + '\n');
		System.out.println("DEDUCTIONS");
		System.out.println("Federal Tax Withholding (20%): $" + data.federalTax(grossAmount));
		System.out.println("State Tax Withholding (9%): $" + data.stateTax(grossAmount));
		System.out.println("Total Deductions: $" + (data.federalTax(grossAmount) + data.stateTax(grossAmount)));
		System.out.println("Net Pay: $" + (grossAmount - (data.federalTax(grossAmount) + data.stateTax(grossAmount))));

		input.close();
	}

}
