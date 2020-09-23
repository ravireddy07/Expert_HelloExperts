package dao;

public class DAOFactory {
	
	private DAOFactory(){}
	
	public static AccountDAO getAccountDAO(){
		return new AccountDAOImpl();
	}
	
	public static BankBranchDAO getBankBranchDAO(){
		return new BankBranchDAOImpl();
	}
	
	public static CustomerDAO getCustomerDAO(){
		return new CustomerDAOImpl();
	}
	
	public static MapAccountCustomerDAO getMapAccountCustomerDAO(){
		return new MapAccountCustomerDAOImpl();
	}
	
	public static TransactionDAO getTransactionDAO(){
		return new TransactionDAOImpl();
	}
}
