import java.util.Scanner;
public class Distance
{
   int feet,inches;
   public void read()
   {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the distance in feet: ");
    feet=sc.nextInt();
    System.out.print("Enter the distance in inches: ");
    inches=sc.nextInt();
    sc.close();

   } 
   public void Display()
   {
    System.out.println("Feet:"+feet+"\tInches:"+inches);
   }
   public void add(Distance D1,Distance D2)
   {
    inches=D1.inches+D2.inches;
    feet=D1.feet+D2.feet+(inches/12);
    inches=inches%12;
   }
   public static void main(String[] args)
   {
    Distance D1=new Distance();
    Distance D2=new Distance();
    Distance D=new Distance();

    System.out.println("Take the input for 1st Distance");
    D1.read();

    System.out.println("Take the input for 2nd Distance");
    D2.read();

    //Addition of two Distances given
    D.add(D1,D2);

    //Display The Result Distance
    D.Display();
    
   }
}