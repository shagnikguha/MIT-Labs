import java.util.*;
class Prime_Print_Arr
{
	static boolean primeChck(int x)
	{
		boolean st = true;
		for(int i=2; i<x; i++)
		{
			if(x%i == 0)
			{
				st = false;
			}
		}
		if(x==1)
		{
			st = false;
		}
		
		return st;
	}

	static void primeNum(int arr[])
	{
		for(int i=0; i<arr.length; i++)
		{
			if(primeChck(arr[i])==true)
			{
				System.out.println(arr[i] + " ");
			}
		}
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size of array:");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter values of Array:");
		for(int i=0; i<n; i++)
		{
			arr[i] = sc.nextInt();
		}
		System.out.println("Prime numbers in array are:");
		primeNum(arr);
		sc.close();
	}
}



