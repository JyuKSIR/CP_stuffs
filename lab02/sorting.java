import java.util.Scanner;

public class sorting{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = read.nextInt();
        int ar[] = new int[n];
        System.out.print("Enter the elements of the array: ");
        for(int i=0; i<n; i++){
            ar[i] = read.nextInt();
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((ar[j] & 1) == 0){
                int temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
                break;
                }
            }
        }
        System.out.print("The final array will be: ");
        for(int i=0; i<n; i++){
            System.out.print(ar[i] + " ");
        }
    }
}