<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<table class="table table-hover">
	<thead>
		<th>Customer ID</th>
		<th>Name / Username</th>
		<th>NRIC</th>
		<th></th>
	</thead>
	<tbody>
		<c:forEach items="${data}" var="customer">
			<tr>
				<td>${customer.customer_id}</td>
				<td><b style="font-size: 18px;">${customer.givenname}</b><br />
					<span class="list-username">${customer.username}</span></td>
				<td>${customer.nric}</td>
				<td><a class="btn btn-small"
					style="width: 50px; margin-bottom: 5px;"
					href="${page.url_host}${page.url_apppath}admin/customer/edit/${customer.customer_id}">Edit</a><br />
					<a class="btn btn-small" style="width: 50px;"
					href="${page.url_host}${page.url_apppath}admin/customer/details/${customer.customer_id}">Details</a>
				</td>
			</tr>
		</c:forEach>
	</tbody>
</table>