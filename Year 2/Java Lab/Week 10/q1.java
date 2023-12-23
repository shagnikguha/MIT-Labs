import java.util.*;

class q1{
	public <T> void exchange(T arr[], int a, int b){
		T temp;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	static <T> void display(T arr[]){
		for(int i=0; i<arr.length;i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String args[]){
		q1 obj = new q1();
		Scanner sc = new Scanner(System.in);
		System.out.println("1->int | 2->double");
		int option = sc.nextInt();
		System.out.println("Enter length:");
		int len = sc.nextInt();
		if(option==1){
			Integer arr[] = new Integer[len];
			System.out.println("Enter values:");
			for(int i = 0; i<len; i++){
				arr[i] = sc.nextInt();
			}
			System.out.println("Enterthe positions to swap");
			int p1 = sc.nextInt();
			int p2 = sc.nextInt();
			obj.exchange(arr, p1, p2);
			display(arr);
		}
		if(option==2){
			Double arr[] = new Double[len];
			System.out.println("Enter values:");
			for(int i = 0; i<len; i++){
				arr[i] = sc.nextDouble();
			}
			System.out.println("Enterthe positions to swap");
			int p1 = sc.nextInt();
			int p2 = sc.nextInt();
		    obj.exchange(arr, p1, p2);
			display(arr);
		}
	}
}
