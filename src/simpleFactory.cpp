#include <iostream>
#include <stdlib.h>
using namespace std;

// 实现一个饮料类，根据客户需要返回对应的饮料对象

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
    static BeverageBase* createBeverage(const string& type) {
        BeverageBase* ptr = nullptr;
        if (type == "coffee") {
            ptr = new Coffee();
        } else if (type == "milk") {
            ptr = new Milk();
        }
        return ptr;
    }
};

int main() {
    BeverageBase* beverage1 = BeverageFactory::createBeverage("coffee");
    if (beverage1 != nullptr) {
        beverage1->drink();
        delete beverage1;
    }

    BeverageBase* beverage2 = BeverageFactory::createBeverage("milk");
    beverage2->drink();
    delete beverage2;


    system("pause");
    return 0;
}