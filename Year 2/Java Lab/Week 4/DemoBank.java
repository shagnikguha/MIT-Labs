import java.util.*;
class Bank{
	String name;
	int Acc_num;
	String type;
	double balance;
	static int ROI = 6;
	Bank(){
		name = "NULL";
		Acc_num = 0;
		balance = 0;
	}
	Bank(String n, int a, String t, double d){
		name = n;
		Acc_num = a;
		type = t;
		balance = d;
	}
	void deposit(double a){
		if(a>0){
			System.out.println(a + " has been added to " + Acc_num);
			balance +=a;
		} else{
			System.out.println("Enter valid amount");
		}
	}
	void withdraw(double req){
		double min = 10000;
		if(balance-req>min){
			System.out.println(req + " money deducted");
			balance -= req;
		} else{
			System.out.println("Withdraw failed");
		}
	}
	void display(){
		System.out.println("Details of " + Acc_num);
		System.out.println("Name: " + name);
		System.out.println("Type: " + type);
		System.out.println("Balance: " + balance);
	}
	static void display_ROI(){
		System.out.println("ROI is: " + ROI);
	}
}

class DemoBank{
	public static void main(String args[]){
		Bank B1 = new Bank();
		System.out.println("Default: " );
		B1.display();
		Bank B2 = new Bank("Shagnik", 1234, "D-Mat", 1000000);
		B2.withdraw(12000);
		B2.deposit(13500);
		B2.display();
		Bank.display_ROI();
	}
}



