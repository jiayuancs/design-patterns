#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Component {
public:
  virtual void process() = 0;
  virtual ~Component() {}
};

// 树节点
class Composite : public Component {
  string name;
  list<Component*> elements;  // 子节点

public:
  Composite(const string& s) : name(s) {}

  void add(Component* element) { elements.push_back(element); }
  void remove(Component* element) { elements.remove(element); }

  void process() {
    // 1. process current node
    cout << name << endl;

    // 2. process leaf nodes
    for (auto& e : elements) e->process();  // 多态调用
  }
};

// 叶子节点
class Leaf : public Component {
  string name;

public:
  Leaf(string s) : name(s) {}

  void process() {
    // process current node
    cout << name << endl;
  }
};

void Invoke(Component& c) {
  //...
  // 如果在c.process中没有实现多态的递归调用，则这里就需要判断c是叶子节点还是其他节点（一对多的关系）
  // Composite将这种一对多的关系转化为了一对一的关系，因此这里不再需要判断
  c.process();
  //...
}

int main() {
  Composite root("root");
  Composite treeNode1("treeNode1");
  Composite treeNode2("treeNode2");
  Composite treeNode3("treeNode3");
  Composite treeNode4("treeNode4");
  Leaf leaf1("leaf1");
  Leaf leaf2("leaf2");

  root.add(&treeNode1);
  treeNode1.add(&treeNode2);
  treeNode2.add(&leaf1);

  root.add(&treeNode3);
  treeNode3.add(&treeNode4);
  treeNode4.add(&leaf2);

  // 对于所有节点，具有一致性
  Invoke(root);
  Invoke(leaf2);
  Invoke(treeNode3);

  return 0;
}
