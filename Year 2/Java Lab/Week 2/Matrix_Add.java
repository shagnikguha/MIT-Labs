import java.util.*;

class Matrix_Add
{
	static int[][] add(int M1[][], int M2[][], int n)
	{
		int R[][] = new int[n][n];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				R[i][j] = M1[i][j] + M2[i][j];
			}
		}
		return R;
	}
	static void display(int arr[][], int n)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println(" ");
		}
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size of matrix(s):");
		int n = sc.nextInt();
		int M1[][] = new int[n][n];
		int M2[][] = new int[n][n];
		int R[][] = new int[n][n];
		System.out.println("Enter values of M1:");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				M1[i][j] = sc.nextInt();
			}
		}
		System.out.println("Enter values of M2:");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				M2[i][j] = sc.nextInt();
			}
		}
		System.out.println("Calculating:");
		display(M1, n);
		System.out.println("+");
		display(M2, n);
		System.out.println("=");
		R = add(M1, M2, n);
		display(R, n);
		sc.close();
	}
}


