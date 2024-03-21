#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Observer interface
class Observer {
public:
    virtual void onNotify() const = 0;
    virtual ~Observer() = default;
};

class Observer1 : public Observer {
public:
    Observer1(std::string aName) : name(aName) {}

    void onNotify() const override { std::cout << name << std::endl; }

private:
    std::string name;
};

class Observer2 : public Observer{
public:
    Observer2(std::string aName) : name(aName) {}

    void onNotify() const override { std::cout << name << std::endl; }

private:
    std::string name;
};

class Observer3 : public Observer {
public:
    Observer3(std::string aName) : name(aName) {}

    void onNotify() const override { std::cout << name << std::endl; }

private:
    std::string name;
};

class Subject {
public:
    void addObserver(std::shared_ptr<Observer> anObserver) {
        mObservers.push_back(anObserver);
    }

    void removeObserver(std::shared_ptr<Observer> anObserver) {
        mObservers.erase(std::remove(mObservers.begin(), mObservers.end(), anObserver),
                         mObservers.end());
    }

    void notifyAll() {
        for (const auto& observer : mObservers)
            observer->onNotify();
    }

private:
    std::vector<std::shared_ptr<Observer>> mObservers;
};

int main() {
    Subject publisher;
    std::shared_ptr<Observer> observer1 = std::make_shared<Observer1>("Hello");
    std::shared_ptr<Observer> observer2 = std::make_shared<Observer2>("Hi");
    std::shared_ptr<Observer> observer3 = std::make_shared<Observer3>("Yo");

    publisher.addObserver(observer1);
    publisher.addObserver(observer2);
    publisher.addObserver(observer3);

    publisher.notifyAll();

    publisher.removeObserver(observer1);

    publisher.notifyAll();

    return 0;
}
