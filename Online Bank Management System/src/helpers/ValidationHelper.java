package helpers;

import java.sql.Connection;
import java.sql.SQLException;

import utils.ChangesStatus;


import dao.AccountDAO;
import dao.DAOFactory;
import exceptions.NotFoundException;

public class ValidationHelper {

	public static boolean isValidUsername(String username) {

		return true;
	}

	public static boolean isValidPassword(String password) {

		return true;
	}

	public static ChangesStatus isValidAmount(String amount) {
		try {
			double amountD = Double.parseDouble(amount);
			if (amountD < 1) {
				return new ChangesStatus(false,
						"Amount should be greter than 0.");
			}
		} catch (NumberFormatException e) {
			return new ChangesStatus(false, "Amount is not a valid value.");
		}
		return new ChangesStatus(true, "");
	}

	public static ChangesStatus isValidAccountId(String account_id) {
		try {
			Connection connection = DBConnectionHelper.getConnection();
			AccountDAO accountDAO = DAOFactory.getAccountDAO();
			int account_idI = Integer.parseInt(account_id);

			accountDAO.getObject(connection, account_idI);

		} catch (NumberFormatException e) {
			return new ChangesStatus(false, "Account ID is not a valid value.");
		} catch (NotFoundException e) {
			e.printStackTrace();
			return new ChangesStatus(false,
					"Account ID doesn't exit. Transaction Cancled.");
		} catch (SQLException e) {
			e.printStackTrace();
			return new ChangesStatus(false, "DB Error.");

		}

		return new ChangesStatus(true, "");
	}

	public static ChangesStatus isValidSecurityPin(String pinIn) {

		try {
			if (pinIn.length() > 6 || pinIn.length() < 6) {
				return new ChangesStatus(false,
						"Security Pin is a 6 digit number.");
			}
			Integer.parseInt(pinIn);
			return new ChangesStatus(true, "");
		} catch (NumberFormatException e) {
			return new ChangesStatus(false,
					"Security Pin must be only numbers.");
		}
	}

}
