package business_controllers;

import helpers.DBConnectionHelper;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import utils.ChangesStatus;

import models.BankBranch;
import dao.BankBranchDAO;
import dao.DAOFactory;
import exceptions.NotFoundException;

public class BankBranchController {

	public List<BankBranch> getAllBankBranches() {
		Connection connection = DBConnectionHelper.getConnection();
		BankBranchDAO bankBranchDAO = DAOFactory.getBankBranchDAO();
		try {
			return bankBranchDAO.loadAll(connection);
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

	public BankBranch getBankBranch(int bank_branch_id) {
		BankBranch bankBranch = new BankBranch();
		BankBranchDAO bankBranchDAO = DAOFactory.getBankBranchDAO();
		
		Connection connection = DBConnectionHelper.getConnection();
		try {
			bankBranch = bankBranchDAO.getObject(connection, bank_branch_id);
			
			return bankBranch;
		} catch (NotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
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
	
	public ChangesStatus saveBankBranch(BankBranch bankBranch){
		
		BankBranchDAO bankBranchDAO = DAOFactory.getBankBranchDAO();
		
		Connection connection = DBConnectionHelper.getConnection();
		try {
			if(bankBranch.getBank_branch_id() > 0){
				bankBranchDAO.save(connection, bankBranch);
				connection.commit();
				return new ChangesStatus(true, "Bank Branch successfully saved.");
			} else {
				bankBranchDAO.create(connection, bankBranch);
				connection.commit();
				return new ChangesStatus(true, "Bank Branch successfully created.");
			}
		} catch (SQLException e) {
			e.printStackTrace();
			return new ChangesStatus(false, "Bank Branch can not be save.");
		} catch (NotFoundException e) {
			e.printStackTrace();
			return new ChangesStatus(false, "Bank Branch can not be save.");
		} finally {
			try {
				connection.close();
			} catch (SQLException e) {e.printStackTrace();}
		}
	}

}
