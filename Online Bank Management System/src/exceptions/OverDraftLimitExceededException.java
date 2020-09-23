package exceptions;

public class OverDraftLimitExceededException extends ExceedLimitException {

	public OverDraftLimitExceededException(String msg) {
		super(msg);
	}
}
