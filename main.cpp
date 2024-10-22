#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct{
      int date;
      int month;
      int year;
}Date;

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
    
    void rent_vehicle(Vehicle* vehicle, int rental_period){
        cout << name << " rented a vehicle for " << rental_period << " days." << endl;
        cout << "Total rental cost: " << vehicle->get_rental_rate() * rental_period <<"rp"<< endl;
        vehicle->display_info();
    }
    
    void return_vehicle(Vehicle& vehicle){
        cout << name << " returned the vehicle." << endl;
    }
    
};

class Rental{
    Customer customer; 
    Vehicle* vehicle;
    Date rental_date;
    int rental_period;
    float total_cost;

    public:
    Rental(Customer& cust, Vehicle* vehicle, Date& date, int rental_period): 
        customer(cust),vehicle(vehicle),rental_date(date),rental_period(rental_period) {total_cost = cal_total_cost();}

    float cal_total_cost(){
        return (rental_period)*(vehicle->get_rental_rate());
    }

    void display_rental_info(){
        cout<<"\n--- Rental Info ---\n"<<endl;
        cout<<"Customer Information: "<<endl;
        customer.display_customer_info();
        cout<<"Vehicle Information: "<<endl;
        vehicle->display_info();
        cout<<"Rental Date: "<<rental_date.date<<"/"<<rental_date.month<<"/"<<rental_date.year<<"/"<<endl;
        cout<<"Rental Period"<<rental_period<<" days"<<endl;
        cout<<"Total Rent: "<<total_cost<<" rps"<<endl;
        cout<<"-------------------\n";

    }
};

int main(){
    vector<Customer> customers;
    vector<Vehicle*> vehicles;

    customers.push_back(Customer("John Doe", 12345));
    customers.push_back(Customer("Jane Smith", 67890));
    customers.push_back(Customer("Alice Johnson", 23456));
    customers.push_back(Customer("David Wilson", 56789));
    customers.push_back(Customer("Michael Brown", 34567));
    customers.push_back(Customer("Emily Davis", 45678));
    customers.push_back(Customer("Sophia Martinez", 67891));

    vehicles.push_back(new Bicycle("Giant", "Escape 3", 2022, 13.5, "Hybrid"));
    vehicles.push_back(new Bicycle("Cannondale", "Quick 4", 2020, 14.0, "Fitness"));
    vehicles.push_back(new Bicycle("Specialized", "Sirrus 2.0", 2021, 12.5, "Road"));
    vehicles.push_back(new Bike("Honda", "CBR500R", 2021, 35.0, "Sport"));
    vehicles.push_back(new Bike("Kawasaki", "Ninja 650", 2023, 45.0, "Sport"));
    vehicles.push_back(new Car("Honda", "Civic", 2021, 55.0, 4));
    vehicles.push_back(new Car("Nissan", "Altima", 2020, 50.0, 4));
    vehicles.push_back(new Car("Ford", "Mustang", 2022, 60.0, 2));
    vehicles.push_back(new Truck("Chevrolet", "Silverado 1500", 2021, 85.0, 1200));
    vehicles.push_back(new Truck("RAM", "1500", 2019, 90.0, 1100));

}
