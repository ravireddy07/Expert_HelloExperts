<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<script type="text/javascript">
	
	$(document).ready(function(){
		$("#addRowBtn").click(function(){
			$("#newowners").append('<input type="text" name="customer_ids" autocomplete="off" placeholder="Customer ID" /><br />');
		});
	});
	
</script>

<c:choose>
	<c:when test="${data.account_id > 0 }">
		<h3>
			Edit : Account ID
			<c:if test="${data.account_id > 0}">${data.account_id}</c:if>
			<a
				href="${page.url_host}${page.url_apppath}admin/account/details/${data.account_id}"
				class="btn btn-small btn-info pull-right" style="margin-top: 15px;">
				View Details of this Account</a>
		</h3>
	</c:when>
	<c:otherwise>
		<h3>New Account</h3>
	</c:otherwise>
</c:choose>

<form name="form-customer" id="form-customer"
	action="${page.url_host}${page.url_apppath}admin/post/save_account"
	method="post">
	<table class="table">
		<tr>
			<td>Account ID</td>
			<td><input type="text" disabled="disabled"
				value="<c:if test="${data.account_id > 0}">${data.account_id}</c:if>" />
				<input type="hidden" name="account_id"
				value="<c:if test="${data.account_id > 0}">${data.account_id}</c:if>" />
			</td>
		</tr>
		<tr>
			<td>Ownership</td>
			<td><c:forEach items="${data.customers}" var="_customer">
					<input disabled="disabled" type="text" style="width: 80px"
						value="${_customer.customer_id}" /> &nbsp;${_customer.givenname} (ID : ${_customer.customer_id})
				<input name="customer_ids" type="hidden"
						value="${_customer.customer_id}" /><br />
				</c:forEach>
				<div id="newowners">
				
				</div>
				<input type="button" id="addRowBtn" value="Add Owner" class="btn btn-small btn-info" />  
			</td>
		</tr>
		<tr>
			<td>Security PIN</td>
			<td><input
				value="<c:if test="${data.pin != 0}">${data.pin}</c:if>" name="pin" autocomplete="off"
				type="text" placeholder="Security Pin" /></td>
		</tr>
		<tr>
			<td>Amount</td>
			<td><input
				value="<c:if test="${data.amount != ''}">${data.amount}</c:if>"
				name="amount" type="text" placeholder="Amount" autocomplete="off" /></td>
		</tr>
		<tr>
			<td>Account Type</td>
			<td><select name="account_type" placeholder="Account Type">
					<option value="">- Select One -</option>
					<option
						<c:if test="${data.account_type == 1}">selected="selected"</c:if>
						value="1">Checking Account</option>
					<option
						<c:if test="${data.account_type == 2}">selected="selected"</c:if>
						value="2">Saving Account</option>
			</select></td>
		</tr>
		<tr>
			<td>Bank Branch</td>
			<td><input name="bank_branch_id" type="text"
				value="<c:if test="${data.bank_branch_id > 0}">${data.bank_branch_id}</c:if>"
				placeholder="Bank Branch ID" /></td>
		</tr>
		<tr>
			<td><a class="btn btn-primary btn-large"
				href="${page.url_host}${page.url_apppath}admin/dashboard">Cancel</a></td>
			<td><input class="btn btn-primary btn-large" type="submit"
				value="Submit" /></td>
		</tr>
	</table>
</form>