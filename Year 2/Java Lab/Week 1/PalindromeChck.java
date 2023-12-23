import java.util.*;
class PalindromeChck
{
	static int reverse(int x)
	{	
		int rem = 0;
		int rev = 0;
		while(x!=0)
		{
			rem = x%10;
			rev = (rev*10)+rem;
			x = x/10;
		}
		return rev;
	}
	static void check(int x)
	{
		int r = reverse(x);
		if(r==x)
		{
			System.out.println("Palindrome");
		}else{
			System.out.println("Not Palindrome");
		}
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number: ");
		int x = sc.nextInt();
		check(x);
	}
}



