#include <iostream>
using namespace std;

class Visitor;

// Vistor模式的前提：Element子类的数量是稳定的
class Element {
public:
  virtual void accept(Visitor& visitor) = 0;  // 第一次多态辨析

  virtual ~Element() {}
};

class ElementA : public Element {
public:
  void accept(Visitor& visitor) override { visitor.visitElementA(*this); }
};

class ElementB : public Element {
public:
  void accept(Visitor& visitor) override {
    visitor.visitElementB(*this);  // 第二次多态辨析
  }
};

class Visitor {
public:
  virtual void visitElementA(ElementA& element) = 0;
  virtual void visitElementB(ElementB& element) = 0;

  virtual ~Visitor() {}
};

//==================================

// 扩展1
class Visitor1 : public Visitor {
public:
  void visitElementA(ElementA& element) override {
    cout << "Visitor1 is processing ElementA" << endl;
  }

  void visitElementB(ElementB& element) override {
    cout << "Visitor1 is processing ElementB" << endl;
  }
};

// 扩展2
class Visitor2 : public Visitor {
public:
  void visitElementA(ElementA& element) override {
    cout << "Visitor2 is processing ElementA" << endl;
  }

  void visitElementB(ElementB& element) override {
    cout << "Visitor2 is processing ElementB" << endl;
  }
};

int main() {
  Visitor2 visitor;
  ElementB elementB;
  // double dispatch 需要两次动态绑定
  // 1. accept虚函数
  // 2. visitElementB虚函数
  elementB.accept(visitor);

  ElementA elementA;
  elementA.accept(visitor);

  return 0;
}
