#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Car {
private:
    std::string registrationNumber;
    int topSpeed;
    int currentSpeed;
    double distanceTraveled;

public:
    Car() : registrationNumber("Unknown"), topSpeed(0), currentSpeed(0), distanceTraveled(0.0) {}

    Car(std::string regNum, int topSpd) : registrationNumber(regNum), topSpeed(topSpd), currentSpeed(0), distanceTraveled(0.0) {}

    void setDetails(std::string regNum, int topSpd) {
        registrationNumber = regNum;
        topSpeed = topSpd;
    }

    void accelerate(int speedChange) {
        currentSpeed += speedChange;
        if (currentSpeed > topSpeed) currentSpeed = topSpeed;
        if (currentSpeed < 0) currentSpeed = 0;
    }

    void travel(double hours) {
        distanceTraveled += currentSpeed * hours;
    }

    double getDistanceTraveled() const {
        return distanceTraveled;
    }

    std::string getRegistrationNumber() const {
        return registrationNumber;
    }

    void printDetails() const {
        std::cout << "Registration Number: " << registrationNumber
            << ", Top Speed: " << topSpeed
            << ", Current Speed: " << currentSpeed
            << ", Distance Traveled: " << distanceTraveled << " km\n";
    }
};

int main() {
    srand(time(nullptr));

    Car cars[10];
    for (int i = 0; i < 10; ++i) {
        cars[i].setDetails("ABC-" + std::to_string(i + 1), 100 + rand() % 101);
    }

    bool raceOver = false;
    std::string winner;
    while (!raceOver) {
        for (int i = 0; i < 10; ++i) {
            cars[i].accelerate(-10 + rand() % 26);
            cars[i].travel(1);

            if (cars[i].getDistanceTraveled() >= 10000 && !raceOver) {
                raceOver = true;
                winner = cars[i].getRegistrationNumber();
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        cars[i].printDetails();
    }

    std::cout << "\nThe winner of the race is: " << winner << std::endl;

    return 0;
}
