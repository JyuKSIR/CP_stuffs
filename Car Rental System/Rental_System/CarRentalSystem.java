package Rental_System;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CarRentalSystem{
	private List<Car> cars = new ArrayList<>();
	private List<Customer> customers = new ArrayList<>();
	private List<Rental> rentals = new ArrayList<>();
	
	public CarRentalSystem(){
		
	}
	
	public void addCar(Car car){
		cars.add(car);
	}
	
	public void addCustomer(Customer customer){
		customers.add(customer);
	}
	
	public void rentCar(Car car, Customer customer, int days){
		if(car.isAvailable()){
			car.rent();
			rentals.add(new Rental(car, customer, days));
		}
		else{
			System.out.println("Car is not available for rent");
		}
	}
	
	public void returnCar(Car car){
		Rental removeRental = null;
		for(Rental storedCars : rentals){
			if(storedCars.getCar() == car){
				removeRental = storedCars;
				car.returnCar();
				break;
			}
		}
		
		if(removeRental != null){
			rentals.remove(removeRental);
		}
		else{
			System.out.println("Car was not rented");
		}
	}
	
	public void menu(){
		Scanner read = new Scanner(System.in);
		
		while(true){
			System.out.println("\n====CAR RENTAL SYSTEM===\n");
			System.out.println("1. Rent a car");
			System.out.println("2. Return a car");
			System.out.println("3. Exit");
			System.out.print("\nEnter your choice: ");
			
			int choice = read.nextInt();
			read.nextLine();
			
			if(choice == 1){
				System.out.println("\nRent a car\n");
				System.out.print("Enter your name: ");
				String customerName = read.nextLine();
				
				System.out.println("\nAvailable cars:\n");
				
				for(Car availableCars : cars){
					if(availableCars.isAvailable()){
						System.out.println(availableCars.getcarId() + "-" + availableCars.getbrand() + "-" + availableCars.getmodel());
					}
				}
				
				System.out.println();
				System.out.print("Enter the car ID you want to rent: ");
				String carId = read.nextLine();
				
				System.out.print("\nEnter the number of days for rental: ");
				int rentalDays = read.nextInt();
				read.nextLine();
				
				Customer newCustomer = new Customer("CUS" + (customers.size() + 1), customerName);
				addCustomer(newCustomer);
				
				Car selectedCar = null;
				
				for(Car carforRent : cars){
					if(carforRent.getcarId().equals(carId) && carforRent.isAvailable()){
						selectedCar = carforRent;
						break;
					}
				}
				
				if(selectedCar != null){
					double totalPrice = selectedCar.totalRent(rentalDays);
					System.out.println();
					System.out.println("==Rental Information==");
					System.out.println();
					System.out.println("Customer Id: " + newCustomer.getId());
					System.out.println("Customer name: " + newCustomer.getName());
					System.out.println("Selected car: " + selectedCar.getbrand() + "-" + selectedCar.getmodel());
					System.out.println("Rental days: " + rentalDays);
					System.out.println("Total price: " + totalPrice + " Taka");
					
					System.out.println();
					System.out.print("Confirrm Rental (Y/n): ");
					String confirm = read.nextLine();
					
					if(confirm.equalsIgnoreCase("Y")){
						rentCar(selectedCar,newCustomer,rentalDays);
						System.out.println();
						System.out.println("Car rented successfully.");
					}
					else{
						System.out.println();
						System.out.println("Rental canceled");
					}
				}
				
				else{
					System.out.println();
					System.out.println("Car not available for rent");
				}
			}
			
			else if(choice == 2){
				System.out.println();
				System.out.println("==Rent a car==");
				System.out.println();
				System.out.print("Enter the car id you want to return: ");
				String returnCarId = read.nextLine();
				
				Car carToreturn = null;
				
				for(Car returnCar : cars){
					if(returnCar.getcarId().equals(returnCarId) && !returnCar.isAvailable()){
						carToreturn = returnCar;
						break;
					}
				}
				
				if(carToreturn != null){
					Customer returnCustomer = null;
					for(Rental rentalCar : rentals){
						if(rentalCar.getCar() == carToreturn){
							returnCustomer = rentalCar.getCustomer();
							break;
						}
					}
					if(returnCustomer != null){
						returnCar(carToreturn);
						System.out.println("\nCar returned successfully by " + returnCustomer.getName());
					}
					else{
						System.out.println("Rental information is missing.");
					}
				}
				else{
					System.out.println("Invalid car Id or car is not found.");
				}
			}
			else if(choice == 3){
				break;
			}
			else{
				System.out.println("Invalid choice. Please Enter a valid option.");
			}
		}
		System.out.println();
		System.out.println("Thank you for using car rental system!\n");
	}
}