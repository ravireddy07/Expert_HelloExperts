package utils;

import java.sql.Timestamp;

public class TransactionHistoryOfAnAccount implements Comparable<TransactionHistoryOfAnAccount>{
	
	private int account_id;
	private int transaction_type; // 1 or 2 or 3
	private double transaction_amount;
	private Timestamp transaction_time;
	private int transaction_relation_type; //1Sent , 2Receive 
	private int transaction_relation_account_id;
	
	public int getAccount_id() {
		return account_id;
	}
	public void setAccount_id(int account_id) {
		this.account_id = account_id;
	}
	public int getTransaction_type() {
		return transaction_type;
	}
	public void setTransaction_type(int transaction_type) {
		this.transaction_type = transaction_type;
	}
	public double getTransaction_amount() {
		return transaction_amount;
	}
	public void setTransaction_amount(double transaction_amount) {
		this.transaction_amount = transaction_amount;
	}
	public Timestamp getTransaction_time() {
		return transaction_time;
	}
	public void setTransaction_time(Timestamp transaction_time) {
		this.transaction_time = transaction_time;
	}
	public int getTransaction_relation_type() {
		return transaction_relation_type;
	}
	public void setTransaction_relation_type(int transaction_relation_type) {
		this.transaction_relation_type = transaction_relation_type;
	}
	public int getTransaction_relation_account_id() {
		return transaction_relation_account_id;
	}
	public void setTransaction_relation_account_id(
			int transaction_relation_account_id) {
		this.transaction_relation_account_id = transaction_relation_account_id;
	}
	@Override
	public int compareTo(TransactionHistoryOfAnAccount o) {
		
		return 0;
	}
	
	

}
