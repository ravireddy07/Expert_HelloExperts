package ib.account;

import javax.ejb.CreateException;
import javax.ejb.EJBHome;
import javax.ejb.FinderException;
import java.rmi.RemoteException;
import java.util.Collection;


public interface AccountHome extends EJBHome {


  public Account create() throws CreateException, RemoteException;

  public Account findByPrimaryKey(String primaryKey) 
    throws FinderException, RemoteException;
       
}
