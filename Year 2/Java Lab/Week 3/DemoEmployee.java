import java.util.*;
class Employee{
	String Ename;
	int Eid;
	int Basic;
	void read()
	{
		Scanner sc = new Scanner(System.in);
		String Ename = new String();
		System.out.println("Enter name: ");
		Ename = sc.nextLine();
		int Eid, Basic;	
		System.out.println("Enter Id: ");
		Eid = sc.nextInt();
		System.out.println("Enter basic: ");
		Basic = sc.nextInt();
		this.Ename = Ename;
		this.Basic = Basic;
		this.Eid = Eid;
	}

	void display(){
		System.out.println("Name: " + this.Ename);
		System.out.println("Id: " + this.Eid);
		System.out.println("Basic: " + this.Basic);
	}
	void compute_net_sal(){
		double gross = 1.52*+(this.Basic);
		double net = 0.7 * gross;
		System.out.println("Net salary: " + net);
	}
}

class DemoEmployee{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no. of employees:");
		int n = sc.nextInt();
		System.out.println("Enter details: ");
		Employee e[] = new Employee[n];
		for(int i=0; i<n; i++)
		{
			e[i] = new Employee();
			e[i].read();
		}
		System.out.println("Details are: ");
		for(Employee ep: e)
		{
			ep.display();
			ep.compute_net_sal();
		}
	}
}


