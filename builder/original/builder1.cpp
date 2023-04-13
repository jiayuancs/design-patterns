
class House {
public:
  // 构建的过程是固定的
  // 这里不能写成构造函数，因为构造函数中调用虚函数是静态绑定
  // 子类的构造函数会先调用父类的构造函数，因此在父类的构造函数执行时，子类还没有进行构造，自然不能执行动态绑定
  void Init() {
    this->BuildPart1();

    for (int i = 0; i < 4; ++i) {
      this->BuildPart2();
    }

    bool flag = this->BuildPart3();

    if (flag) {
      this->BuildPart4();
    }

    this->BuildPart5();
  }

  virtual ~House() {}

protected:
  // 具体的方法是变化的
  virtual void BuildPart1() = 0;
  virtual void BuildPart2() = 0;
  virtual bool BuildPart3() = 0;
  virtual void BuildPart4() = 0;
  virtual void BuildPart5() = 0;
};

// 石头房
class StoneHouse {
protected:
  virtual void BuildPart1() {}
  virtual void BuildPart2() {}
  virtual bool BuildPart3() {}
  virtual void BuildPart4() {}
  virtual void BuildPart5() {}
};

int main() {
  House *phouse = new StoneHouse();
  phouse->Init();
}
