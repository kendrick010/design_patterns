#include <iostream>
#include <vector>
#include <string>

// Forward declarations
class ConcreteElementA;
class ConcreteElementB;

// Visitor interface
class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA& element) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& element) = 0;
    virtual ~Visitor() = default;
};

// Element interface
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() = default;
};

// Concrete elements
class ConcreteElementA : public Element {
public:
    ConcreteElementA(std::string anAction) : theAction(anAction) {}

    void accept(Visitor& visitor) override {
        visitor.visitConcreteElementA(*this); // Pass *this as a reference
    }
    void doAction() { std::cout << "Action: " << theAction << std::endl; } // Void method
private:
    std::string theAction;
};

class ConcreteElementB : public Element {
public:
    ConcreteElementB(std::string anAction) : theAction(anAction) {}

    void accept(Visitor& visitor) override {
        visitor.visitConcreteElementB(*this); // Pass *this as a reference
    }
    void doAction() { std::cout << "Action: " << theAction << std::endl; } // Void method
private:
    std::string theAction;
};

// Concrete visitor implementing specific operations for ConcreteElementA and ConcreteElementB
class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA& element) override {
        std::cout << "ConcreteVisitor: Visiting ConcreteElementA" << std::endl;
        element.doAction(); // Call void method
    }

    void visitConcreteElementB(ConcreteElementB& element) override {
        std::cout << "ConcreteVisitor: Visiting ConcreteElementB" << std::endl;
        element.doAction(); // Call void method
    }
};

// Object structure that contains a collection of elements
class ObjectStructure {
public:
    void addElement(Element* element) {
        elements.push_back(element);
    }

    void accept(Visitor& visitor) {
        for (Element* element : elements) {
            element->accept(visitor);
        }
    }

private:
    std::vector<Element*> elements;
};

int main() {
    // Create concrete elements
    ConcreteElementA elementA("eating");
    ConcreteElementB elementB("sitting");

    // Create object structure and add elements
    ObjectStructure objectStructure;
    objectStructure.addElement(&elementA);
    objectStructure.addElement(&elementB);

    // Create concrete visitor
    ConcreteVisitor visitor;

    // Apply visitor to object structure
    objectStructure.accept(visitor);

    return 0;
}
