#include<iostream>
using namespace std;

class Car{
    private:
    string make;
    string model;
    double fuelCapacity;
    double fuelLevel;
    public:
     Car(string make, string model, double fuelCapacity, double fuelLevel = 0)
        : make(make), model(model), fuelCapacity(fuelCapacity), fuelLevel(fuelLevel) {}

    Car operator+(double fuel)const
    {
        double newFuelLevel = fuelLevel + fuel;
        if (newFuelLevel > fuelCapacity)
        {
            newFuelLevel = fuelCapacity;
        }
        return Car(make, model, fuelCapacity, newFuelLevel);
        
    }

    Car operator-(double fuel)const
    {
        double newFuelLevel = fuelLevel - fuel;
        if (newFuelLevel < 0)
        {
            newFuelLevel = fuelCapacity;
        }
        return Car(make, model, fuelCapacity, newFuelLevel);
    }

    Car& operator+=(double fuel)
    {
        fuelLevel += fuel;
        if (fuelLevel > fuelCapacity)
        {
            fuelLevel = fuelCapacity;
        }
        return *this;
    }

    bool operator==(const Car& other)const
    {
        return(make == other.make && model == other.model && fuelCapacity == other.fuelCapacity);
    }

    bool operator<(const Car& other)const
    {
        return(fuelLevel < other.fuelLevel);
    }

    bool operator>(const Car& other)const
    {
        return(fuelLevel > other.fuelLevel);
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << "Car Make: " << car.make << ", Model: " << car.model
           << ", Fuel Capacity: " << car.fuelCapacity << "L"
           << ", Fuel Level: " << car.fuelLevel << "L";
        return os;
    }

    friend istream& operator>>(istream& is, Car& car) {
        cout << "Enter Car Make: ";
        is >> car.make;
        cout << "Enter Car Model: ";
        is >> car.model;
        cout << "Enter Fuel Capacity (L): ";
        is >> car.fuelCapacity;
        cout << "Enter Fuel Level (L): ";
        is >> car.fuelLevel;
        if (car.fuelLevel > car.fuelCapacity) {
            car.fuelLevel = car.fuelCapacity;
        }
        return is;
    }

    double getFuelLevel() const{
        return fuelLevel;
    }
};

int main() {

    Car car1("Toyota", "Corolla", 50);
    Car car2("Honda", "Civic", 45, 10);


    car1 = car1 + 20.0;
    cout << car1 << endl;

    car2 = car2 - 5.0; 
    cout << car2 << endl;

    car1 += 10.0; 
    cout << car1 << endl;

    if (car1 == car2) {
        cout << "Car1 and Car2 are the same." << endl;
    } else {
        cout << "Car1 and Car2 are different." << endl;
    }

    if (car1 < car2) {
        cout << "Car1 has less fuel than Car2." << endl;
    } else if (car1 > car2) {
        cout << "Car1 has more fuel than Car2." << endl;
    } else {
        cout << "Both cars have the same fuel level." << endl;
    }

    Car car3("", "", 0);
    cin >> car3;
    cout << car3 << endl;
    
    return 0;
}
