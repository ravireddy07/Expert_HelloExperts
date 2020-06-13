<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<h3>
	Detail Information of ${data.givenname} &nbsp;&nbsp;&nbsp;<a
		href="${page.url_host}${page.url_apppath}admin/customer/edit/${data.customer_id}"
		style="margin-top: 15px;" class="pull-right btn btn-small btn-info">Edit
		Details</a>
</h3>

<table class="table">
	<tr>
		<td>Customer ID</td>
		<td>${data.customer_id}</td>
	</tr>
	<tr>
		<td>NRIC Number</td>
		<td>${data.nric}</td>
	</tr>
	<tr>
		<td>Username</td>
		<td>${data.username}</td>
	</tr>
	<tr>
		<td>Given Name</td>
		<td>${data.givenname}</td>
	</tr>
	<tr>
		<td>Address</td>
		<td>${data.address}</td>
	</tr>
	<tr>
		<td>Gender</td>
		<td>${data.gender}</td>
	</tr>
	<tr>
		<td>Nationality</td>
		<td>${data.nationality}
	</tr>
	<tr>
		<td>Date of Birth</td>
		<td>
		<fmt:formatDate value="${data.date_of_birth}" pattern="MM/d/yyyy" />
		</td>
	</tr>
	<tr>
		<td>Date of Join</td>
		<td><fmt:formatDate value="${data.date_of_join}" pattern="MM/d/yyyy" /></td>
	</tr>
</table>
<c:if test="${not empty data.accounts}">
	<h3>Bank Accounts Owned by Customer</h3>
	<table class="table table-hover">
		<thead>
			<tr>
				<td>Account ID</td>
				<td>Balance</td>
				<td>Account Type</td>
				<td>Ownership</td>
				<td></td>
			</tr>
		</thead>
		<tbody>
			<c:forEach items="${data.accounts}" var="_account">
				<tr>
					<td>${_account.account_id}</td>
					<td><fmt:formatNumber value="${_account.amount}" type="currency"/></td>
					<td><c:choose>
							<c:when test="${_account.account_type == 1 }">Checking Account </c:when>
							<c:when test="${_account.account_type == 2 }">Saving Account </c:when>
							<c:otherwise> Undefined </c:otherwise>
						</c:choose></td>
					<td><c:choose>
							<c:when test="${_account.joint_account == false }">Single Account</c:when>
							<c:otherwise> Joint Account </c:otherwise>
						</c:choose> <c:if test="${_account.joint_account == true }">
							<br />
							<u>Owners</u>
							<ul>
								<c:forEach items="${_account.customers}" var="_customer">
									<li><a
										href="${page.url_host}${page.url_apppath}admin/customer/details/${_customer.customer_id}">${_customer.givenname}</a></li>
								</c:forEach>
							</ul>
						</c:if></td>
					<td><a
						href="${page.url_host}${page.url_apppath}admin/account/details/${_account.account_id}"
						class="btn btn-small">View Details</a></td>
				</tr>
			</c:forEach>
		</tbody>
	</table>
</c:if>
