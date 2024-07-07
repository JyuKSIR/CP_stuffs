import java.util.Scanner;

public class lab_4_b{
	public static void main(String[] args){
		Scanner read = new Scanner(System.in);
		int n = read.nextInt();
		for(int i=n; i>=1; i--){
			for(int j=n-i; j>=1; j--){
				System.out.print(" ");
			}
			for(int k=2*i-1; k>=1; k--){
				System.out.print('#');
			}
			System.out.println();
			System.out.println();
		}
	}
}