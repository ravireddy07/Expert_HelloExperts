<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<table class="table table-hover">
	<thead>
		<tr>
			<td>Bank Account ID</td>
			<td>Available Balance</td>
			<td>Account Type</td>
			<td></td>
		</tr>
	</thead>
	<tbody>
		<c:forEach items="${customer.accounts}" var="_account">
			<tr>
				<td>${_account.account_id}</td>
				<td><fmt:formatNumber value="${_account.amount}" type="currency"/></td>
				<td><c:choose>
						<c:when test="${_account.account_type == 1 }">Checking Account </c:when>
						<c:when test="${_account.account_type == 2 }">Saving Account </c:when>
						<c:otherwise> Undefined </c:otherwise>
					</c:choose></td>
				<td><a class="btn btn-success"
					href="${page.url_host}${page.url_apppath}session/account/${_account.account_id}">Select</a></td>
			</tr>
		</c:forEach>
	</tbody>
</table>