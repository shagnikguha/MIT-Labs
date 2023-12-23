import java.util.*;
class Stack{
	int a[];
	int tops;
	int size;
	void declare(int size){
		this.size = size;
		tops = -1;
		a = new int[size];
	}
	void push(int x){
		if(tops==size-1){
			System.out.println("Stack Overflow");
		} else{
			tops++;
			this.a[tops] = x;
		}
	}
	int pop(){
		if(tops==-1){
			System.out.println("Stack Underflow");
		} else{
			tops--;
		}
		return a[tops+1];
	}
	void display(){
		System.out.println("The Stack is: ");
		if(tops ==-1){
			System.out.println("Stack is empty");
		} else{
			for(int i=tops;i>=0; i--){
				System.out.println(this.a[i]);
			}
		}
	}
}

class DemoStack{
	public static void main(String args[]){
		Stack st = new Stack();
		st.declare(3);
		st.push(3);
		st.push(4);
		st.display();
		st.push(5);
		st.push(7);
		st.display();
	}
}


