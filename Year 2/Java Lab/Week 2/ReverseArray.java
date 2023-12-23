import java.util.*;

class ReverseArray
{
	void reverse(int arr[])
	{
		for(int i = arr.length-1; i>=0; i--)
		{
			System.out.println(arr[i]);
		}
	}

	public static void main(String args[])
	{
		ReverseArray obj = new ReverseArray();
		int n;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of elements in array:");
		n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter elements:");
		for(int i=0; i<n; i++)
		{
			arr[i] = sc.nextInt();
		}
		sc.close();
		obj.reverse(arr);
	}
}


