#include <iostream>
#include <stdlib.h>
using namespace std;

// ʵ��һ�������࣬���ݿͻ���Ҫ���ض�Ӧ�����϶���

class BeverageBase {
public:
    virtual void drink() = 0;
    virtual ~BeverageBase() {}
};

class Coffee : public BeverageBase {
public:
    void drink () override  {
        cout << "Drinking coffee" << endl;
    }

    ~Coffee() {
        cout << "coffee drinked" << endl;
    }
};

class Milk : public BeverageBase {
public:
    void drink() override {
        cout << "Drinking milk" << endl;
    }
    ~Milk() {
        cout << "milk drinked" << endl;
    }
};

class BeverageFactory {
public:
    virtual BeverageBase* createBeverage() = 0;
    virtual ~BeverageFactory() {}
};

class CoffeeFactory : public BeverageFactory {
public:
    BeverageBase* createBeverage() override {
        return new Coffee();
    }
};

class MilkFactory : public BeverageFactory {
    BeverageBase* createBeverage() override {
        return new Milk();
    }
};

int main() {
    BeverageFactory* factory = nullptr;
    BeverageBase* beverage = nullptr;

    // �ȿ���
    factory = new CoffeeFactory();
    beverage = factory->createBeverage();
    beverage->drink();
    delete beverage;
    delete factory;

    // ��ţ��
    factory = new MilkFactory();
    beverage = factory->createBeverage();
    beverage->drink();
    delete beverage;
    delete factory;

    system("pause");
    return 0;
}