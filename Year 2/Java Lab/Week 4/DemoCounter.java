class Counter{
	static int c=0;
	Counter(){
		c++;
	}
	static void showCount(){
		System.out.println("No. of objects: " + c);
	}
}
class DemoCounter{
	public static void main(String args[]){
		Counter e[] =new Counter[5];
		for(int i=0; i<5; i++)
		{
			e[i] = new Counter();

		}
		Counter.showCount();
	}
}



