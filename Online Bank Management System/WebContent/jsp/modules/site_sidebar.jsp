<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<fmt:setBundle basename="en"></fmt:setBundle>
<aside id="sidebar" class="span4">
	<div class="btn-group">
		<a class="btn dropdown-toggle btn-large btn-inverse"
			data-toggle="dropdown" href="#"> <c:choose>
				<c:when test="${account_id != null}"> <fmt:message key="switch_account"></fmt:message></c:when>
				<c:otherwise><fmt:message key="choose_account"></fmt:message></c:otherwise>
			</c:choose> <span class="caret"></span>
		</a>
		<ul class="dropdown-menu">
			<c:forEach items="${customer.accounts}" var="_account">
				<li><a
					href="${page.url_host}${page.url_apppath}session/account/${_account.account_id}">
						ID : ${_account.account_id} <c:choose>
							<c:when test="${_account.account_type == 1 }"> - Checking Account </c:when>
							<c:when test="${_account.account_type == 2 }"> - Saving Account </c:when>
							<c:otherwise> Undefined </c:otherwise>
						</c:choose>
				</a></li>
			</c:forEach>
		</ul>
	</div>

	<c:if test="${account != null }">
		<div id="account_summary">
			<h5>&nbsp; Current Account Summary</h5>
			<table class="table">
				<tr>
					<td>Account ID</td>
					<td>: ${account.account_id}</td>
				</tr>
				<tr>
					<td>Amount</td>
					<td>: <fmt:formatNumber value="${account.amount}" type="currency"/></td>
				</tr>
				<tr>
					<td>Type</td>
					<td><c:choose>
							<c:when test="${account.account_type == 1 }">: Checking Account </c:when>
							<c:when test="${account.account_type == 2 }">: Saving Account </c:when>
							<c:otherwise> Undefined </c:otherwise>
						</c:choose></td>
				</tr>
			</table>
		</div>
	</c:if>


	<div id='cssmenu'>
		<ul>
			<li class='active'><a
				href='${page.url_host}${page.url_apppath}bank_account/show_balance'>
					<table>
						<tr>
							<td><object width="25px" height="25px"
									data="${page.url_assets}images/show_balance.svg"
									type="image/svg+xml"></object></td>
							<td><span class="menu_link">Account Details</span></td>
						</tr>
					</table>
			</a></li>
			<li><a
				href='${page.url_host}${page.url_apppath}bank_account/deposit_fund'>
					<table>
						<tr>
							<td><object width="25px" height="25px"
									data="${page.url_assets}images/deposit_money.svg"
									type="image/svg+xml"></object></td>
							<td><span class="menu_link">Deposit Cash</span></td>
						</tr>
					</table>
			</a></li>
			<li><a
				href='${page.url_host}${page.url_apppath}bank_account/withdraw_fund'>
					<table>
						<tr>
							<td><object width="25px" height="25px"
									data="${page.url_assets}images/withdraw_money.svg"
									type="image/svg+xml"></object></td>
							<td><span class="menu_link">Withdraw Cash</span></td>
						</tr>
					</table>
			</a></li>
			<li><a
				href='${page.url_host}${page.url_apppath}bank_account/transfer_fund'>
					<table>
						<tr>
							<td><object width="25px" height="25px"
									data="${page.url_assets}images/transfer_money.svg"
									type="image/svg+xml"></object></td>
							<td><span class="menu_link">Transfer Money</span></td>
						</tr>
					</table>
			</a></li>
			<li class='last'><a
				href='${page.url_host}${page.url_apppath}bank_account/transfer_history'>
					<table>
						<tr>
							<td><object width="25px" height="25px"
									data="${page.url_assets}images/transaction_history.svg"
									type="image/svg+xml"></object></td>
							<td><span class="menu_link">Transaction History</span></td>
						</tr>
					</table>
			</a></li>
		</ul>
	</div>

</aside>