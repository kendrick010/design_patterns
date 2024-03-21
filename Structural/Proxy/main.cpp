#include <iostream>
#include <memory>
#include <string>

// A proxy acts as an intermediary between a client object and a target object, allowing the
// proxy to control or add additional functionalities when accessing the target object.

// Interface
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// Concrete implementation of Image
class RealImage : public Image {
public:
    RealImage(const std::string& aFileName) : fileName(aFileName) {
        loadImageFromDisk();
    }

    void display() override { std::cout << "Displaying image: " << fileName << std::endl; }

private:
    void loadImageFromDisk() { std::cout << "Loading image: " << fileName << " from disk." << std::endl; }

    std::string fileName;
};

// Proxy class
class ImageProxy : public Image {
public:
    ImageProxy(const std::string& aFileName) : fileName(aFileName) {}

    void display() override {
        if (!realImage) realImage = std::make_unique<RealImage>(fileName);

        realImage->display();
    }

private:
    std::unique_ptr<RealImage> realImage;
    std::string fileName;
};

int main() {
    // Create a proxy for the image
    std::shared_ptr<Image> imageProxy = std::make_shared<ImageProxy>("example.jpg");

    imageProxy->display();

    return 0;
}
