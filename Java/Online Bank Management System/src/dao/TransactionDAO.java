package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;

import models.Transaction;
import exceptions.NotFoundException;
public interface TransactionDAO {
	public Transaction createValueObject();
	public Transaction getObject(Connection conn, int transaction_id) throws NotFoundException, SQLException;
	public void load(Connection conn, Transaction valueObject) throws NotFoundException, SQLException;
	public List loadAll(Connection conn) throws SQLException;
    public void create(Connection conn, Transaction valueObject) throws SQLException;
    public void save(Connection conn, Transaction valueObject) throws NotFoundException, SQLException;
    public void delete(Connection conn, Transaction valueObject) throws NotFoundException, SQLException;
    public void deleteAll(Connection conn) throws SQLException;
    public int countAll(Connection conn) throws SQLException;
    public List searchMatching(Connection conn, Transaction valueObject) throws SQLException;
    public int databaseUpdate(Connection conn, PreparedStatement stmt) throws SQLException;
    public void singleQuery(Connection conn, PreparedStatement stmt, Transaction valueObject) throws NotFoundException, SQLException;
    public List listQuery(Connection conn, PreparedStatement stmt) throws SQLException;
}

