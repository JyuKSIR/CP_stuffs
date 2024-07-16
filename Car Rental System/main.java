import Rental_System.*;

public class main{
	public static void main(String[] args){
		
		CarRentalSystem rentalSystem = new CarRentalSystem();
		
		Car car1 = new Car("C001", "Toyota", "Camry", 1500.0);
		Car car2 = new Car("C002", "Honda", "Civic", 2000.0);
		Car car3 = new Car("C003", "Toyota", "HiAce", 3500.0);
		
		rentalSystem.addCar(car1);
		rentalSystem.addCar(car2);
		rentalSystem.addCar(car3);
		
		rentalSystem.menu();
	}
}