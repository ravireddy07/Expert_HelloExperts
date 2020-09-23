<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<header id="header">
	<a href="${page.url_host}${page.url_apppath}">
		<table id="title-holder">
			<tr>
				<td>
					<div id="bank-logo">
						<object width="75px" height="64px"
							data="${page.url_assets}images/building.svg" type="image/svg+xml"></object>
					</div>
				</td>
				<td><h2>Bank of Team 6A</h2></td>
			</tr>
		</table>
		<div id="signout-area">
			<table id="title-holder">
				<tr>
					<td><c:choose>
							<c:when test="${customer.gender != 'Male'}">
								<object width="20px" height="20px"
									data="${page.url_assets}images/customer_female.svg"
									type="image/svg+xml"></object>
							</c:when>
							<c:otherwise>
								<object width="20px" height="20px"
									data="${page.url_assets}images/customer_male.svg"
									type="image/svg+xml"></object>
							</c:otherwise>
						</c:choose></td>
					<td><b><a
							href="${page.url_host}${page.url_apppath}profile">&nbsp;${customer.givenname}</a></b></td>

					<td>&nbsp;&nbsp;</td>

					<td><object width="20px" height="20px"
							data="${page.url_assets}images/power_button.svg"
							type="image/svg+xml"></object></td>
					<td><a
						href="${page.url_host}${page.url_apppath}session/logout"><b>
								&nbsp;[Logout]</b></a></td>

				</tr>
			</table>
		</div>
	</a>
</header>