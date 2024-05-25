#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <memory>

using namespace std;

class Prototype {
public:
    virtual ~Prototype() = default;
    virtual unique_ptr<Prototype> clone() const = 0;
    virtual void show() const = 0;
};

class ConcretePrototype1 : public Prototype {
public:
    ConcretePrototype1(string name) : m_name(name) {}

    unique_ptr<Prototype> clone() const override {
        return make_unique<ConcretePrototype1>(*this);
    }

    void show() const override {
        cout << "ConcretePrototype1: " << m_name << endl;
    }
private:
    string m_name;
};

class ConcretePrototype2 : public Prototype {
public:
    ConcretePrototype2(int value) : m_value(value) {}

    unique_ptr<Prototype> clone() const override {
        return make_unique<ConcretePrototype2>(*this);
    }

    void show() const override {
        cout << "ConcretePrototype2: " << m_value << endl;
    }
private:
    int m_value;
};

int main(){
    unique_ptr<Prototype> ptr1 = make_unique<ConcretePrototype1>("XieFeng");
    unique_ptr<Prototype> ptr2 = make_unique<ConcretePrototype2>(21);
    ptr1->show();
    ptr2->show();
    
    unique_ptr<Prototype> clone1 = ptr1->clone();
    unique_ptr<Prototype> clone2 = ptr2->clone();
    clone1->show();
    clone2->show();

   system("pause");
   return 0;
}

