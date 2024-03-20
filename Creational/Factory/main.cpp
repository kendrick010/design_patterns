#include <iostream>
#include <memory>
#include <string>

class AbstractShape {
public:
    virtual std::string getName() = 0;
    virtual ~AbstractShape() = default;
};

class Circle : public AbstractShape {
public:
    std::string getName() override { return "Circle"; }
};

class Triangle : public AbstractShape {
public:
    std::string getName() override { return "Triangle"; }
};

class Square : public AbstractShape {
public:
    std::string getName() override { return "Square"; }
};

class FactoryShape {
public:
    std::unique_ptr<AbstractShape> getShape(const std::string& aShape) {
        if ("circle" == aShape) return std::make_unique<Circle>();
        else if ("triangle" == aShape) return std::make_unique<Triangle>();
        else if ("square" == aShape) return std::make_unique<Square>();
        else return nullptr; // Handle unknown shape
    }
};

int main() {
    FactoryShape factory;
    std::unique_ptr<AbstractShape> circle = factory.getShape("circle");
    if (circle) std::cout << circle->getName() << std::endl;

    std::unique_ptr<AbstractShape> triangle = factory.getShape("triangle");
    if (triangle) std::cout << triangle->getName() << std::endl;

    std::unique_ptr<AbstractShape> square = factory.getShape("square");
    if (square) std::cout << square->getName() << std::endl;

    return 0;
}
