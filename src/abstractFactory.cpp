#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
using namespace std;

class ShipBody {
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() = default;
};

class WoodyBody : public ShipBody {
public:
    string getShipBody() override {
        return string("用<木材>制作船体\n");
    }
};

class IronBody : public ShipBody {
    string getShipBody() override {
        return string("用<钢铁>制作船体\n");
    }
};

class MetalBody : public ShipBody {
    string getShipBody() override {
        return string("用<合金>制作船体\n");
    }
};

class Weapon {
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() = default;
};

class Gun : public Weapon {
public:
    string getWeapon() override {
        return string("配备的武器是<枪>\n");
    }
};

class Cannon : public Weapon {
public:
    string getWeapon() override {
        return string("配备的武器是<自动机关炮>\n");
    }
};

class Laser : public Weapon {
public:
    string getWeapon() override {
        return string("配备的武器是<激光>\n");
    }
};

class Engine {
public:
    virtual string getEngine() = 0;
    virtual ~Engine() = default;
};

class Human : public Engine {
public:
    string getEngine() override {
        return string("使用<人力驱动>\n");
    }
};

class Diesel : public Engine {
public:
    string getEngine() override {
        return string("使用<内燃机驱动>\n");
    }
};

class Nuclear : public Engine {
public:
    string getEngine() override {
        return string("使用<核能驱动>\n");
    }
};

class Ship {
private:
    shared_ptr<ShipBody> m_body;
    shared_ptr<Engine> m_engine;
    shared_ptr<Weapon> m_weapon;
public:
    Ship(shared_ptr<ShipBody> body, shared_ptr<Weapon> weapon, shared_ptr<Engine> engine) {
        m_body = body;
        m_weapon = weapon;
        m_engine = engine;
    }

    string getProperty() {
        string info = m_body->getShipBody() + m_weapon->getWeapon() + m_engine->getEngine();
        return info;
    }
};

class ShipFactory {
public:
    virtual shared_ptr<Ship> createShip() = 0;
    virtual ~ShipFactory() = default;
};

class BasicShipFactory : public ShipFactory {
public:
    shared_ptr<Ship> createShip() override {
        shared_ptr<WoodyBody> shipBody = make_shared<WoodyBody>();
        shared_ptr<Gun> weapon = make_shared<Gun>();
        shared_ptr<Human> engine = make_shared<Human>();
        shared_ptr<Ship> ship = make_shared<Ship>(shipBody, weapon, engine);
        cout << "<标准型战舰>生产完成" << endl;
        return ship;
    }
};

class NormalShipFactory : public ShipFactory {
public:
    shared_ptr<Ship> createShip() override {
        shared_ptr<IronBody> shipBody = make_shared<IronBody>();
        shared_ptr<Cannon> weapon = make_shared<Cannon>();
        shared_ptr<Diesel> engine = make_shared<Diesel>();
        shared_ptr<Ship> ship = make_shared<Ship>(shipBody, weapon, engine);
        cout << "<普通型战舰>生产完成" << endl;
        return ship;
    }
};

class ExtensionShipFactory : public ShipFactory {
public:
    shared_ptr<Ship> createShip() override {
        shared_ptr<MetalBody> shipBody = make_shared<MetalBody>();
        shared_ptr<Laser> weapon = make_shared<Laser>();
        shared_ptr<Nuclear> engine = make_shared<Nuclear>();
        shared_ptr<Ship> ship = make_shared<Ship>(shipBody, weapon, engine);
        cout << "<进阶型战舰>生产完成" << endl;
        return ship;
    }
};

void test() {
    shared_ptr<ShipFactory> factory = make_shared<ExtensionShipFactory>();
    shared_ptr<Ship> ship = factory->createShip();
    cout << ship->getProperty();
}

int main() {
    test();

    system("pause");
    return 0;
}