# Design Patterns

## GOF-23 模式分类

从目的来看：
- 创建型（Creational）模式：将对象的部分创建工作延迟到子
类或者其他对象，从而应对需求变化为对象创建时具体类型实
现引来的冲击。
- 结构型（Structural）模式：通过类继承或者对象组合获得更灵
活的结构，从而应对需求变化为对象的结构带来的冲击。
- 行为型（Behavioral）模式：通过类继承或者对象组合来划分
类与对象间的职责，从而应对需求变化为多个交互的对象带来的冲击。

从范围来看：
- 类模式处理类与子类的静态关系。
- 对象模式处理对象间的动态关系。 

## 从封装变化角度对模式分类

- 组件协作
  - [Template Method](./template_method/)
  - [Strategy](./strategy/)
  - [Observer/Event](./observer/)
- 单一职责
  - [Decorator](./decorator/)
  - [bridge](./bridge/)
