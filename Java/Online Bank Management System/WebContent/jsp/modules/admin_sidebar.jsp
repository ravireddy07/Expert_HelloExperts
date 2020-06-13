<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<aside id="side_bar" class="span5">
	<ul id="admin_menu">
		<li><a class="btn btn-primary btn-large"
			href="${page.url_host}${page.url_apppath}admin/customer/list">Customer
				List</a></li>
		<li><a class="btn btn-primary btn-large"
			href="${page.url_host}${page.url_apppath}admin/customer/search">Search
				Customer</a></li>
		<li><a class="btn btn-primary btn-large"
			href="${page.url_host}${page.url_apppath}admin/account/search">Search
				Account</a></li>
		<li><a class="btn btn-primary btn-large"
			href="${page.url_host}${page.url_apppath}admin/bank_branch/list">Bank
				Branch List</a></li>
	</ul>
</aside>