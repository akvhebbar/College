import java.util.Scanner;
public class ncr_npr
{
// Function to find factorial
    static int factorial(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        else
            return n * factorial(n - 1);
    }
// Function to calculate nCr
    static int nCr(int n, int r)
    {
        if (r == 0 || r == n)
            return 1;
        else
            return factorial(n) / (factorial(r) * factorial(n - r));
    }
// Function to calculate nPr    
    static int nPr(int n, int r)
    {
        if (r == 0)
            return 1;
        else
            return factorial(n) / factorial(n - r);
    }
    public static void main(String[] args)
    {
        System.out.println("Enter the option 1/2-> 1: for ncr and 2 :for npr");
        Scanner sc=new Scanner(System.in);
        int val=sc.nextInt();
        System.out.print("Enter the value of n: ");
        int n = sc.nextInt();
        System.out.print("Enter the value of r: ");
        int r = sc.nextInt();
        switch(val)
        {
            case 1:
                    if (n >= r)
                    {
                        System.out.println("nCr = " + nCr(n, r));
                    } 
                    else
                    {
                        System.out.println("Invalid input! n should be greater than or equal to r.");
                    }
                    break ;
            case 2:
                    if (n >= r)
                    {
                        System.out.println("nPr = " + nPr(n, r));
                    }
                    else
                    {
                        System.out.println("Invalid input! n should be greater than or equal to r.");
                    }
                    break ;
            default: System.out.println("Invalid Option");
            sc.close();
        }
    }
}