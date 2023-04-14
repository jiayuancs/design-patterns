class ISubject {
public:
  virtual void process();
};

class RealSubject : public ISubject {
public:
  virtual void process() {
    //....
  }
};

class ClientApp {
  ISubject* subject;

public:
  ClientApp() {
    // 由于某种原因：
    // 1. 对象创建的开销很大
    // 2. 需要安全控制
    // 3. 需要进程外的访问
    // ...
    // 直接创建会给使用者、或者系统结构带来很多麻烦
    subject = new RealSubject();
  }

  void DoTask() {
    //...
    subject->process();

    //....
  }
};
