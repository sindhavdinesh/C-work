#include <iostream>
using namespace std;

class Device {
private:
    string brand;
    int powerConsumption;

public:
    void setDetails(string b, int p) {
        brand = b;
        powerConsumption = p;
    }

    string getBrand() { return brand; }
    int getPower() { return powerConsumption; }
};

class Laptop : public Device {
public:
    void display() {
        cout << "Laptop Brand: " << getBrand()
             << " | Power: " << getPower() << "W" << endl;
    }
};

class Smartphone : public Device {
public:
    void display() {
        cout << "Smartphone Brand: " << getBrand()
             << " | Power: " << getPower() << "W" << endl;
    }
};

int main() {
    Laptop l;
    Smartphone s;

    l.setDetails("Dell", 65);
    s.setDetails("Samsung", 15);

    cout << "----- Device Details -----" << endl;
    l.display();
    s.display();

    return 0;
}

// output //

----- Device Details -----
Laptop Brand: Dell | Power: 65W
Smartphone Brand: Samsung | Power: 15W