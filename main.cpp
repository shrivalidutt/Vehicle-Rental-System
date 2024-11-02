#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>   // For file handling
#include<ctime>     // For rental date handling
#include<iomanip>

using namespace std;

// Function to get the current date as a string
string get_current_date() {
    ostringstream oss;
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    oss << put_time(ltm, "%Y-%m-%d");
    return oss.str();
}

class Vehicle{
protected:
    string make; 
    string model; 
    int year; 
    float rental_rate;

public:
    Vehicle(string make, string model, int year, float rate): 
        make(make), model(model), year(year), rental_rate(rate) {}

    virtual float get_rental_rate() {
        return rental_rate;
    }

    virtual void display_info() {
        cout << "Make: " << make << " | Model: " << model << " | Year: " << year << " | Rental Rate: " << rental_rate << " rp/day" << endl;
    }

    string get_make() const { return make; }
    string get_model() const { return model; }
    int get_year() const { return year; }
};

class Bicycle : public Vehicle {
    string type;
public:
    Bicycle(string make, string model, int year, float rate, string type): 
        Vehicle(make, model, year, rate), type(type) {}

    void display_info() {
        Vehicle::display_info();
        cout << " | Type: " << type << " (Bicycle)" << endl;
    }

    string get_type() { return type; }
};

class Bike : public Vehicle {
    string type;
public:
    Bike(string make, string model, int year, float rate, string type): 
        Vehicle(make, model, year, rate), type(type) {}

    void display_info() {
        Vehicle::display_info();
        cout << " | Type: " << type << " (Bike)" << endl;
    }

    string get_type() { return type; }
};

class Car : public Vehicle {
    int num_doors;
public:
    Car(string make, string model, int year, float rate, int doors): 
        Vehicle(make, model, year, rate), num_doors(doors) {}

    void display_info() {
        Vehicle::display_info();
        cout << " | Doors: " << num_doors << " doors (Car)" << endl;
    }

    int get_num_doors() { return num_doors; }
};

class Truck : public Vehicle {
    int cargo_capacity;
public:
    Truck(string make, string model, int year, float rate, int capacity): 
        Vehicle(make, model, year, rate), cargo_capacity(capacity) {}

    void display_info() {
        Vehicle::display_info();
        cout << " | Cargo Capacity: " << cargo_capacity << " kgs (Truck)" << endl;
    }

    int get_cargo_capacity() { return cargo_capacity; }
};

class Customer {
    string name; 
    int license_num; 

public:
    Customer(string name, int license_num): name(name), license_num(license_num) {}

    void display_customer_info() {
        cout << "Name: " << name << " | License no.: " << license_num << endl;
    }

    string get_name() { return name; }

    int get_license_num() { return license_num; }
};

class Rental {
    vector<Customer> customers;
    vector<Vehicle*> vehicles;

    struct RentalRecord {
        string customer_name;
        string vehicle_info;
        string rental_date;
        int rental_period;
        float total_cost;
    };

    vector<RentalRecord> rental_records; // Stores information about each rental

public:
    // Add new vehicle
    void add_vehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
        cout << "Vehicle added successfully!" << endl;
        save_vehicles_to_csv();  //Save to CSV after adding
    }

    // Add new customer
    void add_customer(Customer customer) {
        customers.push_back(customer);
        cout << "Customer added successfully!" << endl;
        save_customers_to_csv();  // Save to CSV after adding
    }

    // Display all available vehicles
    void display_available_vehicles() {
        cout << "\nAvailable vehicles:" << endl;
        for (auto& vehicle : vehicles) {
            vehicle->display_info();
        }
        cout << "--------------------\n";
    }

    // Display all customers
    void display_all_customers() {
        cout << "\n--- Customer List ---\n";
        for (auto& customer : customers) {
            customer.display_customer_info();
        }
        cout << "--------------------\n";
    }

 // Save available vehicles to CSV
void save_vehicles_to_csv() {
    ofstream file("vehicles.csv");
    for (auto& vehicle : vehicles) {
        Bicycle* bicycle = dynamic_cast<Bicycle*>(vehicle);
        if (bicycle) {
            file << bicycle->get_make() << " " << bicycle->get_model() << " " 
                 << bicycle->get_year() << " " << bicycle->get_rental_rate() << " Bicycle " 
                 << bicycle->get_type() << endl;
        }
        
        Bike* bike = dynamic_cast<Bike*>(vehicle);
        if (bike) {
            file << bike->get_make() << " " << bike->get_model() << " " 
                 << bike->get_year() << " " << bike->get_rental_rate() << " Bike " 
                 << bike->get_type() << endl;
        }

        Car* car = dynamic_cast<Car*>(vehicle);
        if (car) {
            file << car->get_make() << " " << car->get_model() << " " 
                 << car->get_year() << " " << car->get_rental_rate() << " Car " 
                 << car->get_num_doors() << endl;
        }

        Truck* truck = dynamic_cast<Truck*>(vehicle);
        if (truck) {
            file << truck->get_make() << " " << truck->get_model() << " " 
                 << truck->get_year() << " " << truck->get_rental_rate() << " Truck " 
                 << truck->get_cargo_capacity() << endl;
        }
    }
    file.close();
}

//saves all customers to CSV
void save_customers_to_csv() {
    ofstream file("customers.csv");
    for (auto& customer : customers) {
        file << customer.get_name() << "," << customer.get_license_num() << endl;
    }
    file.close();
}

   // Save rented vehicles to CSV
void save_rented_vehicles_to_csv(vector<Vehicle*> rented_vehicles) {
    ofstream file("rented_vehicles.csv");
    for (auto& vehicle : rented_vehicles) {
        Bicycle* bicycle = dynamic_cast<Bicycle*>(vehicle);
        if (bicycle) {
            file << bicycle->get_make() << " " << bicycle->get_model() << " " 
                 << bicycle->get_year() << " " << bicycle->get_rental_rate() << " Bicycle " 
                 << bicycle->get_type() << endl;
        }
        
        Bike* bike = dynamic_cast<Bike*>(vehicle);
        if (bike) {
            file << bike->get_make() << " " << bike->get_model() << " " 
                 << bike->get_year() << " " << bike->get_rental_rate() << " Bike " 
                 << bike->get_type() << endl;
        }

        Car* car = dynamic_cast<Car*>(vehicle);
        if (car) {
            file << car->get_make() << " " << car->get_model() << " " 
                 << car->get_year() << " " << car->get_rental_rate() << " Car " 
                 << car->get_num_doors() << endl;
        }

        Truck* truck = dynamic_cast<Truck*>(vehicle);
        if (truck) {
            file << truck->get_make() << " " << truck->get_model() << " " 
                 << truck->get_year() << " " << truck->get_rental_rate() << " Truck " 
                 << truck->get_cargo_capacity() << endl;
        }
    }
    file.close();
}

void load_vehicles_from_csv() {
    ifstream file("vehicles.csv");
    string line, make, model, type;
    int year, num_doors, cargo_capacity;
    float rate;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> make >> model >> year >> rate >> type;

        if (type == "Bicycle") {
            string bicycle_type;
            ss >> bicycle_type;
            vehicles.push_back(new Bicycle(make, model, year, rate, bicycle_type));
        } else if (type == "Bike") {
            string bike_type;
            ss >> bike_type;
            vehicles.push_back(new Bike(make, model, year, rate, bike_type));
        } else if (type == "Car") {
            ss >> num_doors;
            vehicles.push_back(new Car(make, model, year, rate, num_doors));
        } else if (type == "Truck") {
            ss >> cargo_capacity;
            vehicles.push_back(new Truck(make, model, year, rate, cargo_capacity));
        }
    }
    file.close();
}

void load_customers_from_csv() {
    ifstream file("customers.csv");
    string name;
    int license_num;

    while (file.good()) {
        getline(file, name, ',');
        file >> license_num;
        file.ignore(); // Ignore newline

        if (!name.empty()) {
            customers.push_back(Customer(name, license_num));
        }
    }
    file.close();
}


    // Display all rental records (for admin)
    void display_rental_records() {
        cout << "\n--- Rental Records ---\n";
        for (auto& record : rental_records) {
            cout << "Customer: " << record.customer_name << " | Vehicle: " << record.vehicle_info << " | Date: " << record.rental_date << " | Period: " << record.rental_period << " days | Total Cost: " << record.total_cost << " rp" << endl;
        }
        cout << "----------------------\n";
    }

// Save a single rented vehicle to CSV (for persistence)
void save_vehicle_to_rented_csv(Vehicle* rented_vehicle, int customer_license) {
    ofstream file("rented_vehicles.csv", ios::app);
    string vehicle_type;

    Bicycle* bicycle = dynamic_cast<Bicycle*>(rented_vehicle);
    if (bicycle) {
        vehicle_type = "Bicycle";
        file << bicycle->get_make() << " " << bicycle->get_model() << " "
             << bicycle->get_year() << " " << bicycle->get_rental_rate() << " " 
             << vehicle_type << " " << bicycle->get_type() << " " << customer_license << endl; 
    }
    
    Bike* bike = dynamic_cast<Bike*>(rented_vehicle);
    if (bike) {
        vehicle_type = "Bike";
        file << bike->get_make() << " " << bike->get_model() << " "
             << bike->get_year() << " " << bike->get_rental_rate() << " " 
             << vehicle_type << " " << bike->get_type() << " " << customer_license << endl; 
    }

    Car* car = dynamic_cast<Car*>(rented_vehicle);
    if (car) {
        vehicle_type = "Car";
        file << car->get_make() << " " << car->get_model() << " "
             << car->get_year() << " " << car->get_rental_rate() << " " 
             << vehicle_type << " " << car->get_num_doors() << " " << customer_license << endl; 
    }

    Truck* truck = dynamic_cast<Truck*>(rented_vehicle);
    if (truck) {
        vehicle_type = "Truck";
        file << truck->get_make() << " " << truck->get_model() << " "
             << truck->get_year() << " " << truck->get_rental_rate() << " " 
             << vehicle_type << " " << truck->get_cargo_capacity() << " " << customer_license << endl; 
    }
    file.close();
}



void rent_vehicle(string customer_name, int rental_period) {
    bool customer_found = false;
    int customer_license = 0;

    // Find the customer
    for (auto& customer : customers) {
        if (customer.get_name() == customer_name) {
            customer_found = true;
            customer_license = customer.get_license_num(); // Get the license number
            break;
        }
    }

    if (!customer_found) {
        cout << "Customer not found! Would you like to add them? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            cout << "Enter license number: ";
            cin >> customer_license; // Take input for new customer license
            add_customer(Customer(customer_name, customer_license));
        } else {
            return; // Exit if the customer is not found and not added
        }
    }

    cout << "Available vehicles for rent:" << endl;
    for (int i = 0; i < vehicles.size(); ++i) {
        cout << i + 1 << ". ";
        vehicles[i]->display_info();
    }

    int vehicle_choice;
    cout << "Select the vehicle to rent (number): ";
    cin >> vehicle_choice;

    if (vehicle_choice >= 1 && vehicle_choice <= vehicles.size()) {
        Vehicle* selected_vehicle = vehicles[vehicle_choice - 1];
        string rental_date = get_current_date(); // Set the rental date
        float total_cost = selected_vehicle->get_rental_rate() * rental_period;

        cout << customer_name << " rented the vehicle for " << rental_period << " days." << endl;
        cout << "Rental Date: " << rental_date << endl;
        cout << "Total rental cost: " << total_cost << " rp" << endl;

        save_vehicle_to_rented_csv(selected_vehicle, customer_license); // Save with license number
        vehicles.erase(vehicles.begin() + (vehicle_choice - 1)); // Remove from available vehicles
        save_vehicles_to_csv();  // Update available vehicles CSV

        // Save rental record
        rental_records.push_back({customer_name, selected_vehicle->get_make() + " " + selected_vehicle->get_model(), rental_date, rental_period, total_cost});
    } else {
        cout << "Invalid vehicle selection!" << endl;
    }
}

// Return vehicle logic
void return_vehicle(string customer_name) {
    ifstream file("rented_vehicles.csv");
    string make, model, type, line;
    int year, num_doors, cargo_capacity, license_num;
    float rate;
    vector<Vehicle*> rented_vehicles;

    // Read the rented vehicles from CSV
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> make >> model >> year >> rate >> type;

        if (type == "Bicycle") {
            rented_vehicles.push_back(new Bicycle(make, model, year, rate, "Hybrid"));  // Example type
        } else if (type == "Bike") {
            rented_vehicles.push_back(new Bike(make, model, year, rate, "Sport"));
        } else if (type == "Car") {
            ss >> num_doors; // Read number of doors from the line
            rented_vehicles.push_back(new Car(make, model, year, rate, num_doors));
        } else if (type == "Truck") {
            ss >> cargo_capacity; // Read cargo capacity from the line
            rented_vehicles.push_back(new Truck(make, model, year, rate, cargo_capacity));
        }

        // Read customer license number
        ss >> license_num;
    }
    file.close();

    cout << "\nRented Vehicles:\n";
    for (int i = 0; i < rented_vehicles.size(); ++i) {
        cout << i + 1 << ". ";
        rented_vehicles[i]->display_info();
    }

    int vehicle_choice;
    cout << "Select the vehicle to return (number): ";
    cin >> vehicle_choice;

    if (vehicle_choice >= 1 && vehicle_choice <= rented_vehicles.size()) {
        Vehicle* returned_vehicle = rented_vehicles[vehicle_choice - 1];
        vehicles.push_back(returned_vehicle);  // Add back to available vehicles
        rented_vehicles.erase(rented_vehicles.begin() + (vehicle_choice - 1));  // Remove from rented list

        save_vehicles_to_csv();  // Update available vehicles CSV
        save_rented_vehicles_to_csv(rented_vehicles);  // Update rented vehicles CSV

        cout << "Vehicle returned successfully!" << endl;

        // Clean up remaining rented vehicles
        for (auto veh : rented_vehicles) {
            delete veh;  // Free memory for the vehicles
        }
    } else {
        cout << "Invalid vehicle selection!" << endl;
    }
}
};

void admin_menu(Rental& rental_system) {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Add Customer\n";
        cout << "3. Display All Vehicles\n";
        cout << "4. Display All Customers\n";
        cout << "5. Display Rental Records\n";
        cout << "6. Exit Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type_choice;
                cout << "Select vehicle type:\n1. Bicycle\n2. Bike\n3. Car\n4. Truck\nEnter choice: ";
                cin >> type_choice;

                string make, model, type;
                int year, num_doors, cargo_capacity;
                float rate;

                cout << "Enter vehicle make: ";
                cin >> make;
                cout << "Enter vehicle model: ";
                cin >> model;
                cout << "Enter vehicle year: ";
                cin >> year;
                cout << "Enter rental rate: ";
                cin >> rate;

                if (type_choice == 1) {
                    // Bicycle-specific input
                    cout << "Enter bicycle type (e.g., Hybrid, Mountain): ";
                    cin >> type;
                    rental_system.add_vehicle(new Bicycle(make, model, year, rate, type));
                } else if (type_choice == 2) {
                    // Bike-specific input
                    cout << "Enter bike type (e.g., Sport, Cruiser): ";
                    cin >> type;
                    rental_system.add_vehicle(new Bike(make, model, year, rate, type));
                } else if (type_choice == 3) {
                    // Car-specific input
                    cout << "Enter number of doors: ";
                    cin >> num_doors;
                    rental_system.add_vehicle(new Car(make, model, year, rate, num_doors));
                } else if (type_choice == 4) {
                    // Truck-specific input
                    cout << "Enter cargo capacity (in kgs): ";
                    cin >> cargo_capacity;
                    rental_system.add_vehicle(new Truck(make, model, year, rate, cargo_capacity));
                } else {
                    cout << "Invalid vehicle type selected!" << endl;
                }

                break;
            }
            case 2: {
                string name;
                int license_num;
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter license number: ";
                cin >> license_num;
                rental_system.add_customer(Customer(name, license_num));
                break;
            }
            case 3:
                rental_system.display_available_vehicles();
                break;
            case 4:
                rental_system.display_all_customers();
                break;
            case 5:
                rental_system.display_rental_records();
                break;
            case 6:
                cout << "Exiting Admin Menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);
}


void customer_menu(Rental& rental_system) {
    int choice;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. Rent a Vehicle\n";
        cout << "2. Return a Vehicle\n";
        cout << "3. View Available Vehicles\n";
        cout << "4. Exit Customer Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string customer_name;
                int rental_period;
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter rental period in days: ";
                cin >> rental_period;
                rental_system.rent_vehicle(customer_name, rental_period);
                break;
            }
            case 2: {
                string customer_name;
                int customer_license;
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter customer license number: ";
                cin >> customer_license;
                rental_system.return_vehicle(customer_name);
                break;
            }
            case 3:
                rental_system.display_available_vehicles();
                break;
            case 4:
                cout << "Exiting Customer Menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    Rental rental_system;
    rental_system.load_vehicles_from_csv();   // Load previously saved vehicles
    rental_system.load_customers_from_csv();  // Load existing customers

    int user_type;

    do {
        cout << "\n--- Vehicle Rental System ---\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter user type: ";
        cin >> user_type;

        if (user_type == 1) {
            admin_menu(rental_system);
        } else if (user_type == 2) {
            customer_menu(rental_system);
        } else if (user_type == 3) {
            cout << "Exiting the system..." << endl;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (user_type != 3);

    return 0;
}


