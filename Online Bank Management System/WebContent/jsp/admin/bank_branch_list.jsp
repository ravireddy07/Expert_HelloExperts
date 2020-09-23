<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<h3>Bank Branch List</h3>

<table class="table">
	<thead>
		<th>ID</th>
		<th>Name</th>
		<th>Location</th>
		<th>Description</th>
		<th></th>
	</thead>
	<tbody>
		<c:forEach items="${data}" var="bank_branch">
			<tr>
				<td>${bank_branch.bank_branch_id}</td>
				<td>${bank_branch.name}</td>
				<td>${bank_branch.location}</td>
				<td>${bank_branch.description}</td>
				<td><a class="btn btn-small" style="width: 50px;"
					href="${page.url_host}${page.url_apppath}admin/bank_branch/edit/${bank_branch.bank_branch_id}">Edit</a>
				</td>
			</tr>
		</c:forEach>
	</tbody>
</table>