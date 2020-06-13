package helpers;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import configs.SysConfigs;

public class DBConnectionHelper {

	public synchronized static Connection getConnection() {
		return getMySQLConnection();
	}

	public synchronized static Connection getMySQLConnection() {
		Connection dbConnection;

		try {
			Class.forName(SysConfigs.db_Driver);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		try {
			dbConnection = DriverManager.getConnection(
					SysConfigs.db_ConnectionString, SysConfigs.db_Username,
					SysConfigs.db_Password);
			dbConnection.setAutoCommit(false);

			return dbConnection;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
}
