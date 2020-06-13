<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<div id="breadcrumb">&nbsp;&nbsp;</div>
<div id="message-area">
	<c:forEach items="${message_queue}" var="message">
		<div class="alert alert-${message.type}">
			<c:out value="${message.message}" />
		</div>
	</c:forEach>
</div>