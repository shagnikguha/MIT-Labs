import java.util.*;
class STUDENT{
	String name;
	int mark[] = new int[5];
	STUDENT(){
		name = "NULL";
		for(int m=0; m<5; m++){
			mark[m] = 0;
		}
	}
	STUDENT(String n,int arr[]){
		name = n;
		mark = arr;
	}
	void display(){
		System.out.println("Name: " + name);
		System.out.println("Marks: ");
		for(int m: mark)
		{
			System.out.print(m);
		}
		System.out.println();
	}
}

class DemoSTUDENT{
	public static void main(String args[]){
		STUDENT S1 = new STUDENT();
		String name = "Shagnik";
		int marks[] = {1,2,3,4,5};
		STUDENT STU = new STUDENT(name, marks);
		System.out.println("Student 1:");
		S1.display();
		System.out.println("Student 2:");
		STU.display();
	}
}


