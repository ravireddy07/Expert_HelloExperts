package exceptions;

public class BelowMinimumBalanceException extends ExceedLimitException {

	public BelowMinimumBalanceException(String msg) {
		super(msg);
	}
}
