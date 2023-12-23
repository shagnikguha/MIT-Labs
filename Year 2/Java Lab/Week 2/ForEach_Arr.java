import java.util.*;
class ForEach_Arr
{
	public static void main(String args[])
	{
		System.out.println("Enter the desired length of array:");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		//input using for-loop
		for(int i=0; i<n; i++)
		{
			arr[i] = i+1;
		}
		//printing using for-each
		for(int x: arr)
		{
			System.out.println(x + " ");
		}
		sc.close();
	}
}


