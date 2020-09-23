
<html>
<body bgcolor="lavender">
<center>

<jsp:useBean id="user" class="ib.User" scope="session" />

<%
 try
 {
     user.sendChequeBookRequest();
     out.println("<h4>Cheque Book Request Accepted. Your cheque book will be delivered to you within next 10 working days </h4>");
   
 }
 catch(Exception ex)
 {
    out.println("<h4>Error : " + ex.getMessage() + "</h4>");
  }
%>
<h4> Click <a href="home.jsp">here</a> to continue... </h4>
</center>
</body>
</html>
     
    
   
