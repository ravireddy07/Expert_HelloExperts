package ib.account;

import java.io.Serializable;
import java.util.Enumeration;
import java.util.Vector;
import javax.naming.Context;
import javax.naming.InitialContext;

import javax.ejb.CreateException;
import javax.ejb.DuplicateKeyException;
import javax.ejb.EJBException;
import javax.ejb.EntityBean;
import javax.ejb.EntityContext;
import javax.ejb.FinderException;
import javax.ejb.NoSuchEntityException;
import javax.ejb.ObjectNotFoundException;
import javax.ejb.RemoveException;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;
import java.sql.*;
import ib.account.*;


abstract public class AccountBean implements EntityBean 
{

  private EntityContext ctx;
  public AccountBean() {};

  public void setEntityContext(EntityContext ctx) { this.ctx = ctx;}
  public void unsetEntityContext() { this.ctx = null;}


  // container managed fields
  abstract public String getAccno();
  abstract public void setAccno(String val);

  abstract public double getBalance();
  abstract public void setBalance(double val);

  abstract public String getAccountType();
  abstract public void setAccountType(String val);


  public void ejbActivate() { }
  public void ejbPassivate() { }

  public void ejbLoad() { }

  public void ejbStore() { }
  public void ejbRemove() throws RemoveException {}

  public String ejbCreate() throws CreateException  
  {
     return null;
  }

  public void ejbPostCreate() {}

  public double deposit(double amount)
  {
    setBalance(getBalance() + amount);
    return getBalance();
  }

  public void transfer(String acno,double amount)
  {
    Connection con =null;
    PreparedStatement ps= null;

    try
    {
     withdraw(amount);  // withdraw from current account
     AccountHome  ah  = (AccountHome) ctx.getEJBHome();
     Account tacno = ah.findByPrimaryKey(acno);
     tacno.deposit(amount);  // deposit into target account

     // insert two rows into Trans Table
     con = getConnection();
     ps= con.prepareStatement("insert into trans values(sqtrans.nextval,?,?,sysdate,?,?,null)" );
 
     ps.setString(1,getAccno());
     ps.setString(2,"w");
     ps.setDouble(3,amount);
     ps.setString(4,"Transfered To A/C No. " + acno);
    
     if ( ps.executeUpdate() == 0)
           throw new EJBException("Unable to insert into Trans table");

     // trans about deposit into target account
     ps.setString(1,acno);
     ps.setString(2,"d");
     ps.setDouble(3,amount);
     ps.setString(4,"Transfered From A/C No. " + getAccno());
    
     if ( ps.executeUpdate() == 0)
           throw new EJBException("Unable to insert into Trans table");
    
    }
    catch(Exception ex)
    {
      throw new EJBException(ex.getMessage());
    }
    finally
    {
      try
      {
       if (  ps != null) ps.close();
       if (  con != null)  con.close(); 
      }
      catch(Exception ex)
      {  
       System.out.println(ex.getMessage()); 
       throw new EJBException(ex.getMessage());
      }
           
    }

  }    
   


  public double withdraw(double amount) throws FundsException
  {
      // get min balance
      int minbal = 5000;

      if ( getAccountType().equals("s") )
             minbal = 1000;

      if (amount > (getBalance()-minbal) ) 
      {
         throw new FundsException
           ("Request to withdraw Rs." + amount + "; is more than the amount that can be withdrawn, which is Rs." + getBalance() +" in account " + getAccno());
      }
      setBalance(getBalance() - amount);
      return getBalance();
  }


  public double balance()
  {
    return getBalance();
  }

  public String accountType() { return getAccountType();}

  public Connection getConnection() throws Exception
  {
     Context ctx = new InitialContext();
     DataSource ds = (DataSource) ctx.lookup("oracle");
     return ds.getConnection();
  }
     



}











