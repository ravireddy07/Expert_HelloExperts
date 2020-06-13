package exceptions;

public class ExceedLimitException extends TransactionAbortedException {

	public ExceedLimitException(String msg) {
		super(msg);
	}
}
