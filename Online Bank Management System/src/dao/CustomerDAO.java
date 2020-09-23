package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;
import models.Customer;
import exceptions.NotFoundException;

public interface CustomerDAO{
	public Customer createValueObject();
    public Customer getObject(Connection conn, int customer_id) throws NotFoundException, SQLException;
    public void load(Connection conn, Customer valueObject) throws NotFoundException, SQLException;
    public List loadAll(Connection conn) throws SQLException;
    public void create(Connection conn, Customer valueObject) throws SQLException;
    public void save(Connection conn, Customer valueObject) throws NotFoundException, SQLException;
    public void delete(Connection conn, Customer valueObject) throws NotFoundException, SQLException;
    public void deleteAll(Connection conn) throws SQLException;
    public int countAll(Connection conn) throws SQLException;
    public List searchMatching(Connection conn, Customer valueObject) throws SQLException;
    public int databaseUpdate(Connection conn, PreparedStatement stmt) throws SQLException;
    public void singleQuery(Connection conn, PreparedStatement stmt, Customer valueObject) throws NotFoundException, SQLException;
    public List listQuery(Connection conn, PreparedStatement stmt) throws SQLException;
}

