// User Bean

package  ib;
import java.sql.*;
import javax.jms.QueueConnectionFactory;
import javax.jms.QueueConnection;
import javax.jms.QueueSession;
import javax.jms.QueueSender;
import javax.jms.Session;
import javax.jms.TextMessage;
import javax.jms.Queue;
import java.util.*;
import javax.naming.*;
import javax.rmi.*;
import ib.account.*;


public class User
{
    private  String acno;
    private  String uname;
    private  String pwd;
    private  String email;

    private  Context ctx;

    public User() 
    {
      ctx = getInitialContext();
    }

    public  void setAcno (String acno)
    { this.acno = acno; }
    public String getAcno()
    {  return acno; }


    public  void setUname (String uname)
    { this.uname = uname; }

    public String getUname()
    {  return uname; }

    public  void setPwd (String pwd)
    { this.pwd = pwd; }

    public String getPwd()
    {  return pwd; }

    public  void setEmail (String email)
    { this.email = email; }

    public String getEmail()
    {  return email; }

    // returns true if uname and pwd are valid
   //  copies email and acno into properties
    public  boolean isValid()
    {
     Connection con = null;
     PreparedStatement ps = null;
     try
    {
      con = getConnection();
      ps = con.prepareStatement("select acno, email from users where uname = ? and pwd = ?");
      ps.setString(1,uname);
      ps.setString(2,pwd);

      ResultSet rs = ps.executeQuery();
      boolean found = false;

      if ( rs.next())
     {    acno = rs.getString(1);
           email = rs.getString(2);
           found = true;
     }
     return found;
  }
  catch(Exception ex)
  {
      System.out.println( ex.getMessage());
      return false;
   }
   finally
  {
       clean(con,ps);
  } 

 } // end of isValid

 public String updatePassword() 
 {
   Connection con = null;
   PreparedStatement ps= null;

   try
   {
     con = getConnection();
     ps = con.prepareStatement("update users set pwd = ? where uname = ?");
     ps.setString(1,pwd);
     ps.setString(2,uname);

     int cnt = ps.executeUpdate();
     if ( cnt==1 ) 
        return null;
     else
        return "Invalid Username!";
      
  }
  catch(Exception ex)
  {
      System.out.println( ex.getMessage());
      return ex.getMessage();
  }
  finally
  {
       clean(con,ps);
  } 

 } // end of updatePassword

 // send a message to chequebooks message queue
 public void sendChequeBookRequest() throws Exception
 {
    String JMS_FACTORY="weblogic.examples.jms.QueueConnectionFactory";
    String QUEUE="chequebook";

    QueueConnectionFactory qconFactory = (QueueConnectionFactory) ctx.lookup(JMS_FACTORY);
    QueueConnection qcon = qconFactory.createQueueConnection();
    qcon.start();

    QueueSession qsession = qcon.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
    Queue queue = (Queue) ctx.lookup(QUEUE);
    QueueSender qsender = qsession.createSender(queue);

    TextMessage msg = qsession.createTextMessage();
    msg.setText(acno);
    qsender.send(msg);

    qsender.close();
    qsession.close();
    qcon.close();

 } // end of sendChequeBookRequest


 // send a message to cancel cheque
 public void cancelCheque(String cno) throws Exception
 {
    String JMS_FACTORY="weblogic.examples.jms.QueueConnectionFactory";
    String QUEUE="cancelcheque";

    QueueConnectionFactory qconFactory = (QueueConnectionFactory) ctx.lookup(JMS_FACTORY);
    QueueConnection qcon = qconFactory.createQueueConnection();
    qcon.start();

    QueueSession qsession = qcon.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
    Queue queue = (Queue) ctx.lookup(QUEUE);
    QueueSender qsender = qsession.createSender(queue);

    TextMessage msg = qsession.createTextMessage();
    msg.setText(acno + "," + cno);
    qsender.send(msg);

    qsender.close();
    qsession.close();
    qcon.close();

 } // end of cancelCheque


 public  void clean(Connection con, PreparedStatement ps)
 { 
   try
   { if ( ps != null )  ps.close();
     if ( con != null) con.close();
    }
    catch(Exception ex)
    { System.out.println(ex.getMessage()); }
 }

 public Connection getConnection() throws Exception
 {
   Class.forName("oracle.jdbc.driver.OracleDriver"); 
   // connect using Thin driver
   Connection con =   DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:oracle8i",
		"ib","ib");

   return con;
 }    

 public void transferAmount(String tacno, double amount) throws Exception
 {

   Object homeobj = ctx.lookup("ib.account");
   AccountHome home = (AccountHome) PortableRemoteObject.narrow(homeobj, AccountHome.class);
   Account obj =  home.findByPrimaryKey(acno);   
   obj.transfer(tacno, amount);

 } // end of transferAmount 


 public double getBalance() throws Exception
 {
  Object homeobj = ctx.lookup("ib.account");
  AccountHome home = (AccountHome) PortableRemoteObject.narrow(homeobj, AccountHome.class);
  Account obj;
  obj = home.findByPrimaryKey(acno);   
  return obj.balance();
 }

 public Context getInitialContext() 
 {
  
  String JNDI_FACTORY="weblogic.jndi.WLInitialContextFactory";

  try
  {
   Hashtable env = new Hashtable();
   env.put(Context.INITIAL_CONTEXT_FACTORY, JNDI_FACTORY);
   env.put(Context.PROVIDER_URL,"t3://localhost:7001");
   return new InitialContext(env);
  }
  catch(Exception ex)
  { 
    System.out.println(ex.getMessage()); 
    return null;
  }

 }
  

} // end of bean
  
       
    
   




