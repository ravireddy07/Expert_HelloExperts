<%@ page import="javax.naming.*,java.util.*,ib.account.*,javax.rmi.*"%>
<html>
<body bgcolor="lavender">
<center>

<jsp:useBean id="user" class="ib.User" scope="session" />

<%

 try
 {
  String tacno = request.getParameter("tacno");
  String tamt = request.getParameter("tamt");

/*  String JNDI_FACTORY="weblogic.jndi.WLInitialContextFactory";
  Hashtable env = new Hashtable();
  env.put(Context.INITIAL_CONTEXT_FACTORY, JNDI_FACTORY);
  env.put(Context.PROVIDER_URL,"t3://localhost:7001");

  Context ctx = new InitialContext(env);

  AccountHome home = (AccountHome) PortableRemoteObject.narrow(homeobj, AccountHome.class);
  Account obj =  home.findByPrimaryKey(user.getAcno());   
  obj.transfer(tacno,Double.parseDouble(tamt));

*/
  user.transferAmount( tacno,Double.parseDouble(tamt)); 
  out.println("Transfer of funds is successful! ");
 } 
 catch(Exception ex)
 {
  out.println("An Error Occurred During Transfer Of Funds : " + ex.getMessage());
 }


%>



<h4> Click <a href="home.jsp">here</a> to continue... </h4>
</center>
</body>
</html>
     
    
   
