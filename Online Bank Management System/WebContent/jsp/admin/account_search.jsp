<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<h3>Search Bank Account</h3>
<hr />
<form
	action="${page.url_host}${page.url_apppath}admin/post/search_account"
	method="post" name="form-account" class="form-search">
	<input type="text" autocomplete="off" name="account_id" class="input-medium search-query"
		placeholder="Bank Account ID" style="width: 250px" /> &nbsp;&nbsp;
	<button type="submit" class="btn btn-primary">Search</button>
</form>