<jsp:useBean id="user" class="ib.User" scope="session" />

<html>
<style>
h4 {color:red;font:700 14pt verdana}
td {font:11pt verdana}
a  {font:700 11pt verdana}
</style>

<script language="javascript">
function check()
{
   if ( f1.opwd.value == "" )
   {
     alert("You must enter old password!")
     f1.opwd.focus()
     return false
   }

   if ( f1.npwd.value == "" )
   {
     alert("You must enter new password!")
     f1.npwd.focus()
     return false
   }

   if ( f1.npwd.value != f1.npwd2.value)
   {
     alert("New password and confirm new password must match!")
     f1.npwd.focus()
     return false
   }

}

</script>
<body bgcolor="lavender">
<center>
<div style="color:lavender;background-color:purple;font:700 25pt arial;letter-spacing:5">
Update Profile
</div>

<form action=updateprofile.jsp method="post" name="f1" onsubmit="return check()">

<b>Note: </b> Fields with * are manadatory fields.
<p>
<table>
<tr>
<td>
Old Password 
<td>
<input type=password name=opwd size=20>*
</tr>
<tr>
<td>
New Password 
<td>
<input type=password name=npwd size=20>*
</tr>
<tr>
<td>
Confirm New Password
<td>
<input type=password name=npwd2 size=20>*
</tr>
</table>
<p>
<input type=submit value="Update">
<p>
<a href="home.jsp">Go Back To Menu </a>

</form>
<p>


<%

   // read data from form
   String opwd = request.getParameter("opwd");
   if ( opwd == null || opwd.trim().length() ==   0 )
      return;

   if (!opwd.equals(user.getPwd()) )
   {
     out.println("<h4>Sorry! Invalid Password. Try Again!</h4>");
     return;
   }
   

   String npwd= request.getParameter("npwd");
 
   user.setPwd(npwd);
   String msg = user.updatePassword();

   if ( msg == null)
     out.println("<h4>Password Changed Successfully!");
   else
     out.println("<h4>An Error Occured : " + msg);
     
%>

      

   