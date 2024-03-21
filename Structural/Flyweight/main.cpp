#include <iostream>
#include <map>
#include <memory>
#include <string>

// Flyweight interface
class Font {
public:
    virtual void render(const std::string& character) const = 0;
    virtual ~Font() = default;
};

// Concrete Flyweight: Shared font style
class SharedFont : public Font {
public:
    SharedFont(const std::string& aFont) : font(aFont) {}

    void render(const std::string& character) const override {
        std::cout << "Rendering character '" << character << "' with font: " << font << std::endl;
    }

private:
    std::string font;
};

// Flyweight factory
class FontFactory {
public:
    std::shared_ptr<Font> getFont(const std::string& font) {
        // Check if the font already exists in the map
        if (fonts.find(font) == fonts.end()) {
            // If not, create a new SharedFont object and store it in the map
            fonts[font] = std::make_shared<SharedFont>(font);
        }
        // Return the shared pointer to the font
        return fonts[font];
    }

private:
    std::map<std::string, std::shared_ptr<Font>> fonts;
};

int main() {
    // Create a FontFactory
    FontFactory fontFactory;

    // Get shared fonts from the factory
    std::shared_ptr<Font> timesNewRoman = fontFactory.getFont("Times New Roman");
    std::shared_ptr<Font> arial = fontFactory.getFont("Arial");
    std::shared_ptr<Font> timesNewRomanAgain = fontFactory.getFont("Times New Roman");

    // Render characters using shared fonts
    timesNewRoman->render("A");
    arial->render("B");
    timesNewRomanAgain->render("C");

    // Check if the fonts are shared
    std::cout << (timesNewRoman == timesNewRomanAgain ? "Times New Roman is shared" : "Times New Roman is not shared") << std::endl;
    std::cout << (timesNewRoman == arial ? "Times New Roman and Arial are the same" : "Times New Roman and Arial are different") << std::endl;

    return 0;
}