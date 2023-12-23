import java.util.*;
class Max
{
	static int max1(int x, int y, int z)
	{
		if(x>y)
		{
			if(x>z)
			{
				return x;
			} 
			else
			{
				return z;
			}
		}
		else{
			if(y>z)
			{
				return y;
			}
			else
			{
				return z;
			}
		   }
		}
	static int max2(int x, int y, int z)
	{
		int big = 0;
		if(x>y)
		{
			if(x>z)
			{
				big =  x;
			}
			if(z>x)
			{
				big =  z;
			}
		}
		if(y>x)
		{
			if(y>z)
			{
				big =  y;
			}
			if(z>y)
			{
				big = z;
			}
		}
		return big;
	}

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter 3 numbers: ");
		int l = sc.nextInt();
		int m = sc.nextInt();
		int n = sc.nextInt();
		int big  = max1(l,m,n);
		int big2 = max2(l,m,n);	
		System.out.println("Biggest number is: " + big + " " + big2);
		
	}
}

