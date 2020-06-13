<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<div id="dashboard">
	<div class="row">
		<a href="${page.url_host}${page.url_apppath}admin/customer/new"
			class="span4""> <img class="img-circle"
			src="${page.url_assets}images/user_add.png" style="width: 120px;" />
			<br />
		<h5>New Customer Account</h5>
		</a> <a href="${page.url_host}${page.url_apppath}admin/customer/search"
			class="span4""> <img class="img-circle"
			src="${page.url_assets}images/user_search.png" style="width: 120px;" />
			<br />
		<h5>Search Customer Account</h5>
		</a>
	</div>
	<div class="row">
		<a href="${page.url_host}${page.url_apppath}admin/account/new"
			class="span4"> <img src="${page.url_assets}images/new_file.png"
			style="width: 80px;" /> <br />
		<h5>New Bank Account</h5>
		</a> <a href="${page.url_host}${page.url_apppath}admin/account/search"
			class="span4"> <img src="${page.url_assets}images/search.png"
			style="width: 80px;" /> <br />
		<h5>Search Bank Account</h5>
		</a>

	</div>
</div>