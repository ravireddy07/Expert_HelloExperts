<%
  
  // terminate session
  session.invalidate();
  response.sendRedirect("login.html");
%>
