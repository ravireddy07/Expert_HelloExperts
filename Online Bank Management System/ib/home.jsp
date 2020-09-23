
<jsp:useBean id="user" class="ib.User" scope="session" />

<html>
<style>
td {font:10pt verdana}
a  {color:lavender}
</style>

<body bgcolor=lavender leftmargin=0 topmargin=0>

<table width=100% height=100% border=0>
<tr style="background-color:purple">
<td colspan=2>
<center>
<a href="http://www.howstuffworks.com"  target="_blank" alt="howstuffworks.com"><img src="hsw.gif" width=300 height=50></a>
<a href="http://www.theserverside.com"  target="_blank" alt="theserverside.com"><img src="logo.gif" width=300 height=50></a>
</td>
</tr>
<tr>
<td width=25% style="background-color:purple">

<a href="trans.jsp">Transactions Statement </a>
<p>
<a href="transfer.html">Transfer Of Funds </a>
<p>
<a href="chequebook.html">Request for Chequebook </a>
<p>
<a href="cancelcheque.jsp">Cancel A Cheque </a>
<p>
<a href="updateprofile.jsp">Update Profile </a>
<p>
<a href="sendmail.html">Mail To Accounts Manager </a>
<p>
<a href="logout.jsp">Logout </a>
</td>

<td>

<table cellpadding=5 style="font:700 12pt verdana">
<tr>
<td>Your Account No : <td> <jsp:getProperty  name="user" property="acno" />
</tr>
<tr>
<td>Current Balance : <td> <%= user.getBalance()%>
</tr>
</table>

</td>
</tr>

</table>


