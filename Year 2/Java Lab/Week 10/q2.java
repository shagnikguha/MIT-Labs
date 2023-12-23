import java.util.*;

class stack <T>{
	int top;
	int size;
	T arr[];

	stack(int y){
		top = -1;
		size = y;
		arr = (T[])new Object[y];
	}

	void push(T x){
		if(top==size){
			System.out.println("Stack is full!");
			return;
		}
		arr[++top] = x;
	}

	void pop(){
		if(top==-1){
			System.out.println("Stack is empty!");
			return;
		}
		System.out.println(arr[top] + " popped!");
		top -= 1;
	}

	void compare(T x,T y){
		if(x==y){
			System.out.println("objects are same");
		} else{
			System.out.println("objects are not same");
		}
	}
}

class Student{
	String name;
	int id;
	Student(String n, int i){
		name = n;
		id = i;
	}
}

class Employee{
	String name;
	int salary;
	Employee(String n, int e){
		name = n;
		salary = e;
	}
}

class q2{
	public static void main(String args[]){
		stack<Student> obj1 = new stack<Student>(5);
		Student ob1 = new Student("SG", 1);
		obj1.push(ob1);
		Student ob2 = new Student("RC", 2);
		obj1.push(ob2);
		obj1.pop();
		obj1.compare(ob1,ob1);
		stack<Employee> obj2 = new stack<Employee>(5);
		Employee ob3 = new Employee("SG", 1);
		obj2.push(ob3);
		obj2.pop();
	}
}
