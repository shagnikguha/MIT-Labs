import java.util.*;
class Student{
        String name;
        int marks[];
        void assign(){
                Scanner sc = new Scanner(System.in);
                String name = new String();
                System.out.println("Enter name: ");
                name = sc.nextLine();
                System.out.println("Enter number of subjects:");
                int n = sc.nextInt();
		int marks[] = new int[n];
                System.out.println("Enter marks: ");
                for(int i = 0; i<n; i++)
                {
                        marks[i] = sc.nextInt();
                }
                this.name = name;
                this.marks = marks;
        }
        void compute()
        {
                int total = 0, n=0;
                for(int c:this.marks)
                {
                        total +=c;
                        n++;
                }
                double avg = total/(double)n;
                System.out.println("Total marks: " + total);
                System.out.println("Avg is: " + avg);
        }
        void display(){
                System.out.println("Name: " +this.name);
                System.out.println("Marks: ");
		for(int c:this.marks){
                        System.out.print(c + " ");
                }
		System.out.println();
        }
}


class DemoStudent{
	public static void main(String args[]){
		Student s1 = new Student();
		s1.assign();
		Student s2 = new Student();
		s2.assign();
		s1.display();
		s1.compute();
		s2.display();
		s2.compute();
	}
}

