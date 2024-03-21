#include <iostream>

// Abstract base class defining the template method
class AbstractClass {
public:
    // Template method that defines the algorithm
    void templateMethod() {
        step1(); // Abstract step
        step2(); // Concrete step
        step3(); // Abstract step
    }

    virtual ~AbstractClass() = default;

protected:
    // Abstract steps to be implemented by subclasses
    virtual void step1() = 0;
    virtual void step3() = 0;

    // Concrete step implemented by the base class
    void step2() {
        std::cout << "AbstractClass: Performing step 2" << std::endl;
    }
};

// Concrete subclass implementing abstract steps
class ConcreteClass : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClass: Performing step 1" << std::endl;
    }

    void step3() override {
        std::cout << "ConcreteClass: Performing step 3" << std::endl;
    }
};

int main() {
    // Create an instance of the concrete class
    ConcreteClass concreteObject;

    // Call the template method
    concreteObject.templateMethod();

    return 0;
}
