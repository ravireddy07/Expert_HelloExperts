
<html>
<body bgcolor="lavender">
<center>

<jsp:useBean id="user" class="ib.User" scope="session" />

<jsp:setProperty  name="user" property="*" />

<%
  if ( !user.isValid() )
%>
<h3>Invalid Login. Click <a href=login.html>here</a> to try again! </h3>
<%
  else
     response.sendRedirect("home.jsp"); 
%>

</center>
</body>
</html>
     
    
   
