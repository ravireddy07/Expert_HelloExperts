<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<table class="table .table-condensed">
	<thead>
		<h4>Account Summary</h4>
	</thead>
	<tr>
		<td>Bank Account ID</td>
		<td>${account.account_id}</td>
	</tr>
	<tr>
		<td>Balance</td>
		<td><fmt:formatNumber value="${account.amount}" type="currency"/></td>
	</tr>
	<tr>
		<td>Account Type</td>
		<td><c:choose>
				<c:when test="${account.account_type == 1 }">Checking Account </c:when>
				<c:when test="${account.account_type == 2 }">Saving Account </c:when>
				<c:otherwise> Undefined </c:otherwise>
			</c:choose></td>
	</tr>
</table>

<div class="center-holder">

	<form id="form-withdraw" name="form-withdraw" class="center-box"
		action="${page.url_host}${page.url_apppath}post/withdraw"
		method="post">
		<h4>Withdraw</h4>
		<table>
			<tr>
				<td style="width: 150px;"><label>Amount to Withdraw</label></td>
				<td style="width: 250px;"><input name="withdraw_amount" autocomplete="off"
					type="text" class="input-block-level" required="required"
					placeholder="Withdraw Amount"></td>
			</tr>
			<tr>
				<td><label>Security Pin</label></td>
				<td><input name="pin" type="text" autocomplete="off"
					required="required" class="input-block-level"
					placeholder="Security Pin" /></td>
			</tr>
			<tr>
				<td></td>
				<td><button class="btn btn-info btn-primary"
						style="float: right;" type="submit">Withdraw</button></td>
			</tr>
		</table>
	</form>
</div>