package models;

import java.io.*;
import java.sql.*;
import java.util.*;
import java.math.*;

public class BankBranch implements Cloneable, Serializable {

	private int bank_branch_id;
	private String name;
	private String location;
	private String description;

	public BankBranch() {

	}

	public BankBranch(int bank_branch_idIn) {

		this.bank_branch_id = bank_branch_idIn;

	}

	public int getBank_branch_id() {
		return this.bank_branch_id;
	}

	public void setBank_branch_id(int bank_branch_idIn) {
		this.bank_branch_id = bank_branch_idIn;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String nameIn) {
		this.name = nameIn;
	}

	public String getLocation() {
		return this.location;
	}

	public void setLocation(String locationIn) {
		this.location = locationIn;
	}

	public String getDescription() {
		return this.description;
	}

	public void setDescription(String descriptionIn) {
		this.description = descriptionIn;
	}

	public void setAll(int bank_branch_idIn, String nameIn, String locationIn,
			String descriptionIn) {
		this.bank_branch_id = bank_branch_idIn;
		this.name = nameIn;
		this.location = locationIn;
		this.description = descriptionIn;
	}

	public boolean hasEqualMapping(BankBranch valueObject) {

		if (valueObject.getBank_branch_id() != this.bank_branch_id) {
			return (false);
		}
		if (this.name == null) {
			if (valueObject.getName() != null)
				return (false);
		} else if (!this.name.equals(valueObject.getName())) {
			return (false);
		}
		if (this.location == null) {
			if (valueObject.getLocation() != null)
				return (false);
		} else if (!this.location.equals(valueObject.getLocation())) {
			return (false);
		}
		if (this.description == null) {
			if (valueObject.getDescription() != null)
				return (false);
		} else if (!this.description.equals(valueObject.getDescription())) {
			return (false);
		}

		return true;
	}

	public String toString() {
		StringBuffer out = new StringBuffer(this.getDaogenVersion());
		out.append("\nclass BankBranch, mapping to table bank_branch\n");
		out.append("Persistent attributes: \n");
		out.append("bank_branch_id = " + this.bank_branch_id + "\n");
		out.append("name = " + this.name + "\n");
		out.append("location = " + this.location + "\n");
		out.append("description = " + this.description + "\n");
		return out.toString();
	}

	public Object clone() {
		BankBranch cloned = new BankBranch();

		cloned.setBank_branch_id(this.bank_branch_id);
		if (this.name != null)
			cloned.setName(new String(this.name));
		if (this.location != null)
			cloned.setLocation(new String(this.location));
		if (this.description != null)
			cloned.setDescription(new String(this.description));
		return cloned;
	}

	public String getDaogenVersion() {
		return "DaoGen version 2.4.1";
	}

}