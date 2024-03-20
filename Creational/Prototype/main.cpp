#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Car {
public:
    Car (std::string aModel, std::string aColor) : model(aModel), color(aColor) { }

    void setColor (std::string aColor) { color = aColor; }

    virtual ~Car() = default;
    virtual std::unique_ptr<Car> clone() const = 0;

private:
    std::string model;
    std::string color;
};

class RaceCar : public Car {
public:
    RaceCar (std::string aModel, std::string aColor, int aSpeed) : Car (aModel, aColor), maxSpeed(aSpeed) { }

    std::unique_ptr<Car> clone() const override {
        return std::make_unique<RaceCar>(*this);
    }

    void setSpeed (int aSpeed) { maxSpeed = aSpeed; }

private:
    int maxSpeed;
};

int main() {
    std::vector<std::unique_ptr<Car>> cars;

    const auto prototype = std::make_unique<RaceCar>("Toyota", "Blue", 100);

    auto redCar = prototype->clone();
    redCar->setColor("red");

    return 0;
}
