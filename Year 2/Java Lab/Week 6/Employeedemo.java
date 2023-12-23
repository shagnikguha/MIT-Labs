import java.util.*;

class Employee{
	String name;
	int id;
	 int Eid;
      float basic;
        double DA;
        double gross_sal;
        double net_sal;
        double IT;

  Employee(String name,float basic){
    this.name=name;
    this.basic=basic;
  }

  Employee(){
    this.name="unknown";
    this.id=121212;
  }

    void compute_net_sal()
  {

    DA=0.52*basic;
    gross_sal=DA+basic;
    IT=0.3*gross_sal;
    net_sal=gross_sal-IT;
  }

    void display()
  {
          System.out.println("details of "+name+" are given below");
          System.out.println("basic is "+basic);
          System.out.println("DA is "+ DA);
          System.out.println("gross salary is "+gross_sal);
          System.out.println("net salary of "+name+"  normal employee is "+  net_sal);

          System.out.println();
  }
}


class FulltimeEmp extends Employee{
  double bonus;
  double deduction;
  double net_sal;
  FulltimeEmp(String name,float basic,double bonus,double deduction){
  	super(name,basic);
  	this.bonus=bonus;
  	this.deduction=deduction;
  }

  void compute_net_sal(){
   super.compute_net_sal();
   net_sal=super.net_sal+bonus-deduction;
  }

  void display(){
  	super.display();
   System.out.println("the net salary of"+super.name+"as  part time  employee after bonus and deduction is "+net_sal);

  }

}

class PartTimeEmployee extends Employee{
	int hours;
    static double hourly_rate;
    double net_sal;
    

	PartTimeEmployee(String name,float basic,int hours,double hourly_rate){
		super(name,basic);
		this.hours=hours;
		this.hourly_rate=hourly_rate;
	}

	PartTimeEmployee(){
		super();
		hours=8;
		hourly_rate=250;
	}

	 void compute_net_sal(){
		 super.compute_net_sal();
	 	net_sal=basic+(hours*hourly_rate*30);
	 }

	 void display(){
	 	super.display();
	 	System.out.println("net salary for "+super.name+" as  full time is "+net_sal);
	 }
 
}

class Employeedemo{
 public static void main(String[] args) {
 	int n;
 	String name;
 	float basic;
 	int hours;
 	double hourly_rate,bonus,deduction;
 		Scanner sc=new Scanner(System.in);

 	System.out.println("enter 0 for creating normal employee, 1 for partTime and 2 for Fulltime");
 	 n=sc.nextInt();
	 sc.nextLine();
 	switch(n){
 	case 0:
 		System.out.println("enter name of employee and basic amount");
 		name=sc.nextLine();
 		basic=sc.nextInt();
 		Employee e1=new Employee(name,basic);
 		e1.compute_net_sal();
 		e1.display();
 		break;

 	case 1:
        System.out.println("enter name of partTime and basic amount");
 		name=sc.nextLine();
 		basic=sc.nextInt();

 		 System.out.println("enter working hours and hourly rate");
 		 hours=sc.nextInt();
 		 hourly_rate=sc.nextDouble();
 		PartTimeEmployee e2=new PartTimeEmployee(name,basic,hours,hourly_rate);
 		e2.compute_net_sal();
 		e2.display();
 		break;

 	case 2:
 		System.out.println("enter name of Fulltime employee and basic amount");
 		name=sc.nextLine();
 		basic=sc.nextInt();

 		 System.out.println("enter bonus and deduction rate");
 		 bonus=sc.nextDouble();
 		 deduction=sc.nextDouble();
 		FulltimeEmp e3=new FulltimeEmp(name,basic,bonus,deduction);
 		e3.compute_net_sal();
 		e3.display();
 		break;

 	}
 }

}
