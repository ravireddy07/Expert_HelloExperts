package dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;

import models.BankBranch;
import exceptions.NotFoundException;

public interface BankBranchDAO {
    public BankBranch createValueObject();
    public BankBranch getObject(Connection conn, int bank_branch_id) throws NotFoundException, SQLException;
    public void load(Connection conn, BankBranch valueObject) throws NotFoundException, SQLException;
    public List loadAll(Connection conn) throws SQLException;
    public void create(Connection conn, BankBranch valueObject) throws SQLException;
    public void save(Connection conn, BankBranch valueObject) throws NotFoundException, SQLException;
    public void delete(Connection conn, BankBranch valueObject) throws NotFoundException, SQLException;
    public void deleteAll(Connection conn) throws SQLException;
    public int countAll(Connection conn) throws SQLException;
    public List searchMatching(Connection conn, BankBranch valueObject) throws SQLException;
    public int databaseUpdate(Connection conn, PreparedStatement stmt) throws SQLException;
    public void singleQuery(Connection conn, PreparedStatement stmt, BankBranch valueObject) throws NotFoundException, SQLException;
    public List listQuery(Connection conn, PreparedStatement stmt) throws SQLException;
}

