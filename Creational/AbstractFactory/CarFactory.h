//
// Created by Kendrick Nguyen on 3/19/24.
//

#include <memory>
#include "Car.h"

#ifndef ABSTRACTFACTORY_CARFACTORY_H
#define ABSTRACTFACTORY_CARFACTORY_H

class CarFactory {
public:
    virtual std::unique_ptr<Car> buildCar() = 0;
    virtual ~CarFactory() = default;
protected:
    std::unique_ptr<Car> car;
    virtual std::unique_ptr<Tire> buildTire() = 0;
    virtual std::unique_ptr<Body> buildBody() = 0;
};

class SimpleCarFactory : public CarFactory {
protected:
    std::unique_ptr<Car> buildCar() override {
        std::unique_ptr<Car> car = std::make_unique<Car>("SimpleCar");
        car->setTire(buildTire());
        car->setBody(buildBody());

        return car;
    }

    std::unique_ptr<Tire> buildTire() override { return std::make_unique<SimpleTire>(); }
    std::unique_ptr<Body> buildBody() override { return std::make_unique<SimpleBody>(); }
};

class FancyCarFactory : public CarFactory {
protected:
    std::unique_ptr<Car> buildCar() override {
        std::unique_ptr<Car> car = std::make_unique<Car>("FancyCar");
        car->setTire(buildTire());
        car->setBody(buildBody());

        return car;
    }

    std::unique_ptr<Tire> buildTire() override { return std::make_unique<FancyTire>(); }
    std::unique_ptr<Body> buildBody() override { return std::make_unique<FancyBody>(); }
};


#endif //ABSTRACTFACTORY_CARFACTORY_H
