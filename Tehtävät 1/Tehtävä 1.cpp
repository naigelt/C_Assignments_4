#include <iostream>
#include <string>

class Car {
private:
    std::string registrationNumber;
    int topSpeed;
    int currentSpeed;
    double distanceTraveled;

public:
    // Constructor
    Car(std::string regNum, int topSpd) : registrationNumber(regNum), topSpeed(topSpd) {
        currentSpeed = 0;
        distanceTraveled = 0.0;
    }

    // Method to print car details
    void printDetails() const {
        std::cout << "Registration Number: " << registrationNumber
            << ", Top Speed: " << topSpeed
            << ", Current Speed: " << currentSpeed
            << ", Distance Traveled: " << distanceTraveled << " km\n";
    }
};

int main() {
    // Create a new Car object
    Car myCar("ABC-123", 142);

    // Print the details of the created car
    myCar.printDetails();

    return 0;
}
