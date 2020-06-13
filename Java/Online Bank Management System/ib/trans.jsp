
<%@ page import="java.sql.*"%>

<jsp:useBean id="user" class="ib.User" scope="session"/>

<html>
<style>
td {font:10pt verdana}
</style>

<body bgcolor="lavender">
<center>
<div style="color:lavender;background-color:purple;font:700 25pt arial;letter-spacing:5">
Transaction Statement
</div>

<form action=trans.jsp method="post">
<table>
<tr>
<td>
From Date  
<td> 
<input type=text name=fromdate size=10>(dd-mon-yy)
To 
<input type=text name=todate size=10>(dd-mon-yy)
</tr>

<tr>
<td>
Amount Staring From 
<td> 
<input type=text name=startamount size=10>
To 
<input type=text name=endamount size=10>
</tr>

<tr>
<td>
Description Contains
<td> 
<input type=text name=desc size=30>
</tr>

</table>

<input type=submit value="Get Transactions">
<input type=reset value="Clear">
&nbsp;
<a href="home.jsp">Go Back To Menu </a>
</form>
<p>
<%
   // get parameter values
   String fromdate = request.getParameter("fromdate");

   if ( fromdate == null)    
          return;

   String todate = request.getParameter("todate");
   String startamount = request.getParameter("startamount");
   String endamount= request.getParameter("endamount");
   String desc= request.getParameter("desc");

   String query;

   query = " acno ='" + user.getAcno() + "'";

   if ( fromdate.length() > 0)
      query += " and tdate >= '" + fromdate + "'";
   
   if ( todate.length() > 0)
      query += " and tdate <= '" + todate + "'";

   if ( startamount.length() > 0)
      query += " and tamt >= " + startamount;
   
   if ( endamount.length() > 0)
      query += " and tamt <=" +  endamount;

   if ( desc.length() > 0 )
      query += " and tdesc like '%" + desc + "%'";
   
   Connection con = user.getConnection();

   Statement st = con.createStatement();
   ResultSet rs= st.executeQuery( " select tno, to_char(tdate) tdate, tdesc, cno,to_char(tamt,'99,99,999.00') tamt,ttype from trans where " + query);

%>
<table border=1 cellpadding=3>
<tr style="background-color:purple;color:lavender">
<th>Tran. NO
<th>Tran. Date
<th>Description
<th>Cheque No.
<th>Deposit
<th>WidthDrawal
</tr>

<%
   while (rs.next())
   {
%>
<tr>
<td>
<%= rs.getString("tno") %>
<td>
<%=rs.getString("tdate") %>
<td>
<%=rs.getString("tdesc") %>
<td>
<%
   String cno = rs.getString("cno");
   if ( rs.wasNull())
     out.println( "&nbsp;");
   else
     out.println(cno);

%>

<td>
<%
   String ttype = rs.getString("ttype");
   if ( ttype.equals("d"))
        out.println( rs.getString("tamt"));
   else
        out.println("&nbsp;");
%>
<td>

<%
   if ( ttype.equals("w"))
        out.println( rs.getString("tamt"));
   else
        out.println("&nbsp;");
   
%>  
</tr>

<%
    } // end of while 

    rs.close();
    st.close();
    con.close();
%>
  
</table>

</body>
</html>




