import java.util.*;
class Student{
	String name;
	int marks[]=new int[5];
	Student(){
		name="NULL";
		for(int i=0;i<5;i++){
			marks[i] = 0;
		}
	}
	Student(String name,int marks[]){
		this.name=name;
		this.marks=marks;
	}
	String ExtractIni(){
		String[] words=name.split(" ");
		StringBuilder I=new StringBuilder();
		for(String w:words)
		{
			I.append(Character.toUpperCase(w.charAt(0)));
		}
		return I.toString();
	}
	String NoSpace(){
		String[] words=name.split(" ");
		StringBuilder n=new StringBuilder();
		for(String w:words)
		{
			n.append(w);
		}
		return n.toString();
	}
	void display(){
		System.out.println("name : "+this.name);
		System.out.println("Marks are : ");
		for(int c:this.marks)
			System.out.print(c+" ");
		System.out.println();
		System.out.println("Initials : "+ExtractIni()+"\nName with no space :"+NoSpace());
	}
	static void Sub(Student[] a,String key)
	{
		for(int i=0;i<a.length;i++)
			if(a[i].name.contains(key))
				System.out.println(a[i].name);
	}
	static void Sort(Student[] a)
	{
		Student temp;
		for(int i=0;i<a.length;i++)
		{
			for(int j=i+1;j<a.length;j++)
			{
				if(a[j].name.compareTo(a[i].name)<0)
				{
					temp=a[j];
					a[j]=a[i];
					a[i]=temp;
				}
			}
		}
		for(Student s:a){
			System.out.println(s.name);
		}
	}

}
class DemoStu{
	public static void main(String[] args){
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of students : ");
		n=sc.nextInt();
		sc.nextLine();
		Student[] s=new Student[n];
		for(int i=0;i<n;i++)
		{
			String name=new String();
			int marks[]=new int[5];
		    System.out.println("Enter name : ");
			name=sc.nextLine();
			System.out.println("Enter the marks : ");
			for(int j=0;j<5;j++){
				marks[j]=sc.nextInt();
			}
			s[i]=new Student(name,marks);
			sc.nextLine();	
		}
		for(int i=0;i<n;i++)
			s[i].display();
		System.out.println("Students in alphabetical order is :");
		Student.Sort(s);
		System.out.println("Enter string for which we need to access the name :");
		String h=new String();
		h=sc.nextLine();
		Student.Sub(s,h);
	}
}
