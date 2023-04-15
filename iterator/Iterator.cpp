template <typename T>
class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() const = 0;
  virtual T& current() = 0;
};

template <typename T>
class MyCollection {
public:
  Iterator<T> GetIterator() {
    //...
  }
};

template <typename T>
class CollectionIterator : public Iterator<T> {
  MyCollection<T> mc;

public:
  CollectionIterator(const MyCollection<T>& c) : mc(c) {}

  void first() override {}
  void next() override {}
  bool isDone() const override {}
  T& current() override {}
};

void MyAlgorithm() {
  MyCollection<int> mc;

  Iterator<int> iter = mc.GetIterator();

  // 循环中的first、isDone、next、current都是虚函数调用，性能开销很大
  // STL中使用泛型编程的迭代器，在编译时就确定调用
  for (iter.first(); !iter.isDone(); iter.next()) {
    cout << iter.current() << endl;
  }
}
