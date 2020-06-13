package helpers;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.StringTokenizer;

import javax.servlet.http.HttpServletRequest;

import models.Account;
import models.BankBranch;
import models.Customer;
import models.MapAccountCustomer;
import configs.SysConfigs;
import dao.CustomerDAO;
import dao.DAOFactory;
import exceptions.NotFoundException;

public class HttpHelper {

	public synchronized static HashMap<String, String> analyseRequest(
			HttpServletRequest request) {

		HashMap<String, String> uris = new HashMap<String, String>();

		String fullUri = request.getRequestURI();
		String appPath = SysConfigs.url_AppPath;
		String realUri = fullUri.replace(appPath, "");

		StringTokenizer st = new StringTokenizer(realUri, "/");

		for (int i = 1; i <= 4; i++) {
			String _s;
			_s = (st.hasMoreTokens()) ? st.nextToken() : "";
			uris.put("uri_" + i, _s.trim());
		}

		String type = request.getParameter("type");
		type = (type == null) ? "html" : type;
		uris.put("type", type);

		return uris;
	}

	public synchronized static boolean isGET(HttpServletRequest request) {
		if (request.getMethod().toString().equals("GET")) {
			return true;
		}
		return false;
	}

	public synchronized static boolean isPOST(HttpServletRequest request) {
		if (request.getMethod().toString().equals("POST")) {
			return true;
		}
		return false;
	}

	public synchronized static Customer sanatizeRequestedCustomerModel(
			HttpServletRequest request) {

		Customer customer = new Customer();
		
		if (request.getParameter("customer_id") != "") {
			customer.setCustomer_id(Integer.parseInt(request
					.getParameter("customer_id")));
			
			CustomerDAO customerDAO = DAOFactory.getCustomerDAO();
			Connection connection = DBConnectionHelper.getConnection();
			
			try {
				Customer oldCustomerData = customerDAO.getObject(connection, Integer.parseInt(request.getParameter("customer_id")));
				customer.setDate_of_join(oldCustomerData.getDate_of_join());
			} catch (NumberFormatException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (NotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			 
		}

		customer.setNric(request.getParameter("nric"));
		customer.setUsername(request.getParameter("username"));
		customer.setPassword(AuthenticationHelper.encryptPassword(request
				.getParameter("password")));
		customer.setGivenname(request.getParameter("givenname"));
		customer.setAddress(request.getParameter("address"));
		customer.setGender(request.getParameter("gender"));
		customer.setNationality(request.getParameter("nationality"));

		SimpleDateFormat datetimeFormatter1 = new SimpleDateFormat("mm/dd/yyyy");
		try {
			Date lFromDate1 = datetimeFormatter1.parse(request
					.getParameter("date_of_birth"));
			Timestamp fromTS1 = new Timestamp(lFromDate1.getTime());
			customer.setDate_of_birth(fromTS1);
		} catch (ParseException e) {
			e.printStackTrace();
		}

		if (!(customer.getCustomer_id() > 0)) {
			customer.setDate_of_join(new Timestamp(System.currentTimeMillis()));
		}

		return customer;
	}

	public synchronized static Account sanatizeRequestedAccountModel(
			HttpServletRequest request) {

		Account account = new Account();

		if (!(request.getParameter("account_id").equals(""))) {
			account.setAccount_id(Integer.parseInt(request
					.getParameter("account_id")));
		}

		account.setPin(Integer.parseInt(request.getParameter("pin")));
		account.setAmount(Double.parseDouble(request.getParameter("amount")));
		account.setAccount_type(Integer.parseInt(request
				.getParameter("account_type")));
		account.setBank_branch_id(Integer.parseInt(request
				.getParameter("bank_branch_id")));
		return account;
	}

	public synchronized static ArrayList<MapAccountCustomer> sanatizeRequestedMapAccountCustomerModel(
			HttpServletRequest request) {

		ArrayList<MapAccountCustomer> mapAccountCustomerList = new ArrayList<MapAccountCustomer>();
		if(request.getParameterValues("customer_ids") != null){
			String[] customer_ids = request.getParameterValues("customer_ids");
			
			for (int i = 0; i < customer_ids.length; i++) {
				if (!(customer_ids[i].equals(""))) {
					MapAccountCustomer mapAccountCustomer = new MapAccountCustomer();
					mapAccountCustomer.setCustomer_id(Integer
							.parseInt(customer_ids[i]));
					mapAccountCustomerList.add(mapAccountCustomer);
				}
		}
		
			/*
			 * if(request.getParameter("account_id") != null){//TODO:move to out
			 * of loop
			 * mapAccountCustomer.setAccount_id(Integer.parseInt(request.
			 * getParameter("account_id"))); }
			 */
		}

		return mapAccountCustomerList;
	}

	public synchronized static BankBranch sanatizeRequestedBankBranchModel(
			HttpServletRequest request) {

		BankBranch bank_branch = new BankBranch();

		if (request.getParameter("bank_branch_id") != "") {
			bank_branch.setBank_branch_id(Integer.parseInt(request
					.getParameter("bank_branch_id")));// TODO:2
		}

		bank_branch.setName(request.getParameter("name"));
		bank_branch.setLocation(request.getParameter("location"));
		bank_branch.setDescription(request.getParameter("description"));

		return bank_branch;
	}

}
