<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<div id="dashboard">
	<div class="row">
		<a href="${page.url_host}${page.url_apppath}bank_account/show_balance"
			class="span4""> <object width="80px" height="80px"
				data="${page.url_assets}images/show_balance.svg"
				type="image/svg+xml"></object> <span class="dlink"><br />Details</span>
		</a> <a
			href="${page.url_host}${page.url_apppath}bank_account/deposit_fund"
			class="span4"> <object width="80px" height="80px"
				data="${page.url_assets}images/deposit_money.svg"
				type="image/svg+xml"></object> <span class="dlink"><br />Deposit</span>
		</a> <a
			href="${page.url_host}${page.url_apppath}bank_account/withdraw_fund"
			class="span4"> <object width="80px" height="80px"
				data="${page.url_assets}images/withdraw_money.svg"
				type="image/svg+xml"></object> <span class="dlink"><br />Withdraw</span>
		</a>
	</div>
	<div class="row">
		<a
			href="${page.url_host}${page.url_apppath}bank_account/transfer_fund"
			class="span4"> <object width="80px" height="80px"
				data="${page.url_assets}images/transfer_money.svg"
				type="image/svg+xml"></object> <span class="dlink"><br />Transfer
				Cash</span>
		</a> <a
			href="${page.url_host}${page.url_apppath}bank_account/transfer_history"
			class="span4"> <object width="80px" height="80px"
				data="${page.url_assets}images/transaction_history.svg"
				type="image/svg+xml"></object> <span class="dlink"><br />Transaction
				History</span>
		</a> <a href="${page.url_host}${page.url_apppath}profile" class="span4">
			<c:choose>
				<c:when test="${customer.gender != 'Male'}">
					<object width="80px" height="80px"
						data="${page.url_assets}images/customer_female.svg"
						type="image/svg+xml"></object>
				</c:when>
				<c:otherwise>
					<object width="80px" height="80px"
						data="${page.url_assets}images/customer_male.svg"
						type="image/svg+xml"></object>
				</c:otherwise>
			</c:choose> <span class="dlink"><br />My Information</span>
		</a>

	</div>
</div>