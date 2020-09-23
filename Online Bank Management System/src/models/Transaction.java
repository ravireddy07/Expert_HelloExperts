package models;

import java.io.Serializable;
import java.sql.Timestamp;

public class Transaction implements Cloneable, Serializable {

	private int transaction_id;
	private int customer_id_by;
	private int account_id;
	private int account_id_to;
	private int transaction_type;
	private double transaction_amount;
	private Timestamp transaction_time;

	public Transaction() {

	}

	public Transaction(int transaction_idIn) {

		this.transaction_id = transaction_idIn;
	}

	public int getTransaction_id() {
		return this.transaction_id;
	}

	public void setTransaction_id(int transaction_idIn) {
		this.transaction_id = transaction_idIn;
	}

	public int getCustomer_id_by() {
		return this.customer_id_by;
	}

	public void setCustomer_id_by(int customer_id_byIn) {
		this.customer_id_by = customer_id_byIn;
	}

	public int getAccount_id() {
		return this.account_id;
	}

	public void setAccount_id(int account_idIn) {
		this.account_id = account_idIn;
	}

	public int getAccount_id_to() {
		return this.account_id_to;
	}

	public void setAccount_id_to(int account_id_toIn) {
		this.account_id_to = account_id_toIn;
	}

	public int getTransaction_type() {
		return this.transaction_type;
	}

	public void setTransaction_type(int transaction_typeIn) {
		this.transaction_type = transaction_typeIn;
	}

	public double getTransaction_amount() {
		return this.transaction_amount;
	}

	public void setTransaction_amount(double transaction_amountIn) {
		this.transaction_amount = transaction_amountIn;
	}

	public Timestamp getTransaction_time() {
		return this.transaction_time;
	}

	public void setTransaction_time(Timestamp transaction_timeIn) {
		this.transaction_time = transaction_timeIn;
	}

	/**
	 * setAll allows to set all persistent variables in one method call. This is
	 * useful, when all data is available and it is needed to set the initial
	 * state of this object. Note that this method will directly modify instance
	 * variales, without going trough the individual set-methods.
	 */

	public void setAll(int transaction_idIn, int customer_id_byIn,
			int account_idIn, int account_id_toIn, int transaction_typeIn,
			double transaction_amountIn, Timestamp transaction_timeIn) {
		this.transaction_id = transaction_idIn;
		this.customer_id_by = customer_id_byIn;
		this.account_id = account_idIn;
		this.account_id_to = account_id_toIn;
		this.transaction_type = transaction_typeIn;
		this.transaction_amount = transaction_amountIn;
		this.transaction_time = transaction_timeIn;
	}

	/**
	 * hasEqualMapping-method will compare two Transaction instances and return
	 * true if they contain same values in all persistent instance variables. If
	 * hasEqualMapping returns true, it does not mean the objects are the same
	 * instance. However it does mean that in that moment, they are mapped to
	 * the same row in database.
	 */
	public boolean hasEqualMapping(Transaction valueObject) {

		if (valueObject.getTransaction_id() != this.transaction_id) {
			return (false);
		}
		if (valueObject.getCustomer_id_by() != this.customer_id_by) {
			return (false);
		}
		if (valueObject.getAccount_id() != this.account_id) {
			return (false);
		}
		if (valueObject.getAccount_id_to() != this.account_id_to) {
			return (false);
		}
		if (valueObject.getTransaction_type() != this.transaction_type) {
			return (false);
		}
		if (valueObject.getTransaction_amount() != this.transaction_amount) {
			return (false);
		}
		if (this.transaction_time == null) {
			if (valueObject.getTransaction_time() != null)
				return (false);
		} else if (!this.transaction_time.equals(valueObject
				.getTransaction_time())) {
			return (false);
		}

		return true;
	}

	/**
	 * toString will return String object representing the state of this
	 * valueObject. This is useful during application development, and possibly
	 * when application is writing object states in textlog.
	 */
	public String toString() {
		StringBuffer out = new StringBuffer(this.getDaogenVersion());
		out.append("\nclass Transaction, mapping to table transaction\n");
		out.append("Persistent attributes: \n");
		out.append("transaction_id = " + this.transaction_id + "\n");
		out.append("customer_id_by = " + this.customer_id_by + "\n");
		out.append("account_id = " + this.account_id + "\n");
		out.append("account_id_to = " + this.account_id_to + "\n");
		out.append("transaction_type = " + this.transaction_type + "\n");
		out.append("transaction_amount = " + this.transaction_amount + "\n");
		out.append("transaction_time = " + this.transaction_time + "\n");
		return out.toString();
	}

	/**
	 * Clone will return identical deep copy of this valueObject. Note, that
	 * this method is different than the clone() which is defined in
	 * java.lang.Object. Here, the retuned cloned object will also have all its
	 * attributes cloned.
	 */
	public Object clone() {
		Transaction cloned = new Transaction();

		cloned.setTransaction_id(this.transaction_id);
		cloned.setCustomer_id_by(this.customer_id_by);
		cloned.setAccount_id(this.account_id);
		cloned.setAccount_id_to(this.account_id_to);
		cloned.setTransaction_type(this.transaction_type);
		cloned.setTransaction_amount(this.transaction_amount);
		if (this.transaction_time != null)
			cloned.setTransaction_time((Timestamp) this.transaction_time
					.clone());
		return cloned;
	}

	/**
	 * getDaogenVersion will return information about generator which created
	 * these sources.
	 */
	public String getDaogenVersion() {
		return "DaoGen version 2.4.1";
	}

}