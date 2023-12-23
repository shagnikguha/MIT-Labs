import java.util.*;
class Emp{
	String Ename;
	int Eid;
	int basic;
	Emp(){
		Ename="NULL";
		Eid=0;
		basic=0;
	}
	Emp(String Ename,int Eid,int basic){
		this.Ename=Ename;
		this.Eid=Eid;
		this.basic=basic;
	}
	void display(){
		System.out.println("Name :"+this.Ename);
		System.out.println("id : "+this.Eid);
		System.out.println("basic : "+this.basic);
		double gross=1.52*(this.basic);
		double net=0.7*gross;
		System.out.println("Net : "+net);
		System.out.println("Formated Nmae : "+FormatName());
		System.out.println("Email : "+GenEmail());
	}
	String FormatName(){
		StringBuilder Fname=new StringBuilder();
		Fname.append(Character.toUpperCase(Ename.charAt(0)));
		for(int i=1;i<Ename.length();i=i+1)
		{
			Fname.append(Character.toLowerCase(Ename.charAt(i)));
			if(Ename.charAt(i)==' ')
			{
				Fname.append(Character.toUpperCase(Ename.charAt(i+1)));
				i++;
			}

		}
		return Fname.toString();
	}
	String GenEmail(){
		String words[]=Ename.split(" ");
		StringBuilder E=new StringBuilder();
		for(int i=0;i<words.length-1;i++)
		{
			E.append(Character.toLowerCase(words[i].charAt(0)));
		}
		E.append(words[words.length-1].toLowerCase());
		E.append("@gmail.com");
		return E.toString();
	}
}
class DemoEmp{
	public static void main(String[] args){
		int n;
		System.out.println("Enter the no of employees");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		Emp e[]=new Emp[n];
		for(int i=0;i<n;i++)
		{
			String name=new String();
			int id,basic;
			System.out.println("Please enter the id,basic,name");
			id=sc.nextInt();
			basic=sc.nextInt();
			sc.nextLine();
			name=sc.nextLine();
			e[i]=new Emp(name,id,basic);
		}
		for(Emp em:e)
			em.display();
		System.out.println("Default is ");
		Emp a=new Emp();
		a.display();
	}
}
