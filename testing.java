import java.util.*;

abstract class MobileOS {
	protected abstract void DoStart();
	public void start() {
		DoStart();
	}
}
class IOS extends MobileOS {
	public void DoStart() {
		System.out.println("This from IOS DoStart");
	}
}

class Android  extends MobileOS {
	public void DoStart() {
		System.out.println("This from Android DoStart");
	}
}

class mainclass {
    public static void main(String args[]) {
		Android a = new Android();
		//MobileOS b = new Android();
		//MobileOS c = new IOS();
		a.start();
		a.DoStart();
		//b.start();
		//c.start();
    }  
}