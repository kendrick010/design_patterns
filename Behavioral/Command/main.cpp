#include <iostream>
#include <vector>
#include <memory>

// Receiver interface
class Receiver {
public:
    virtual void action() = 0;
    virtual ~Receiver() = default;
};

// Concrete Receiver
class ConcreteReceiver : public Receiver {
public:
    void action() override {
        std::cout << "Performing action by ConcreteReceiver." << std::endl;
    }
};

// Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Concrete Command
class ConcreteCommand : public Command {
public:
    ConcreteCommand(std::shared_ptr<Receiver> receiver) : receiver(receiver) {}

    void execute() override {
        receiver->action();
    }

private:
    std::shared_ptr<Receiver> receiver;
};

// Invoker
class Invoker {
public:
    void setCommand(std::shared_ptr<Command> aCommand) {
        command = aCommand;
    }

    void executeCommand() {
        if (command) command->execute();
        else std::cout << "No command set." << std::endl;
    }

private:
    std::shared_ptr<Command> command;
};

int main() {
    // Create receiver and command
    std::shared_ptr<Receiver> receiver = std::make_shared<ConcreteReceiver>();
    std::shared_ptr<Command> command = std::make_shared<ConcreteCommand>(receiver);

    // Create invoker and set the command
    Invoker invoker;
    invoker.setCommand(command);

    // Execute the command
    invoker.executeCommand();

    return 0;
}
