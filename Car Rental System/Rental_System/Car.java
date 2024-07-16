package Rental_System;

public class Car{
	private String carId;
	private String brand;
	private String model;
	private double pricePerDay;
	private boolean isAvailable;
	
	public Car(){ //constructor which provide java automatically
	
	}
	
	public Car(String carId, String brand, String model, double pricePerDay){ //constructor we made manually to initialize things 
		this.carId = carId;
		this.brand = brand;
		this.model = model;
		this.pricePerDay = pricePerDay;
		this.isAvailable = true;
	}
	
	public String getcarId(){    //getter method for car id
		return carId;
	}
	
	public String getbrand(){    //getter method for brand
		return brand;
	}
	
	public String getmodel(){    //getter method for model
		return model;
	}
	
	public boolean isAvailable(){ //getter method for available or not
		return isAvailable; 
	}
	
	public void rent(){           //taking a car for rent making it not available
		this.isAvailable = false;
	}
	
	public void returnCar(){      //returning a car for rent making it again available
		this.isAvailable = true;
	}
	
	public double totalRent(int days){  //for how many days want to take the car multiplying price per day and getting the total rent
	    return pricePerDay*days;
	}
}