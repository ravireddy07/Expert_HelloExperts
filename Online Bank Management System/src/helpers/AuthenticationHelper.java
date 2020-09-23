package helpers;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import models.Customer;
import dao.CustomerDAOImpl;

public class AuthenticationHelper {

	public synchronized static int isValidLogin(HttpServletRequest request) {
		String loginid = request.getParameter("loginid");
		String password = request.getParameter("password");

		Connection connection = DBConnectionHelper.getConnection();

		try {

			CustomerDAOImpl customerDAO = new CustomerDAOImpl();
			Customer customer = new Customer();
			customer.setUsername(loginid);
			customer.setPassword(MD5(SHA1(password)));

			List<Customer> rows = customerDAO.searchMatching(connection,
					customer);

			if (rows.size() == 1) {
				for (Customer c : rows) {
					return c.getCustomer_id();
				}
			} else {
				return 0;
			}
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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

		return 0;
	}

	public static synchronized String encryptPassword(String rawPassword) {
		try {
			return MD5(SHA1(rawPassword));
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	private static synchronized String SHA1(String input)
			throws NoSuchAlgorithmException {
		MessageDigest mDigest = MessageDigest.getInstance("SHA1");
		byte[] result = mDigest.digest(input.getBytes());
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < result.length; i++) {
			sb.append(Integer.toString((result[i] & 0xff) + 0x100, 16)
					.substring(1));
		}
		return sb.toString();
	}

	private static synchronized String MD5(String input)
			throws NoSuchAlgorithmException {
		String md5 = null;
		MessageDigest digest = MessageDigest.getInstance("MD5");
		digest.update(input.getBytes(), 0, input.length());
		md5 = new BigInteger(1, digest.digest()).toString(16);
		return md5;
	}

}
