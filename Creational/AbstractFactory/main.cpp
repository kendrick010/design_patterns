#include <memory>
#include <string>
#include "CarFactory.h"

std::unique_ptr<Car> assembleAndDisplayCar(std::unique_ptr<CarFactory>& factory) {
    std::unique_ptr<Car> car = factory->buildCar();
    return car;
}

int main() {
    const std::string& carType = "ca";
    std::unique_ptr<CarFactory> factory;

    if ("simple" == carType)
        factory = std::make_unique<SimpleCarFactory>();
    else
        factory = std::make_unique<FancyCarFactory>();

    std::unique_ptr<Car> car = assembleAndDisplayCar(factory); // Pass the unique_ptr by value, not by reference

    return 0;
}
