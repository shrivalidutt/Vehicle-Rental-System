# Vehicle Rental Management System - README

## Overview
This project implements a simple **Vehicle Rental Management System** in C++. The system has two types of users: **administrators** and **customers**. Administrators can add new vehicles and customers to the system and view existing ones. Customers can rent vehicles, return them, and view the list of available vehicles for rent.

### Key Features:
1. **Administrator Menu**:
   - Add a new vehicle (Bicycle, Bike, Car, or Truck).
   - Add a new customer.
   - Display all available vehicles.
   - Display all customers.

2. **Customer Menu**:
   - Rent a vehicle.
   - Return a rented vehicle.
   - View available vehicles for rent.

## Class Descriptions

### 1. **Vehicle Class (Base Class)**
   - Stores information about the vehicle such as:
     - `make` (manufacturer)
     - `model`
     - `year`
     - `rental_rate` (rental cost per day)
   - Provides a method `display_info()` to display vehicle details.
   - Provides a method `get_rental_rate()` to return the rental rate of the vehicle.
   
### 2. **Bicycle, Bike, Car, Truck (Derived Classes)**
   - **Bicycle**: Includes the type of bicycle (e.g., Hybrid, Road).
   - **Bike**: Includes the type of bike (e.g., Sport).
   - **Car**: Includes the number of doors.
   - **Truck**: Includes the cargo capacity.

### 3. **Customer Class**
   - Stores customer details such as:
     - `name`
     - `license number`
   - Provides methods to display customer information and retrieve the customer’s name.

### 4. **Rental Class**
   - Manages the core operations of the rental system:
     - Adding vehicles and customers.
     - Displaying available vehicles.
     - Displaying all customers.
     - Renting and returning vehicles.

## How the System Works

### Administrator Menu:
When logged in as an administrator, you are presented with the following options:
1. **Add a new vehicle**: You can add a bicycle, bike, car, or truck by entering the vehicle details (make, model, year, rental rate, etc.).
2. **Add a new customer**: You can add a customer by providing their name and license number.
3. **Display all vehicles**: This shows all vehicles currently available for rent.
4. **Display all customers**: This shows all customers who are registered in the system.

### Customer Menu:
When logged in as a customer, you can:
1. **Rent a vehicle**: You will be shown a list of available vehicles, and after selecting one and specifying the rental period, the system will display the total rental cost.
2. **Return a vehicle**: After renting a vehicle, you can return it.
3. **View available vehicles**: This will display all vehicles that are available for rent.

## Code Structure

1. **Main Function**:
   - The entry point of the program asks whether the user is an administrator or a customer and navigates them to the appropriate menu.

2. **Administrator Menu (`admin_menu`)**:
   - Provides options for adding vehicles, adding customers, and viewing records.

3. **Customer Menu (`customer_menu`)**:
   - Provides options for renting, returning, and viewing available vehicles.

## Usage Instructions

   **Interaction**:
   - Upon starting the program, you will be prompted to select if you are an administrator or a customer.
   - As an administrator, you can add new vehicles, customers, and view current lists.
   - As a customer, you can rent or return a vehicle, and view available vehicles for rent.

## Possible Extensions

- **Display Customer Rental Information**: Extend the system to show details of a customer’s active rental, including:
   - Customer’s name and license number.
   - Vehicle information (make, model, year, etc.).
   - Rental start date and rental period (in days).
   - Total rental cost.
This can be implemented by adding a rental tracking system that links a customer to a rented vehicle, tracks the rental start date, and calculates the total cost based on the rental period.

- **Track rented vehicles**: Add a system to mark vehicles as "rented" so that they don't appear in the list of available vehicles.
- **Enhanced return mechanism**: Implement a more detailed return system where customers can be prompted to confirm which vehicle they are returning.
- **Track rental history**: Implement a history log to keep track of which customers rented which vehicles and when.

## Notes
- The system currently does not have persistent storage, so all data is lost when the program exits.
- It assumes all vehicles are available for rent at the start and does not handle vehicle availability when rented by a customer.

## Conclusion
This program provides a basic framework for vehicle rental management, with distinct functionalities for administrators and customers. The flexibility to handle different vehicle types allows for diverse rental scenarios.
