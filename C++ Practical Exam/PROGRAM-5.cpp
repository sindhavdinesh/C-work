#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;
    virtual void move() = 0;
    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    void makeSound() {
        cout << "Lion Roars!" << endl;
    }

    void move() {
        cout << "Lion Runs on Land." << endl;
    }
};

class Fish : public Animal {
public:
    void makeSound() {
        cout << "Fish Makes Blub Sound!" << endl;
    }

    void move() {
        cout << "Fish Swims in Water." << endl;
    }
};

int main() {
    Animal* animals[2];

    animals[0] = new Lion();
    animals[1] = new Fish();

    cout << "----- Animal Behaviour -----" << endl;

    for(int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->move();
        cout << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}

// output //

----- Animal Behaviour -----
Lion Roars!
Lion Runs on Land.

Fish Makes Blub Sound!
Fish Swims in Water.