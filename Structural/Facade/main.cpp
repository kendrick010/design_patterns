#include <iostream>
#include <string>
#include <memory>

class Process1 {
protected:
    std::string operation = "Process 1";

public:
    Process1() {
        std::cout << "Initialized Process 1" << std::endl;
    }

    Process1(const Process1& aCopy) { *this = aCopy; }
    ~Process1() = default;
    Process1& operator=(const Process1& aCopy) {
        operation = aCopy.operation;
        return *this;
    }

    void start() {
        std::cout << "Comleted Process 1" << std::endl;
    }
};

class Process2 {
protected:
    std::string operation = "Process 2";

public:
    Process2() {
        std::cout << "Initialized Process 2" << std::endl;
    }

    Process2(const Process2& aCopy) { *this = aCopy; }
    ~Process2() = default;
    Process2& operator=(const Process2& aCopy) {
        operation = aCopy.operation;
        return *this;
    }

    void start() {
        std::cout << "Comleted Process 2" << std::endl;;
    }
};

class Process3 {
protected:
    std::string operation = "Process 3";

public:
    Process3() {
        std::cout << "Initialized Process 3" << std::endl;
    }

    Process3(const Process1& aCopy) { *this = aCopy; }
    ~Process3() = default;
    Process3& operator=(const Process3& aCopy) {
        operation = aCopy.operation;
        return *this;
    }

    void start() {
        std::cout << "Comleted Process 3" << std::endl;;
    }
};

class Facade {
protected:
    std::unique_ptr<Process1> process1;
    std::unique_ptr<Process2> process2;
    std::unique_ptr<Process3> process3;

public:
    Facade() {
        process1 = std::make_unique<Process1>();
        process2 = std::make_unique<Process2>();
        process3 = std::make_unique<Process3>();
    }

    Facade(const Facade& aCopy) { *this = aCopy; }
    ~Facade() = default;
    Facade& operator=(const Facade& aCopy) {
        process1 = std::make_unique<Process1>(*aCopy.process1);
        process2 = std::make_unique<Process2>(*aCopy.process2);
        process3 = std::make_unique<Process3>(*aCopy.process3);

        return *this;
    }

    void Operation1() {
        std::cout << "Starting Operation 1" << std::endl;
        process1->start();
        process2->start();
        //...
    };

    void Operation2() {
        process2->start();
        process3->start();
        //...
    };

    // operations...
};

int main() {
    Facade aFacade;

    aFacade.Operation1();

    return 0;
}
