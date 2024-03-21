#include <iostream>
#include <memory>
#include <string>

// Abstract Handler
class Handler {
public:
    virtual ~Handler() = default;
    virtual void handleRequest(const std::string& request) = 0;
    virtual void setNextHandler(std::shared_ptr<Handler> next) = 0;
};

// Concrete Handler 1
class ConcreteHandler1 : public Handler {
private:
    std::shared_ptr<Handler> nextHandler;

public:
    void handleRequest(const std::string& request) override {
        if (request == "Handler1") {
            std::cout << "Handled by ConcreteHandler1" << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "Passing request to next handler from ConcreteHandler1" << std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "End of chain reached. Request not handled." << std::endl;
        }
    }

    void setNextHandler(std::shared_ptr<Handler> next) override {
        nextHandler = next;
    }
};

// Concrete Handler 2
class ConcreteHandler2 : public Handler {
private:
    std::shared_ptr<Handler> nextHandler;

public:
    void handleRequest(const std::string& request) override {
        if (request == "Handler2") {
            std::cout << "Handled by ConcreteHandler2" << std::endl;
        } else if (nextHandler != nullptr) {
            std::cout << "Passing request to next handler from ConcreteHandler2" << std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "End of chain reached. Request not handled." << std::endl;
        }
    }

    void setNextHandler(std::shared_ptr<Handler> next) override {
        nextHandler = next;
    }
};

int main() {
    // Create handlers using smart pointers
    auto handler1 = std::make_shared<ConcreteHandler1>();
    auto handler2 = std::make_shared<ConcreteHandler2>();

    // Set up chain of responsibility
    handler1->setNextHandler(handler2);

    // Process requests
    handler1->handleRequest("Handler1");
    handler1->handleRequest("Handler2");
    handler1->handleRequest("Handler3");

    return 0;
}
