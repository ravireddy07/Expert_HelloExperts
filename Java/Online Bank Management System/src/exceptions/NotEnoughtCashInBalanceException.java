package exceptions;

public class NotEnoughtCashInBalanceException extends
		TransactionAbortedException {
	public NotEnoughtCashInBalanceException(String msg) {
		super(msg);
	}
}
