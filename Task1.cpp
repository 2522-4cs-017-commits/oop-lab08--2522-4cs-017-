#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo; 

public:
    Vehicle(string r) {
        regNo = r; 
    }

    virtual double toll() = 0;
    virtual string type() = 0;

    void showInfo() {
        cout << type() << " " << regNo << ": toll Rs. " << toll() << endl;
    }

    virtual ~Vehicle() {}
};


class Car : public Vehicle {
public:
    Car(string r) : Vehicle(r) {}
    double toll() override { return 150; }
    string type() override { return "Car"; }
};

class Bus : public Vehicle {
public:
    Bus(string r) : Vehicle(r) {}
    double toll() override { return 300; }
    string type() override { return "Bus"; }
};


class Truck : public Vehicle {
private:
    int axles;
public:
    Truck(string r, int a) : Vehicle(r) {
        axles = a;
    }
    double toll() override { return 200 + 100 * axles; }
    string type() override { return "Truck"; }
};

int main() {
   
    Vehicle* lane[4];
    lane[0] = new Car("LEA-1234");
    lane[1] = new Bus("KHI-555");
    lane[2] = new Truck("ISB-909", 3); 
    lane[3] = new Car("RWP-77");

    double totalToll = 0;

    for (int i = 0; i < 4; i++) {
        lane[i]->showInfo();
        totalToll += lane[i]->toll();
    }

    cout << "Total collected: Rs. " << totalToll << endl;

    
    for (int i = 0; i < 4; i++) {
        delete lane[i];
    }

    return 0;
}