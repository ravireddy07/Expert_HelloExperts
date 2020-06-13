package models;

import java.io.Serializable;
import java.util.ArrayList;

public class Account implements Cloneable, Serializable {

    private int account_id;
    private int pin;
    private double amount;
    private int account_type; //1 checking //2 saving
    private int bank_branch_id;
    
   	private ArrayList<Customer> customers;
    private BankBranch bank_branch;
    private boolean joint_account;

	public void addCustomer(Customer customer){
    	this.customers.add(customer);
    }
    
    public ArrayList<Customer> getCustomers() {
		return customers;
	}

	public void setCustomers(ArrayList<Customer> customers) {
		this.customers = customers;
	}

    public BankBranch getBank_branch() {
		return bank_branch;
	}

	public void setBank_branch(BankBranch bank_branch) {
		this.bank_branch = bank_branch;
	}

	public boolean isJoint_account() {
		return joint_account;
	}


	public void setJoint_account(boolean joint_account) {
		this.joint_account = joint_account;
	}

    public Account () {
    	customers = new ArrayList<Customer>();
    }

    public Account (int account_idIn) {
    	this.account_id = account_idIn;
    }

    public int getAccount_id() {
          return this.account_id;
    }
    public void setAccount_id(int account_idIn) {
          this.account_id = account_idIn;
    }

    public int getPin() {
          return this.pin;
    }
    public void setPin(int pinIn) {
          this.pin = pinIn;
    }

    public double getAmount() {
          return this.amount;
    }
    public void setAmount(double f) {
          this.amount = f;
    }

    public int getAccount_type() {
          return this.account_type;
    }
    public void setAccount_type(int account_typeIn) {
          this.account_type = account_typeIn;
    }

    public int getBank_branch_id() {
          return this.bank_branch_id;
    }
    public void setBank_branch_id(int bank_branch_idIn) {
          this.bank_branch_id = bank_branch_idIn;
    }

    public void setAll(int account_idIn,
          int pinIn,
          long amountIn,
          int account_typeIn,
          int bank_branch_idIn) {
          this.account_id = account_idIn;
          this.pin = pinIn;
          this.amount = amountIn;
          this.account_type = account_typeIn;
          this.bank_branch_id = bank_branch_idIn;
    }

    public boolean hasEqualMapping(Account valueObject) {

          if (valueObject.getAccount_id() != this.account_id) {
                    return(false);
          }
          if (valueObject.getPin() != this.pin) {
                    return(false);
          }
          if (valueObject.getAmount() != this.amount) {
                    return(false);
          }
          if (valueObject.getAccount_type() != this.account_type) {
                    return(false);
          }
          if (valueObject.getBank_branch_id() != this.bank_branch_id) {
                    return(false);
          }

          return true;
    }

    public String toString() {
        StringBuffer out = new StringBuffer(this.getDaogenVersion());
        out.append("\nclass Account, mapping to table account\n");
        out.append("Persistent attributes: \n"); 
        out.append("account_id = " + this.account_id + "\n"); 
        out.append("pin = " + this.pin + "\n"); 
        out.append("amount = " + this.amount + "\n"); 
        out.append("account_type = " + this.account_type + "\n"); 
        out.append("bank_branch_id = " + this.bank_branch_id + "\n"); 
        return out.toString();
    }

    public Object clone() {
        Account cloned = new Account();

        cloned.setAccount_id(this.account_id); 
        cloned.setPin(this.pin); 
        cloned.setAmount(this.amount); 
        cloned.setAccount_type(this.account_type); 
        cloned.setBank_branch_id(this.bank_branch_id); 
        return cloned;
    }

    public String getDaogenVersion() {
        return "DaoGen version 2.4.1";
    }

}
