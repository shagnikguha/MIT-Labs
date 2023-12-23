import java.util.*;
class Mixer{
	int a[];
	void accept(){
		int n;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements;");
		n = sc.nextInt();
		int a[] = new int[n];
		System.out.println("Enter in ascneding:");
		for(int i=0; i<n; i++)
		{
			a[i] = sc.nextInt();
		}
		this.a = a;
	}
	Mixer mix(Mixer A){
		Mixer B = new Mixer();
		B.a = new int[this.a.length + A.a.length];
		int i =0,j =0, k=0;
		int n = this.a.length + A.a.length;
		while(k<n && i< this.a.length && j<A.a.length){
			if(this.a[i] < A.a[j]){
				B.a[k] = this.a[i];
				i++;
				k++;
			} else{
				if(this.a[i]>A.a[j]){
					B.a[k] = A.a[j];
					j++;
					k++;
				} else{
					B.a[k] = A.a[j];
					B.a[k+1] = A.a[j];
					k = k+2;i++;j++;
				}
			}
			if(i!=this.a.length-1 &&j==A.a.length){
				for(;k<n;k++,i++){
					B.a[k] = this.a[i];
				}
			}
			if(j!=A.a.length-1 && i==this.a.length){
				for(;k<n; k++,j++){
					B.a[k] = A.a[j];
				}
			}
		}
		return B;
	}
	void display(){
		for(int c: this.a){
			System.out.print(c + " ");
		}
	}
}

class DemoMixer{
	public static void main(String args[]){
		Mixer A = new Mixer();
		Mixer B = new Mixer();
		A.accept();
		B.accept();
		System.out.println("Mixed: ");
		Mixer C = A.mix(B);
		C.display();
		
	}
}


