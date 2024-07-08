import java.util.Scanner;

public class leap_year{
    public static void main(String[] agrs){
        
        Scanner read = new Scanner(System.in);
        System.out.print("input the year: ");
        int year = read.nextInt();
        boolean leap_year;
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    leap_year = true;
                }
                else{
                    leap_year = false;
                }
            }
            else{
                leap_year = true;
            }
        }
        else{
            leap_year = false;
        }
        if(leap_year){
            System.out.println(year + " is a leap year");
        }
        else{
            System.out.println(year + " is not a leap year");
        }
    }
}