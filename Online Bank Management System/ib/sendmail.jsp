
<%@ page import="java.util.*,java.io.*,javax.mail.*,javax.mail.internet.*"%>
<jsp:useBean id="user" class="ib.User" scope="session"/>

<%

     String to = "accmanager@bank.com";

     // create some properties and get the default Session
     Properties props = System.getProperties();
     Session msession = Session.getDefaultInstance(props,null);

     try {
	    // create a message
	    Message msg = new MimeMessage(msession);
	    msg.setFrom(new InternetAddress( user.getEmail()) );
	    msg.setRecipient(Message.RecipientType.TO, new InternetAddress(to));
	    msg.setSubject( request.getParameter("subject"));
	    msg.setSentDate(new Date());
	    msg.setText( request.getParameter("body"));
	    Transport.send(msg);
	    out.println("Mail has been sent to Accounts Manager.");
	}
	catch (MessagingException mex)
	{
	    out.println("Error " + mex.getMessage());
	}
	 
%>

<h4>Click <a href="home.jsp">here</a> To Continue...</h4> 