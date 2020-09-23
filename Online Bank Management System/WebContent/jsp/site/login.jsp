<%@ page language="java" contentType="text/html; charset=US-ASCII"
	pageEncoding="US-ASCII"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>


<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=US-ASCII">

<title><c:out value="${page.page_title}" /></title>


<link href="${page.url_assets}css/bootstrap.min.css" rel="stylesheet"
	media="screen" />
<link href="${page.url_assets}css/application_site_login.css"
	rel="stylesheet" media="screen" />

<script src="${page.url_assets}js/bootstrap.min.js"></script>
<script src="${page.url_assets}js/application_site.js"></script>
</head>

<body id="body-login">
	<div>

		<form id="form-signin" name="input"
			action="${page.url_host}${page.url_apppath}login" method="post">

			<div id="form-signin-header-container">
				<object width="48px" height="48px"
					data="${page.url_assets}images/bank_atm.svg" type="image/svg+xml"></object>
				<h2 id="form-signin-heading">Bank of Team 6A (SA-36)</h2>
			</div>

			<div id="message-area">
				<c:forEach items="${message_queue}" var="message">
					<div class="alert alert-${message.type}">
						<c:out value="${message.message}" />
					</div>
				</c:forEach>
			</div>

			<input name="loginid" type="text" required="required" autocomplete="off"
				class="input-block-level" placeholder="Username"> <input autocomplete="off"
				name="password" type="password" required="required"
				class="input-block-level" placeholder="Password"> <label
				class="checkbox"> <input type="checkbox" value="remember-me">Remember
				me
			</label>
			<button class="btn btn-large btn-primary" type="submit">Sign
				in</button>

		</form>

		<footer id="footer">
		<ul>
			<li><span class="icon-book"></span><a href="#">Privacy
					Policy</a></li>
			<li><span class="icon-flag"></span><a href="#">Terms &
					Conditions</a></li>
			<li>&copy; Copyright Team 6(A) | NUS, ISS SA(36)</li>
		</ul>
		</footer>

	</div>
</body>
</html>