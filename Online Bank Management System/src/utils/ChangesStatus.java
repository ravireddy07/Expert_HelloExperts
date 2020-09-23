package utils;

public class ChangesStatus {
	
	private boolean status;
	private String message;
	
	public ChangesStatus(){
		
	}
	
	public ChangesStatus(boolean status, String message) {
		this.status = status;
		this.message = message;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
	
	public void setMessage(String message) {
		this.message = message;
	}
	
	public String getMessage() {
		return message;
	}
	
	public boolean getStatus(){
		return status;
	}
	
	
	

}
