//
// Created by Kendrick Nguyen on 3/19/24.
//

#ifndef CAR_H
#define CAR_H

class Tire {
public:
    Tire (std::string aName, double aPressure) : name(aName), pressure(aPressure) {}

protected:
    std::string name;
    double pressure;
};

class SimpleTire : public Tire {
public:
    SimpleTire() : Tire("SimpleTire", 1.1) {}
};

class FancyTire : public Tire {
public:
    FancyTire() : Tire("FancyTire", 12.3) {}
};

class Body {
public:
    Body (std::string aBrand, int aGrade) : brand(aBrand), grade(aGrade){}

protected:
    std::string brand;
    int grade;
};

class SimpleBody : public Body {
public:
    SimpleBody() : Body("toyota", 10) {}
};

class FancyBody : public Body {
public:
    FancyBody() : Body("honda", 20) {}
};

class Car {
public:
    Car(std::string aName) : name(aName) {}

    void setTire(std::unique_ptr<Tire> aTire) { tire = std::move(aTire); }
    void setBody(std::unique_ptr<Body> aBody) { body = std::move(aBody); }

protected:
    std::string name;
    std::unique_ptr<Tire> tire;
    std::unique_ptr<Body> body;
};


#endif //CAR_H
