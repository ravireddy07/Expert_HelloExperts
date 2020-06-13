package exceptions;

public class NoPermissionException extends TransactionAbortedException {
	public NoPermissionException(String msg) {
		super(msg);
	}

}
