#include <iostream>
#include <string>

class Car {
private:
    std::string registrationNumber;
    int topSpeed;
    int currentSpeed;
    double distanceTraveled;

public:
    Car(std::string regNum, int topSpd) : registrationNumber(regNum), topSpeed(topSpd) {
        currentSpeed = 0;
        distanceTraveled = 2000.0;
    }

    void accelerate(int speedChange) {
        currentSpeed += speedChange;
        if (currentSpeed > topSpeed) currentSpeed = topSpeed;
        if (currentSpeed < 0) currentSpeed = 0;
        std::cout << "Car " << registrationNumber << " speed change: " << speedChange
            << " km/h, New Speed: " << currentSpeed << " km/h\n";
    }

    void travel(double hours) {
        distanceTraveled += currentSpeed * hours;
        std::cout << "Car " << registrationNumber << " traveled for " << hours
            << " hours, New Distance: " << distanceTraveled << " km\n";
    }

    int getCurrentSpeed() const {
        return currentSpeed;
    }

    void printDetails() const {
        std::cout << "Registration Number: " << registrationNumber
            << ", Top Speed: " << topSpeed
            << ", Current Speed: " << currentSpeed
            << ", Distance Traveled: " << distanceTraveled << " km\n";
    }
};

int main() {
    Car myCar("ABC-123", 142);
    myCar.accelerate(30);
    myCar.travel(1.5);
    myCar.accelerate(70);
    myCar.travel(2);
    myCar.accelerate(50);
    myCar.travel(0.5);
    myCar.accelerate(-200);
    myCar.travel(1);

    myCar.printDetails();

    return 0;
}
