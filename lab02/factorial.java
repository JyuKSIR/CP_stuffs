import java.util.Scanner;

public class factorial{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.print("Input a number: ");
        int n = read.nextInt();
        long fact = 1;
        for(int i = n; i>=1; i--){
            fact*=i;
        }
        System.out.print("Factorial of "+ n + " is: " + fact);
    }
}