#include <iostream>

class Singleton {
public:
    Singleton (const Singleton&) = delete;
    static Singleton& get() { return s_Instance; }

private:
    Singleton() {}  // On purpose

    static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int main() {
    auto& aSingleton = Singleton::get();

    return 0;
}
