#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <string>
using namespace std;

class Car {
public:
    void addParts(const string& part) {
        parts.push_back(part);
    }
    void showParts() const {
        cout << "Car parts: ";
        for (const auto& part : parts) {
            cout << part << ", ";
        }
        cout << endl;
    }
private:
    vector<string> parts;
};

class CarBuilder {
public:
    virtual ~CarBuilder() = default;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildBody() = 0;
    virtual shared_ptr<Car> getCar() = 0;
};

class SportsCarBuilder : public CarBuilder {
public:
    SportsCarBuilder() {
        car = make_shared<Car>();
    }

    void buildEngine() override {
        car->addParts("Sports Engine");
    }

    void buildWheels() override {
        car->addParts("Sports Wheels");
    }

    void buildBody() override {
        car->addParts("Sports Body");
    }

    shared_ptr<Car> getCar() override {
        return car;
    }

private:
    shared_ptr<Car> car;
};

class SUVCarBuilder : public CarBuilder {
public:
    SUVCarBuilder() {
        car = make_shared<Car>();
    }

    void buildEngine() override {
        car->addParts("SUV Engine");
    }

    void buildWheels() override {
        car->addParts("SUV Wheels");
    }

    void buildBody() override {
        car->addParts("SUV Body");
    }

    shared_ptr<Car> getCar() override {
        return car;
    }

private:
    shared_ptr<Car> car;
};

class Director {
public:
    Director(shared_ptr<CarBuilder> builder) : builder(builder) {}

    void construct () {
        builder->buildEngine();
        builder->buildWheels();
        builder->buildBody();
    }

    shared_ptr<Car> getCar() {
        return builder->getCar();
    }

private:
    shared_ptr<CarBuilder> builder;
};

int main() {
    shared_ptr<CarBuilder> sportsCarBuilder = make_shared<SportsCarBuilder>();
    Director director(sportsCarBuilder);
    director.construct();
    shared_ptr<Car> sportsCar = director.getCar();
    sportsCar->showParts();

    shared_ptr<CarBuilder> suvCarBuilder = make_shared<SUVCarBuilder>();
    Director director2(suvCarBuilder);
    director2.construct();
    shared_ptr<Car> suvCar = director2.getCar();
    suvCar->showParts();


    system("pause");
    return 0;
}