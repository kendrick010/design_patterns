#include <iostream>
#include <memory>
#include <string>

// Component interface (the base class)
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override { return "Simple coffee"; }

    double cost() const override { return 1.0; }
};

// Decorator base class
class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : theCoffee(coffee) {}

    std::string getDescription() const override { return theCoffee->getDescription(); }

    double cost() const override { return theCoffee->cost(); }

protected:
    std::shared_ptr<Coffee> theCoffee;
};

// Concrete decorator: Milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override { return theCoffee->getDescription() + " w/ milk"; }

    double cost() const override { return theCoffee->cost() + 0.5; }
};

// Concrete decorator: Sugar
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override { return theCoffee->getDescription() + " w/ sugar"; }

    double cost() const override { return theCoffee->cost() + 0.2; }
};

int main() {
    std::shared_ptr<Coffee> coffee = std::make_shared<SimpleCoffee>();
    std::cout << "Description: " << coffee->getDescription() << ", Cost: $" << coffee->cost() << std::endl;

    // Add milk to the coffee
    coffee = std::make_shared<MilkDecorator>(coffee);
    std::cout << "Description: " << coffee->getDescription() << ", Cost: $" << coffee->cost() << std::endl;

    // Add sugar to the coffee
    coffee = std::make_shared<SugarDecorator>(coffee);
    std::cout << "Description: " << coffee->getDescription() << ", Cost: $" << coffee->cost() << std::endl;

    return 0;
}
