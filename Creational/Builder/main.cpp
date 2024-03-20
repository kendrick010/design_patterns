#include <iostream>
#include <memory>
#include <string>

class Product {
public:
    void setNum(int const& aNum) { num = aNum; }
    void setString(std::string const& aString) { string = aString; }

private:
    int num;
    std::string string;
};

class Builder {
public:
    virtual ~Builder() = default;

    virtual void buildNum() = 0;
    virtual void buildString() = 0;
    virtual std::unique_ptr<Product> getProduct() = 0;
};

class ConcreteBuilder: public Builder {
public:
    ConcreteBuilder(): product{std::make_unique<Product>()} {}

    void buildNum() override { product->setNum(10); }
    void buildString() override { product->setString("Testing"); }

    std::unique_ptr<Product> getProduct() override { return std::move(product); }

private:
    std::unique_ptr<Product> product;
};

// Create more builders of derived Builder class ...

class Director {
public:
    void set_builder(std::shared_ptr<Builder> const& aBuilder) { builder = aBuilder; }

    void construct() {
        builder->buildNum();
        builder->buildString();
    }

private:
    std::shared_ptr<Builder> builder;
};

int main() {
    std::shared_ptr<Builder> builder = std::make_shared<ConcreteBuilder>();
    std::shared_ptr<Director> director = std::make_shared<Director>();

    director->set_builder(builder);
    director->construct();

    std::unique_ptr<Product> product = builder->getProduct();

    return 0;
}