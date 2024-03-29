
class Memento {
  string state;
  //..
public:
  Memento(const string& s) : state(s) {}
  string getState() const { return state; }
  void setState(const string& s) { state = s; }
};

class Originator {
  string state;
  //....
public:
  Originator() {}
  // 创建快照
  Memento createMomento() {
    Memento m(state);
    return m;
  }
  // 恢复到m中保存的状态
  void setMomento(const Memento& m) { state = m.getState(); }
};

int main() {
  Originator orginator;

  // 捕获对象状态，存储到备忘录
  Memento mem = orginator.createMomento();

  //... 改变orginator状态

  // 从备忘录中恢复
  orginator.setMomento(memento);
}
