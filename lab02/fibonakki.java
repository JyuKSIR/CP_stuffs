import java.util.Scanner;

public class fibonakki{
	public static void main(String[] args){
		Scanner read = new Scanner(System.in);
		int n, f=1, s=1, next;
		n = read.nextInt();
		System.out.println("The first " + n + " fibonakki numbers are:");
		for(int i=1; i<=n; i++){
			if(i==1) System.out.print(f + " ");
			else if(i==2) System.out.print(s + " ");
			else{
				next = f + s;
				System.out.print(next + " ");
				f = s;
				s = next;
			}	
		}
	}
}