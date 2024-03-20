#include <iostream>

class Rectangle {
public:
    Rectangle(double aWidth, double aHeight) : width(aWidth), height(aHeight) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double calculateArea() const { return width * height; }

private:
    double width;
    double height;
};

class Square {
public:
    Square(double sideLength) : sideLength(sideLength) {}

    double getSideLength() const { return sideLength; }
    double calculateArea() const { return sideLength * sideLength; }

private:
    double sideLength;
};

class Adapter : public Square {
public:
    Adapter(const Rectangle& rectangle)
            : Square(std::min(rectangle.getWidth(), rectangle.getHeight())), rectangle(rectangle) {}

private:
    const Rectangle& rectangle;
};


int main() {
    Rectangle rectangle(5.0, 4.0);
    Adapter adapter(rectangle);

    std::cout << "Rectangle Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Square Adapter Area: " << adapter.calculateArea() << std::endl;

    return 0;
}

