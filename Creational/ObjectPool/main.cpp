#include <iostream>
#include <memory>
#include <vector>

class Object {
public:
    void doSomething() { std::cout << "Hello" << std::endl; }
};

class ObjectPool {
protected:
    std::vector<std::shared_ptr<Object>> pool;

public:
    ObjectPool(size_t size) { }

    std::shared_ptr<Object> acquiredObject() {
        if (!pool.empty()) {
            auto obj = pool.back();
            pool.pop_back();
            return obj;
        }

        return nullptr;
    }

    void releaseObject(std::shared_ptr<Object> obj) {
        pool.push_back(obj);
    }
};

int main() {
    ObjectPool pool(3);     // Create a pool of max size 3

    auto obj1 = pool.acquiredObject();
    auto obj2 = pool.acquiredObject();
    auto obj3 = pool.acquiredObject();

    pool.releaseObject(obj1);
    pool.releaseObject(obj2);
    pool.releaseObject(obj3);

    return 0;
}
