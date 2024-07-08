import java.util.Scanner;

public class gcd{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int n1 = read.nextInt();
        System.out.print("Enter the second number: ");
        int n2 = read.nextInt();
        int gcd = 1;
        int min;
        if(n1>n2){
            min = n2;
        }
        else{
            min = n1;
        }
        for(int i = 1; i<=min; i++){
            if(n1 % i == 0 && n2 % i == 0){
                gcd = i;
            }
        }
        System.out.print("The gcd of " + n1 + " and " + n2 + " is: " + gcd);
    }
} 