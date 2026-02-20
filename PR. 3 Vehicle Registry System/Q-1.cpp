#include <iostream>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    // Constructor
    Vehicle(int id, string manu, string mod, int y) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
        totalVehicles++;
    }

    // Destructor
    ~Vehicle() {
        totalVehicles--;
    }

    // Setters
    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(string manu) { manufacturer = manu; }
    void setModel(string mod) { model = mod; }
    void setYear(int y) { year = y; }

    // Getters
    int getVehicleID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }

    void display() {
        cout << "\nVehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

int main() {
    Vehicle v1(101, "Toyota", "Fortuner", 2023);
    v1.display();

    cout << "\nTotal Vehicles: " << Vehicle::totalVehicles << endl;
    return 0;
}

 // output //
 
 Vehicle ID: 101
Manufacturer: Toyota
Model: Fortuner
Year: 2023

Total Vehicles: 1

--------------------------------
Process exited after 0.02085 seconds with return value 0
Press any key to continue . . .