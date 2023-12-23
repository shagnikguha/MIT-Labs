import java.util.*;

class apply{
	synchronized void mul(int n){
		for(int i=1;i<10;i++){
			System.out.println(" " + (i*n));
		}
	}
}

class NewThread extends Thread{
	int Number;
	apply obj;
	NewThread(apply n, int num){
		obj = n;
		Number = num;
		start();
	}
	public void run(){
		try{
			obj.mul(Number);
			Thread.sleep(2000);
		} 
		catch(InterruptedException exp){
			System.out.println(exp);
		}
	}
}

class Tables{
	public static void main(String[] args) {
		apply o1 = new apply();
		apply o2 = new apply();
		NewThread obj1 = new NewThread(o1, 5);
        NewThread obj2 = new NewThread(o2, 7);
	}
} 
