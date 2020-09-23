<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<header class="navbar" id="header">
	<div class="navbar-inner">
		<div style="width: auto;" class="container">
			<a data-target=".nav-collapse" data-toggle="collapse"
				class="btn btn-navbar"> <span class="icon-bar"></span> <span
				class="icon-bar"></span> <span class="icon-bar"></span>
			</a> <a href="#" class="brand">Bank of Team 6A</a>
			<div class="nav-collapse">
				<ul class="nav">
					<li><a
						href="${page.url_host}${page.url_apppath}admin/dashboard">Dashboard</a></li>
					<li class="dropdown"><a data-toggle="dropdown"
						class="dropdown-toggle" href="#">Customer <b class="caret"></b></a>
						<ul class="dropdown-menu">
							<li><a
								href="${page.url_host}${page.url_apppath}admin/customer/list">Customer
									List</a></li>
							<li><a
								href="${page.url_host}${page.url_apppath}admin/customer/new">Create
									New Customer</a></li>
							<li><a
								href="${page.url_host}${page.url_apppath}admin/customer/search">Search
									Customer</a></li>
						</ul></li>
					<li class="dropdown"><a data-toggle="dropdown"
						class="dropdown-toggle" href="#">Banking Account<b
							class="caret"></b></a>
						<ul class="dropdown-menu">
							<li><a
								href="${page.url_host}${page.url_apppath}admin/account/new">Create
									New Account</a></li>
							<li><a
								href="${page.url_host}${page.url_apppath}admin/account/search">Search
									Account</a></li>
						</ul></li>
					<li class="dropdown"><a data-toggle="dropdown"
						class="dropdown-toggle" href="#">Bank Branch<b class="caret"></b></a>
						<ul class="dropdown-menu">
							<li><a
								href="${page.url_host}${page.url_apppath}admin/bank_branch/list">Bank
									Branch List</a></li>
							<li><a
								href="${page.url_host}${page.url_apppath}admin/bank_branch/new">Add
									New Bank Branch</a></li>
						</ul></li>
				</ul>
				<ul class="nav pull-right">
					<form
						action="${page.url_host}${page.url_apppath}admin/post/search_account"
						method="post" class="navbar-search pull-left">
						<input name="account_id" type="text"
							placeholder="Search Bank Account" style="width: 200px;"
							class="search-query span2">
					</form>
					<li class="divider-vertical"></li>
					<li class="dropdown"><a data-toggle="dropdown"
						class="dropdown-toggle" href="#">Administrator <b
							class="caret"></b></a>
						<ul class="dropdown-menu">
							<li><a href="#">Settings</a></li>
							<li class="divider"></li>
							<li><a href="#">Logout</a></li>
						</ul></li>
				</ul>
			</div>
			<!-- /.nav-collapse -->
		</div>
	</div>
	<!-- /navbar-inner -->
</header>