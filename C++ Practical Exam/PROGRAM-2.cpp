#include <iostream>
using namespace std;

class Car {
private:
    string model;
    int year;
    float speed;

public:
    // Setter Methods
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    void setSpeed(float s) { speed = s; }

    // Getter Methods
    string getModel() { return model; }
    int getYear() { return year; }
    float getSpeed() { return speed; }
};

int main() {
    Car c;

    // Accessing private data using public functions
    c.setModel("Toyota Fortuner");
    c.setYear(2023);
    c.setSpeed(120.5);

    cout << "----- Car Details -----" << endl;
    cout << "Model : " << c.getModel() << endl;
    cout << "Year  : " << c.getYear() << endl;
    cout << "Speed : " << c.getSpeed() << " km/h" << endl;

    return 0;
}

// output //

----- Car Details -----
Model : Toyota Fortuner
Year  : 2023
Speed : 120.5 km/h

