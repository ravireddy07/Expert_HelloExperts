<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>



<form name="form-customer" id="form-customer"
	action="${page.url_host}${page.url_apppath}admin/post/save_bank_branch"
	method="post">
	<table class="table">
		<tr>
			<td>Branch ID</td>
			<td><input type="text" disabled="disabled"
				value="<c:if test="${data.bank_branch_id > 0}">${data.bank_branch_id}</c:if>" />
				<input name="bank_branch_id" type="hidden"
				value="<c:if test="${data.bank_branch_id > 0}">${data.bank_branch_id}</c:if>" />
			</td>
		</tr>
		<tr>
			<td>Branch Name</td>
			<td><input value="${data.name}" name="name" type="text" autocomplete="off"
				required="required" placeholder="Branch Name" /></td>
		</tr>
		<tr>
			<td>Branch Location</td>
			<td><textarea name="location" type="textarea" autocomplete="off"
					required="required" placeholder="Description">${data.location}</textarea></td>
		</tr>
		<tr>
			<td>Description</td>
			<td><textarea name="description" type="textarea"
					required="required" placeholder="Description">${data.description}</textarea></td>
		</tr>
		<tr>
			<td><a class="btn btn-primary btn-large"
				href="${page.url_host}${page.url_apppath}admin/bank_branch/list">Cancel</a></td>
			<td><input class="btn btn-primary btn-large" type="submit"
				value="Submit" /></td>
		</tr>
	</table>
</form>