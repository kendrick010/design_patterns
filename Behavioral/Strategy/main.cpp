#include <iostream>
#include <memory>

// Strategy interface
class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() = default;
};

// Concrete strategy 1
class ConcreteStrategy1 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Concrete Strategy 1" << std::endl;
    }
};

// Concrete strategy 2
class ConcreteStrategy2 : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Concrete Strategy 2" << std::endl;
    }
};

// Context class
class Context {
private:
    std::shared_ptr<Strategy> strategy;

public:
    Context(std::shared_ptr<Strategy> strategy) : strategy(strategy) {}

    // Set strategy dynamically
    void setStrategy(std::shared_ptr<Strategy> newStrategy) {
        strategy = newStrategy;
    }

    // Execute strategy
    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    // Create strategies
    auto strategy1 = std::make_shared<ConcreteStrategy1>();
    auto strategy2 = std::make_shared<ConcreteStrategy2>();

    // Create context with initial strategy
    Context context(strategy1);

    // Execute initial strategy
    context.executeStrategy();

    // Change strategy dynamically
    context.setStrategy(strategy2);

    // Execute new strategy
    context.executeStrategy();

    return 0;
}
