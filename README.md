



# Vehicle Rental Management System

## Overview
This project is a simple vehicle rental management system developed in C++. It allows administrators to manage vehicle and customer records, and customers to rent and return vehicles.

## Features
- Admin functionalities:
  - Add new vehicles
  - Add new customers
  - View all vehicles and customers
- Customer functionalities:
  - Rent vehicles
  - Return vehicles
  - View available vehicles

- **Data Management:**
  - Save rented vehicles and available vehicles to CSV files for persistent storage.
  - Track rental information, including customer details, rental dates, rental periods, and total costs.

## Requirements
- C++ Compiler (e.g., g++, clang++)
- Standard C++ libraries
- File system access for CSV operations
  
## Usage
Upon starting the program, select whether you are an admin or a customer. Follow the prompts to add vehicles, customers, or rent/return vehicles as needed. The data will be stored in CSV files (`rented_vehicles.csv`, `vehicles.csv`) for future reference.

## Code Structure
- `main.cpp`: Contains the main function and user interface.
- `Vehicle`: Base class for all vehicle types.
- `Bicycle`, `Bike`, `Car`, `Truck`: Derived classes representing specific vehicle types.
- `Customer`: Class to manage customer details.
- `Rental`: Class that handles vehicle rentals, including rental records and CSV file management.

## Future Improvements
- Implement user authentication for admin and customer accounts.
- Add a feature to view and manage rental history for customers.
- Enhance the user interface for better user experience.

## Acknowledgements
Thanks to all contributors and resources that helped in the development of this project.


