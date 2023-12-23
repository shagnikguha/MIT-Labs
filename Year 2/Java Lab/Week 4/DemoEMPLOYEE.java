import java.util.*;
class EMPLOYEE{
	String Ename;
	int Eid;
	int basic;
	EMPLOYEE(){
		Ename = "NULL";
		Eid = 0;
		basic = 0;
	}
	EMPLOYEE(String n, int id, int b){
		Ename = n;
		Eid = id;
		basic = b;
	}
	void display(){
		System.out.println("Name: " + Ename);
		System.out.println("ID: " + Eid);
		System.out.println("Basic: "+ basic);
		double gross = 1.52*(double)basic;
		double net = 0.7*gross;
		System.out.println("Net: " + net);
	}
}
class DemoEMPLOYEE{
	public static void main(String args[]){
		System.out.println("Enter n: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		EMPLOYEE e[] = new EMPLOYEE[n];
		for(int i=0; i<n; i++){
			//sc.nextLine();
			System.out.println("Enter Details:");
			System.out.println("Name: ");
			String name = sc.next();
			sc.nextLine();
			System.out.println("ID:");
			int id = sc.nextInt();
			System.out.println("Basic:");
			int basic = sc.nextInt();
			e[i] = new EMPLOYEE(name, id, basic);
		}
		for(EMPLOYEE ep:e){
			ep.display();
		}
		System.out.println("Default is");
		EMPLOYEE d = new EMPLOYEE();
		d.display();
		sc.close();
	}
}


