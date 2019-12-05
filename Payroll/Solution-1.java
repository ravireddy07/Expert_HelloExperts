import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.*;


//This is the class that is where the majority of the coding happens. 
//This class implements and runs everything for all three types of employees and then
//outputs their pay check and all the other tasks that are requried by this program
public class Payroll
{
	private Scanner scanner;
	private PayrollMenu menu;
	private ArrayList<Employee> employees;

	
public Payroll(String input)
	{
		//catch the exceptions
		try
		{
			scanner = new Scanner(new FileReader(input)); //scanner reads from input file
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Input file not found!");
			System.exit(1);
		}
		
		menu = new PayrollMenu(scanner); //creates a new menu object while passing in scanner to get commands
		employees = new ArrayList<Employee>();//creates employees array list
	}
		

	public Payroll()
	{
		scanner = new Scanner(System.in);
		menu = new PayrollMenu(scanner);
		employees = new ArrayList<Employee>();
	}


	public void go()
	{
		//welcome();
		menu = new PayrollMenu(scanner);
		PayrollCommand command = menu.getNextCommand();

		if (command == PayrollCommand.ADD_EMPLOYEE)
			addEmployee();
		else if (command == PayrollCommand.REMOVE_EMPLOYEE)
			removeEmployee();
		else if (command == PayrollCommand.SHOW_EMPLOYEES)
			showEmployees();
		else if (command == PayrollCommand.DO_WEEKLY_PAYROLL)
			doWeeklyPayroll();
		else if (command == PayrollCommand.QUIT)
			quit();

	}
	
	public boolean isThere(String name) //for loop statement for addemployee
	{
		boolean present = false; //by default, employee not found
		
		for (int index = 0; index < employees.size(); index++)
		{
			if (name.equals(employees.get(index).getName())) //checks for given employee and sets boolean present to true
			{	
				present = true;
			}
		}
		return present; //returns either true or false
	}
	
	public void welcome()
	{
		System.out.println("");
		System.out.println("ICS H22 Lab 3: The Price You Pay");
		System.out.println("Danish Khan and Adam Su");
		System.out.println("");
	}
	
	public void addEmployee()
	{
		String employeeName;
		String employeeType;
		int wage;
		//System.out.println("Please enter new employee name:");
		
		employeeName = scanner.nextLine(); //takes in new employee name
		
		if (isThere(employeeName))//checks to see if employee already exists
		{
			//System.out.println("The employee, "+employeeName+" is already in the database.  Please try again.");
			go();
		}
		//System.out.println("Please specify employee type (hourly, salaried, contract):");
		
		employeeType = scanner.nextLine();
		
			if (employeeType.compareToIgnoreCase("hourly") == 0) //takes in employee type
			{
				//System.out.println("What is the hourly wage of this employee (in cents): ");
				try
				{
					wage = (int)(scanner.nextDouble() * 100); //takes in hourly wage
					scanner.nextLine();
				}

				catch (InputMismatchException ime)
				{
					//System.out.println("Invalid entry.  Hourly wage needs to be a positive integer in cents. Please try again:");
					wage = (int)(scanner.nextDouble() * 100);
					scanner.nextLine();
					go();
				}
				
				Employee newHourlyEmployee = new hourlyEmployee(employeeName, wage); //creates new hourly employee object
				employees.add(newHourlyEmployee);//add employee to array
				System.out.println("SUCCESS! - New hourly employee, "+employeeName+", added successfully!");
				go();
			}
			else if (employeeType.compareToIgnoreCase("salaried") == 0)
			{
				//System.out.println("What is the annual wage of this employee (in cents): ");
				try
				{
					wage = (int)(scanner.nextDouble() * 100);
					scanner.nextLine();
				}

				catch (InputMismatchException ime)
				{
				//	System.out.println("Invalid entry.  Annual wage needs to be a positive integer in cents. Please try again:");
					wage = (int)(scanner.nextDouble() * 100);
					scanner.nextLine();
					go();
				}
				Employee newSalariedEmployee = new salariedEmployee(employeeName, wage);
				employees.add(newSalariedEmployee);	
				System.out.println("SUCCESS! - New salaried employee, "+employeeName+", added successfully!");
				go();
			}
			else if (employeeType.compareToIgnoreCase("contract") == 0)
			{
				//System.out.println("What is the hourly wage of this employee (in cents): ");
				try
				{
					wage = (int)(scanner.nextDouble() * 100);
					scanner.nextLine();
				}

				catch (InputMismatchException ime)
				{
					//System.out.println("Invalid entry.  Hourly wage needs to be a positive integer in cents. Please try again:");
					wage = (int)(scanner.nextDouble() * 100);
					scanner.nextLine();
					go();
				}
				Employee newContractEmployee = new contractEmployee(employeeName, wage);
				employees.add(newContractEmployee);
				System.out.println("SUCCESS! - New contract employee, "+employeeName+", added successfully!");
				go();
			}
			//System.out.println("Invalid employee type.  Please try again.");
			go();
	}
	
	public void removeEmployee()
	{
		String name;
		boolean found = false;
		int i = 0;

		//scanner = new Scanner(System.in);
		//System.out.println("Please input the full name of the employee you wish to remove: ");
		name = scanner.nextLine();
		while (i < employees.size() && (found == false))
		{
			if (name.compareToIgnoreCase(employees.get(i).getName()) == 0)
			{
				employees.remove(i);
				found = true;
			}
			i++;
		}

		if (found == false)
			System.out.println("ERROR! - The employee, "+name+", was not found in the database and could not be removed.");

		else
			System.out.println("SUCCESS! - Employee, "+name+", successfully removed from the database!");
	}
	
	private void showEmployees()
		{
			int c;
			for (c = 0; c < employees.size(); c++)
		{
		System.out.println(employees.get(c).toString());
		}
			go();
}
	
	public void doWeeklyPayroll()
	{
		ArrayList<String> payroll = new ArrayList<String>();
		int d = 0;
		int e = 0;
		int hoursWorked;
		for (d = 0; d < employees.size(); d++)
		{
		//	System.out.println("How many hours did " +employees.get(d).getName()+ 
		//			" work this week?");
			String temp = scanner.nextLine();
			hoursWorked = scanner.nextInt();
				scanner.nextLine();
			String tempPayroll = employees.get(d).createWeeklyPaycheck(hoursWorked).toString();
			payroll.add(d, tempPayroll);
		}
		
		for (e = 0; e < payroll.size(); e++)
		{
			System.out.println (payroll.get(e));
		}
		go();
	}
	
	public void quit()
	{
		System.out.println("Thank you for using the payroll program.  Good Bye...");
		System.exit(1);
	}
			

}