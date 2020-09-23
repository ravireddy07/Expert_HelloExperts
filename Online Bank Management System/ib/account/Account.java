package ib.account;

import java.rmi.RemoteException;
import javax.ejb.*;


public interface Account extends EJBObject {


  public double deposit(double amount) throws RemoteException;
  public double withdraw(double amount) throws FundsException, RemoteException;
  public double balance() throws RemoteException;
  public String accountType() throws RemoteException;
  public void transfer(String acno, double amount) throws RemoteException,FundsException;

}
