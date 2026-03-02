#include <iostream>
using namespace std;

class Device {
protected:
    string brand;
    float price;

public:
    Device(string b, float p) {
        brand = b;
        price = p;
    }

    virtual float calculateDiscount() = 0;
    virtual void display() = 0;

    virtual ~Device() {}
};

class Laptop : public Device {
public:
    Laptop(string b, float p) : Device(b, p) {}

    float calculateDiscount() {
        return price * 0.10; 
    }

    void display() {
        cout << "Laptop Brand: " << brand
             << " | Discount: " << calculateDiscount() << endl;
    }
};

class Smartphone : public Device {
public:
    Smartphone(string b, float p) : Device(b, p) {}

    float calculateDiscount() {
        return price * 0.05; 
    }

    void display() {
        cout << "Smartphone Brand: " << brand
             << " | Discount: " << calculateDiscount() << endl;
    }
};

int main() {
    Device* devices[2];

    devices[0] = new Laptop("HP", 50000);
    devices[1] = new Smartphone("Apple", 70000);

    cout << "----- Discount Details -----" << endl;

    for(int i = 0; i < 2; i++) {
        devices[i]->display();
    }

    for(int i = 0; i < 2; i++) {
        delete devices[i];
    }

    return 0;
}

// output //

----- Discount Details -----
Laptop Brand: HP | Discount: 5000
Smartphone Brand: Apple | Discount: 3500