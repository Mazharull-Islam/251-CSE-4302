#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

class Car {
public:
    string brand;
    string model;
    int year;
    string fuelType;
    double mileage;

    
    Car(string b, string m, int y, string f, double mile) {
        brand = b;
        model = m;
        year = y;
        fuelType = f;
        mileage = mile;
    }

   
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
    }

    
    bool isFuelEfficient(double threshold = 15.0) {
        return mileage > threshold;
    }

    
    double calculateFuelConsumption(double distance) {
        if (fuelType == "Electric") {
            return 0.0; 
        }
        return distance / mileage;
    }

    
    double estimateFuelCost(double distance, double fuelPricePerLiter) {
        if (fuelType == "Electric") {
            return 0.0; 
        }
        double fuelConsumed = calculateFuelConsumption(distance);
        return fuelConsumed * fuelPricePerLiter;
    }
};


void displayFuelEfficiencyStatus(Car car) {
    if (car.isFuelEfficient()) {
        cout << "This car is fuel-efficient." << endl;
    } else {
        cout << "This car is not fuel-efficient." << endl;
    }
}


void displayFuelCost(Car car, double distance, double fuelPrice) {
    if (car.fuelType == "Electric") {
        cout << "This car is electric, efficiency measured in km/charge." << endl;
    } else {
        double fuelCost = car.estimateFuelCost(distance, fuelPrice);
        cout << "Estimated fuel cost for " << distance << " km: $" << fixed << setprecision(2) << fuelCost << endl;
    }
}

int main() {
    vector<Car> cars;
    int numCars;

    cout << "Enter the number of cars: ";
    cin >> numCars;

    
    for (int i = 0; i < numCars; ++i) {
        string brand, model, fuelType;
        int year;
        double mileage;

        cout << "Enter details for car " << i + 1 << endl;

        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Year: ";
        cin >> year;
        cout << "Fuel Type (Petrol/Diesel/Electric/Hybrid): ";
        cin >> fuelType;
        cout << "Mileage (km/l): ";
        cin >> mileage;

        
        cars.push_back(Car(brand, model, year, fuelType, mileage));
    }

    
    double petrolPrice = 0.89;
    double dieselPrice = 3.24;
    double hybridPrice = 2.45;
    double distance = 100.0; 

    
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << "\nCar " << i + 1 << ":" << endl;
        cars[i].displayInfo();
        displayFuelEfficiencyStatus(cars[i]);

        if (cars[i].fuelType == "Petrol") {
            displayFuelCost(cars[i], distance, petrolPrice);
        } else if (cars[i].fuelType == "Diesel") {
            displayFuelCost(cars[i], distance, dieselPrice);
        } else if (cars[i].fuelType == "Hybrid") {
            displayFuelCost(cars[i], distance, hybridPrice);
        } else if (cars[i].fuelType == "Electric") {
            displayFuelCost(cars[i], distance, 0); 
        }
        cout << endl;
    }

    return 0;
}
