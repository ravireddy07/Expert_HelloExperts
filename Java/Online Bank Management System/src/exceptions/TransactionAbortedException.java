package exceptions;

public class TransactionAbortedException extends Exception {

	public TransactionAbortedException(String msg) {
		super(msg);
	}

}
