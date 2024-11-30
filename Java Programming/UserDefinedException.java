
//write a java program to display user defined exception
import java.util.Scanner;

class Balance extends Exception {
    String message;

    public Balance(String message) {
        this.message = message;
    }

    public String toString() {
        return message;
    }
}

public class UserDefinedException {
    static double current_balance;

    public static void main(String[] args) throws Balance {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Amount to deposit");
        current_balance = s.nextInt();
        System.out.println("Enter amount to withdrawal");
        int n = s.nextInt();

        try {
            if (current_balance < n) {
                throw new Balance("Insufficient funds! Your current balance is " + current_balance);
            } else {
                System.out.println("Please Take The Money: " + n);
                current_balance = current_balance - n;
                System.out.println("Balance Available After Withdrawal: " + current_balance);
            }
        } catch (Balance mab) {
            mab.printStackTrace();
        } finally {
            s.close(); // Close the scanner
        }
    }
}
