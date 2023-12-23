import java.util.*;
class nCr
{
	public static int fact(int x)
	{
		int f = 1;
		for(int i = 1; i<=x; i++)
		{
			f *= i;
		}
		System.out.println(f);
		return f;
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter value of n: ");
		int n = sc.nextInt();
		System.out.println("Enter value of r: ");
		int r = sc.nextInt();
		int calc = fact(n)/(fact(r) * fact(n-r));
		System.out.println(n+"C"+r+" = "+ calc);
	}
}

