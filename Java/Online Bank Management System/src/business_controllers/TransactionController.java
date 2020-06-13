package business_controllers;

import helpers.DBConnectionHelper;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import utils.TransactionHistoryOfAnAccount;

import models.Transaction;
import dao.DAOFactory;
import dao.TransactionDAO;

public class TransactionController {

	public TransactionController() {
	}

	public List<TransactionHistoryOfAnAccount> getAllTransactionsOfAAccount(
			int account_id) {

		Connection connection = DBConnectionHelper.getConnection();
		TransactionDAO transactionDAO = DAOFactory.getTransactionDAO();

		List<TransactionHistoryOfAnAccount> histories = new ArrayList<TransactionHistoryOfAnAccount>();
		try {

			Transaction _transaction1 = new Transaction();
			// Retrieving Deposit and Withdraw and Transaction(SENT)
			_transaction1.setAccount_id(account_id);
			List<Transaction> _transactionList = transactionDAO.searchMatching(
					connection, _transaction1);
			for (Transaction t : _transactionList) {
				TransactionHistoryOfAnAccount _tH = new TransactionHistoryOfAnAccount();
				_tH.setAccount_id(account_id);
				_tH.setTransaction_type(t.getTransaction_type());
				_tH.setTransaction_amount(t.getTransaction_amount());
				_tH.setTransaction_time(t.getTransaction_time());
				// For Transaction(SENT)
				if (t.getTransaction_type() == 3) {
					_tH.setTransaction_relation_type(1);
					_tH.setTransaction_relation_account_id(t.getAccount_id_to());
				}
				// add to list
				histories.add(_tH);
			}

			Transaction _transaction2 = new Transaction();
			// Transaction(RECEIVE)
			_transaction2.setAccount_id_to(account_id);
			List<Transaction> _transactionListTo = transactionDAO
					.searchMatching(connection, _transaction2);
			for (Transaction t : _transactionListTo) {
				TransactionHistoryOfAnAccount _tH = new TransactionHistoryOfAnAccount();
				_tH.setAccount_id(account_id);
				_tH.setTransaction_type(t.getTransaction_type());
				_tH.setTransaction_amount(t.getTransaction_amount());
				_tH.setTransaction_time(t.getTransaction_time());
				_tH.setTransaction_relation_type(2);
				_tH.setTransaction_relation_account_id(t.getAccount_id());

				// add to list
				histories.add(_tH);
			}
			return histories;

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
