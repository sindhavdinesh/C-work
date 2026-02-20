#include <iostream>
using namespace std;

class Vehicle {
public:
    int id;
    string name;

    Vehicle() {}

    Vehicle(int i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

class VehicleRegistry {
private:
    Vehicle vehicles[5];
    int count;

public:
    VehicleRegistry() { count = 0; }

    void addVehicle(int id, string name) {
        vehicles[count++] = Vehicle(id, name);
    }

    void displayAll() {
        for(int i = 0; i < count; i++) {
            vehicles[i].display();
        }
    }
};

int main() {
    VehicleRegistry vr;
    vr.addVehicle(1, "Car");
    vr.addVehicle(2, "Bike");

    vr.displayAll();

    return 0;
}

 // output //
 
 ID: 1 Name: Car
ID: 2 Name: Bike

--------------------------------
Process exited after 0.3059 seconds with return value 0
Press any key to continue . . .