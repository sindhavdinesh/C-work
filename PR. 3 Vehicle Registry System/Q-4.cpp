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

int main() {
    Vehicle vehicles[100];
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Vehicle";
        cout << "\n2. View Vehicles";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1) {
            int id;
            string name;
            cout << "Enter ID and Name: ";
            cin >> id >> name;
            vehicles[count++] = Vehicle(id, name);
        }
        else if(choice == 2) {
            for(int i = 0; i < count; i++) {
                vehicles[i].display();
            }
        }

    } while(choice != 3);

    return 0;
}

// output // 

1. Add Vehicle
2. View Vehicles
3. Exit
Enter Choice: 1
Enter ID and Name: 10 Car

1. Add Vehicle
2. View Vehicles
3. Exit
Enter Choice: 1
Enter ID and Name: 20 bike

1. Add Vehicle
2. View Vehicles
3. Exit
Enter Choice: 2
ID: 10 Name: Car
ID: 20 Name: bike

1. Add Vehicle
2. View Vehicles
3. Exit
Enter Choice: 3

--------------------------------
Process exited after 173.2 seconds with return value 0
Press any key to continue . . .