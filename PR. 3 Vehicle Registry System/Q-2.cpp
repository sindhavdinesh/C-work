#include <iostream>
using namespace std;

// Base Class
class Vehicle {
public:
    int id;
    Vehicle(int i) { id = i; }
};

// Single Inheritance
class Car : public Vehicle {
public:
    string fuelType;
    Car(int i, string fuel) : Vehicle(i) {
        fuelType = fuel;
    }
};

// Multilevel
class ElectricCar : public Car {
public:
    int batteryCapacity;
    ElectricCar(int i, string fuel, int battery)
        : Car(i, fuel) {
        batteryCapacity = battery;
    }
};

// Hierarchical
class Sedan : public Car {
public:
    Sedan(int i, string fuel) : Car(i, fuel) {}
};

class SUV : public Car {
public:
    SUV(int i, string fuel) : Car(i, fuel) {}
};

// Multiple
class Aircraft {
public:
    int flightRange;
    Aircraft(int range) {
        flightRange = range;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int i, string fuel, int range)
        : Car(i, fuel), Aircraft(range) {}
};

int main() {
    ElectricCar e(1, "Electric", 75);
    cout << "Electric Car Battery: " << e.batteryCapacity << endl;

    FlyingCar f(2, "Hybrid", 1000);
    cout << "Flying Car Range: " << f.flightRange << endl;

    return 0;
}

 // output //
 
 Electric Car Battery: 75
Flying Car Range: 1000

--------------------------------
Process exited after 0.298 seconds with return value 0
Press any key to continue . . .