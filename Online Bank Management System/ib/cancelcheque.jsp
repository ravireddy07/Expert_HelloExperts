<%@ page import="java.sql.*"%>

<jsp:useBean id="user" class="ib.User"  scope="session" />

<html>
<style>
h4 {color:red;font:700 14pt verdana}
td {font:11pt verdana}
a  {font:700 11pt verdana}
</style>


<body bgcolor="lavender">
<center>
<div style="color:lavender;background-color:purple;font:700 25pt arial;letter-spacing:5">
Cancellation of Cheque
</div>

<form action=cancelcheque.jsp method="post">
Enter cheque number : 
<input type=text name=cno size=20>
<p>
<input type=submit value="Cancel Cheque">
<p>
<a href="home.jsp">Go Back To Menu </a>

</form>

<%

 String cno = request.getParameter("cno");
 if ( cno == null || cno.length() == 0)
    return;

 Connection  con =null;
 PreparedStatement ps =null;
 try
 {
 // connect to database
 con = user.getConnection();

 // find out whether the cheque is already processed 
 ps = con.prepareStatement("select tdate from trans where acno = ? and cno = ? and ttype = 'w'");

 ps.setString(1,user.getAcno());
 ps.setString(2, cno);

 ResultSet rs = ps.executeQuery();
 if ( rs.next())
    out.println("Sorry! Cheque [" + cno + "] was already processed on " + rs.getString(1));
 else
 {
   // send message to CANCELCHEQUE message queue with format  acno,cheque no
   user.cancelCheque(cno);
   out.println("Request for cheque cancellation has been accepted");
 }

 rs.close();
 }
 catch(Exception ex)
 {
   out.println("Error :" + ex.getMessage());
 }
 finally
 {
  try
  {
   ps.close();
   con.close();
  }
  catch(Exception ex) {}
 }


%>

Click <a href=home.jsp>here</a>  to continue ...
</body>
</html>   