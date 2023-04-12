// 程序库开发人员
class Library {
public:
  // 稳定 template method
  void Run() {
    Step1();

    if (Step2()) {  // 支持变化 ==> 虚函数的多态调用
      Step3();
    }

    for (int i = 0; i < 4; i++) {
      Step4();  // 支持变化 ==> 虚函数的多态调用
    }

    Step5();
  }
  virtual ~Library() {}

protected:
  // 稳定的代码写成非虚函数
  void Step1() {  // 稳定
    //.....
  }
  void Step3() {  // 稳定
    //.....
  }
  void Step5() {  // 稳定
    //.....
  }

  // 变化的代码写成(纯)虚函数
  virtual bool Step2() = 0;  // 变化
  virtual void Step4() = 0;  // 变化
};
