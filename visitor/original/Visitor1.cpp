#include <iostream>
using namespace std;

class Element {
public:
  virtual void Func1() = 0;

  // 变化：如果Element需要添加新的行为，则所有的子类都要进行override
  // 违背开闭原则
  virtual void Func2(int data) = 0;
  virtual void Func3(int data) = 0;
  //...

  virtual ~Element() {}
};

class ElementA : public Element {
public:
  void Func1() override {
    //...
  }

  // 变化
  void Func2(int data) override {
    //...
  }
};

class ElementB : public Element {
public:
  void Func1() override {
    //***
  }

  // 变化
  void Func2(int data) override {
    //***
  }
};
