### 概念

建造者模式是一种创建型设计模式，他通过将对象的构建过程与其表示分离，使得同样的构建过程可以创建不同的表示。

### 模式结构

* AbstractBuilder（抽象建造类）
* ConcreteBuilder（具体建造类）
* Product（产品类）
* Director（指挥者），负责按照特定顺序调用ConcreteBuilder生产产品

### 使用场景

1. 需要创建复杂对象时
2. 当构造函数的参数太长时
3. 当对象的创建过程需要分步骤进行，并且允许灵活控制创建的顺序和步骤时
