#include<iostream>
#include<string>
#include<vector>

using namespace std;

// typedef struct{
//       int date;
//       int month;
//       int year;
// }Date;

class Vehicle{
    protected:
    string make; 
    string model; 
    int year; 
    float rental_rate;

    public:
    Vehicle(string make, string model, int year, float rate): 
        make(make),model(model),year(year),rental_rate(rate) {}
    
    virtual float get_rental_rate(){
        return rental_rate;
    }
    
    virtual void display_info(){
        cout<<"Make: "<<make<<" | Model: "<<model<<" | Year: "<<year<<" | Rental Rate: "<<rental_rate<<" rp/day"<<endl;
    }
};

class Bicycle : public Vehicle{
    string type;
    public:
    Bicycle(string make, string model, int year, float rate, string type): 
        Vehicle(make, model, year, rate), type(type) {}
  
    void display_info(){
        Vehicle::display_info();
        cout<<" | Type: "<<type<<"(Bicycle)"<<endl;
    }
};

class Bike : public Vehicle{
    string type;
    public:
    Bike(string make, string model, int year, float rate, string type): 
        Vehicle(make, model, year, rate), type(type) {}

    void display_info(){
        Vehicle::display_info();
        cout<<" | Type: "<<type<< "(Bike)"<<endl;
    }
};

class Car : public Vehicle{
    int num_doors;
    public:
    Car(string make, string model, int year, float rate, int doors): 
        Vehicle(make, model, year, rate), num_doors(doors) {}
    
    void display_info(){
        Vehicle::display_info();
        cout<<" | Doors: "<<num_doors<<"doors (Car)"<<endl;
    }
};

class Truck : public Vehicle{
    int cargo_capacity;
    public:
    Truck(string make, string model, int year, float rate, float capacity): 
        Vehicle(make, model, year, rate), cargo_capacity(capacity) {}
    
    void display_info(){
        Vehicle::display_info();
        cout<<" | Cargo Capacity:"<<cargo_capacity<<"kgs (Truck)"<<endl;
    }
};

class Customer{
    string name; 
    int license_num; 
    
    public:
    Customer(string name, int license_num): name(name),license_num(license_num) {}
    
    void display_customer_info(){
        cout<<"Name: "<<name<<" | License no.: "<<license_num<<endl;
    }

    string get_name(){
        return name;
    }
    
};

class Rental{
    vector<Customer> customers;
    vector<Vehicle*> vehicles;
    
    public:
    void add_vehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
        cout << "Vehicle added successfully!" << endl;
    }

    void add_customer(Customer customer) {
        customers.push_back(customer);
        cout << "Customer added successfully!" << endl;
    }

     void display_available_vehicles() {
        cout << "\n--- Available Vehicles ---\n";
        for (auto vehicle : vehicles) {
            vehicle->display_info();
        }
        cout << "--------------------------\n";
    }

    void display_all_customers() {
        cout << "\n--- All Customers ---\n";
        for (auto customer : customers) {
            customer.display_customer_info();
        }
        cout << "--------------------\n";
    }

    void rent_vehicle(string customer_name, int rental_period) {
        for (auto& customer : customers) {
            if (customer.get_name() == customer_name) {
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
                    cout << customer_name << " rented the vehicle for " << rental_period << " days." << endl;
                    cout << "Total rental cost: " << selected_vehicle->get_rental_rate() * rental_period << " rp" << endl;
                } else {
                    cout << "Invalid vehicle selection!" << endl;
                }
                return;
            }
        }
        cout << "Customer not found!" << endl;
    }

    void return_vehicle(string customer_name) {
        cout << customer_name << " returned the vehicle." << endl;
    }

   
};

//administrator menu
void admin_menu(Rental& system) {
    int choice;
    do {
        cout << "\n--- Administrator Menu ---\n";
        cout << "1. Add a new vehicle\n";
        cout << "2. Add a new customer\n";
        cout << "3. Display all vehicles\n";
        cout << "4. Display all customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string make, model, vehicle_type,type;
                int year, cargo_capacity, num_doors;
                float rate;
                cout << "Enter vehicle make: ";
                cin >> make;
                cout << "Enter vehicle model: ";
                cin >> model;
                cout << "Enter vehicle year: ";
                cin >> year;
                cout << "Enter rental rate: ";
                cin >> rate;
                cout << "Enter vehicle type (Bicycle, Bike, Car, Truck): ";
                cin >> vehicle_type;

                if (vehicle_type == "Bicycle") {
                    cout << "Enter type (Hybrid/ Fitness/ Road): ";
                    cin >> type;
                    system.add_vehicle(new Bicycle(make, model, year, rate, type));
                } 
                else if (vehicle_type == "Bike") {
                    cout << "Enter type (e.g., Sport): ";
                    cin >> type;
                    system.add_vehicle(new Bike(make, model, year, rate, type));
                } 
                else if (vehicle_type == "Car") {
                    cout << "Enter number of doors: ";
                    cin >> num_doors;
                    system.add_vehicle(new Car(make, model, year, rate, num_doors));
                } 
                else if (vehicle_type == "Truck") {
                    cout << "Enter cargo capacity: ";
                    cin >> cargo_capacity;
                    system.add_vehicle(new Truck(make, model, year, rate, cargo_capacity));
                }
                break;
            }
            case 2: {
                string name;
                int license_num;
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter customer license number: ";
                cin >> license_num;
                system.add_customer(Customer(name, license_num));
                break;
            }
            case 3:
                system.display_available_vehicles();
                break;
            case 4:
                system.display_all_customers();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Customer menu
void customer_menu(Rental& system, const string& customer_name) {
    int choice;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. Rent a vehicle\n";
        cout << "2. Return a vehicle\n";
        cout << "3. View available vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int rental_period;
                cout << "Enter rental period (in days): ";
                cin >> rental_period;
                system.rent_vehicle(customer_name, rental_period);
                break;
            }
            case 2:
                system.return_vehicle(customer_name);
                break;
            case 3:
                system.display_available_vehicles();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

int main(){
    Rental system;
    int user_type;
    string customer_name;

    cout << "Welcome to the Vehicle Rental System\n";
    cout << "Are you an administrator (1) or customer (2)? ";
    cin >> user_type;

    if (user_type == 1) {
        admin_menu(system);
    } 
    else if (user_type == 2) {
        cout << "Enter your name: ";
        cin >> customer_name;
        customer_menu(system, customer_name);
    } 
    else {
        cout << "Invalid input!\n";
    }

    return 0;
}

