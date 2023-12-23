import java.util.*;

class STUDENT{
    String name;
    int marks[]=new int[5];
	STUDENT(){
		name = "NULL";
		for(int m=0; m<5; m++){
			marks[m] = 0;
		}
	}
	STUDENT(String n,int arr[]){
		name = n;
		marks = arr;
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


class ScienceStudent extends STUDENT{
	private int practicalMarks;
	ScienceStudent(String n, int arr[], int x){
		super(n, arr);
		practicalMarks = x;
	}
	void compute(){
		int total = 0, n=0;
        for(int c:this.marks)
        {
            total +=c;
            n++;
        }
        n++;
        total += practicalMarks;
        double avg = total/(double)n;
        System.out.println("Total marks: " + total);
        System.out.println("Avg is: " + avg);
	}
	void displayPractMarks(){
		System.out.println("Practical marks earned: " + practicalMarks);
	}
}

class ArtStudent extends STUDENT{
	private String elective;
	ArtStudent(String n, int arr[], String x){
		super(n, arr);
		elective = x;
	}
	void displayElective(){
		System.out.println("Elective chosen: " + elective);
	}
}


class DemoSTUDENT{
	public static void main(String args[]){
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
        System.out.println("Enter Stream(0->Science|1->Art)");
        int choice = sc.nextInt();
        sc.nextLine();
        if(choice == 0){
        	System.out.println("Enter practical marks:");
        	int pm = sc.nextInt();
        	ScienceStudent obj1 = new ScienceStudent(name, marks, pm);
        	obj1.compute();
        	obj1.display();
        	obj1.displayPractMarks();
        } else{
        	System.out.println("Enter elective subject:");
        	String ele = sc.nextLine();
        	ArtStudent obj2 = new ArtStudent(name, marks, ele);
        	obj2.compute();
        	obj2.display();
        	obj2.displayElective();
        }
	}
}
