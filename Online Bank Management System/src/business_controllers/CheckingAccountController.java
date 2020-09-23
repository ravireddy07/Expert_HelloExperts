package business_controllers;

import helpers.DBConnectionHelper;
import helpers.PermissionHelper;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.Date;

import utils.ChangesStatus;

import models.Account;
import models.Transaction;
import configs.BusinessRules;
import dao.AccountDAO;
import dao.DAOFactory;
import dao.TransactionDAO;
import exceptions.BelowMinimumBalanceException;
import exceptions.NotFoundException;
import exceptions.OverDraftLimitExceededException;

public class CheckingAccountController extends AccountController{
	
	public ChangesStatus withdrawMoney(int account_id, int customer_id_by, int amount, int pin) 
			throws BelowMinimumBalanceException, OverDraftLimitExceededException{
		
		Connection connection = DBConnectionHelper.getConnection();
		AccountDAO accountDAO = DAOFactory.getAccountDAO();
		
		try {
			Account account = accountDAO.getObject(connection, account_id);
			
			//Checking Security Pin
			if( !(account.getPin() == pin)){
				return new ChangesStatus(false, "Security Pin do not match! Transaction Canceled.");
			}
			//Checking Permission
			if( !(PermissionHelper.isThisAccountOwnByThisCustomer(account_id, customer_id_by))){
				return new ChangesStatus(false, "You do not own this account. Transaction Canceled.");
			}
			
			double newAmount = account.getAmount() - amount;
			
			if(newAmount < BusinessRules.CHECKING_ACCOUNT_OVER_DRAFT_LIMIT){
				throw new OverDraftLimitExceededException("Overdraw Limit Exceed");
			}
			
			account.setAmount(newAmount);
			
			accountDAO.save(connection, account);
			
			Transaction transaction = new Transaction();
			transaction.setCustomer_id_by(customer_id_by);
			transaction.setAccount_id(account_id);
			transaction.setTransaction_amount(amount);
			transaction.setTransaction_type(2);
			
			Date date = new Date();
			transaction.setTransaction_time(new Timestamp(date.getTime()));
			TransactionDAO transactionDAO = DAOFactory.getTransactionDAO();
			transactionDAO.create(connection, transaction);
			//If exception found roll back in catch block
			connection.commit();
			
			return new ChangesStatus(true, "Successfully Withdrawed" + amount);
			
		} catch (NotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			try {
				e.printStackTrace();
				connection.rollback();
				return new ChangesStatus(false, "Rolledbacked. Transaction Unsuccessful.");
			} catch (SQLException e1) {
				e1.printStackTrace();
				return new ChangesStatus(false, "Unsuccessful Rolledback.");
			}
		} finally {
			try {
				connection.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return null;
	}

	public ChangesStatus transferMoney(int account_id_from, int account_id_to, int customer_id_by, int amount) throws OverDraftLimitExceededException {
		
		Connection connection = DBConnectionHelper.getConnection();
		AccountDAO accountDAO = DAOFactory.getAccountDAO();
		
		try {
			Account account_1 = accountDAO.getObject(connection, account_id_from);
			
			double newAmount_1 = (account_1.getAmount() - amount);
			if(newAmount_1 < BusinessRules.CHECKING_ACCOUNT_OVER_DRAFT_LIMIT){
				throw new OverDraftLimitExceededException("Overdraw Limit Exceed");
			}
			
			account_1.setAmount(newAmount_1);
			accountDAO.save(connection, account_1);
			
			Account account_2 = accountDAO.getObject(connection, account_id_to);
			
			double newAmount_2 = (account_2.getAmount() + amount);
			account_2.setAmount(newAmount_2);
			accountDAO.save(connection, account_2);
			
			Transaction transaction = new Transaction();
			transaction.setCustomer_id_by(customer_id_by);
			transaction.setAccount_id(account_id_from);
			transaction.setAccount_id_to(account_id_to);
			transaction.setTransaction_amount(amount);
			transaction.setTransaction_type(3);
			
			Date date = new Date();
			transaction.setTransaction_time(new Timestamp(date.getTime()));
			TransactionDAO transactionDAO = DAOFactory.getTransactionDAO();
			transactionDAO.create(connection, transaction);
			//If exception found roll back in catch block
			connection.commit();
			
			return new ChangesStatus(true, "Successfully Transfered " + amount);
			
			
		} catch (NotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			
		} catch (SQLException e) {
			e.printStackTrace();
			try {
				connection.rollback();
				return new ChangesStatus(false, "Rolledbacked. Transaction Unsuccessful.");
			} catch (SQLException e1) {
				e1.printStackTrace();
				return new ChangesStatus(false, "Unsuccessful Rolledback.");
			}
		} finally {
			try {
				connection.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}		
		return null;
	}

}
