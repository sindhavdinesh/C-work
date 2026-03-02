#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    // Parameterized Constructor
    Student(string n, int r) {
        name = n;
        rollNumber = r;
    }

    void display() {
        cout << "Name: " << name 
             << " | Roll Number: " << rollNumber << endl;
    }
};

int main() {
    // Array of objects using parameterized constructor
    Student s[3] = {
        Student("Rahul", 101),
        Student("Priya", 102),
        Student("Amit", 103)
    };

    cout << "----- Student Details -----" << endl;
    for(int i = 0; i < 3; i++) {
        s[i].display();
    }

    return 0;
}

// output //

----- Student Details -----
Name: Rahul | Roll Number: 101
Name: Priya | Roll Number: 102
Name: Amit | Roll Number: 103

