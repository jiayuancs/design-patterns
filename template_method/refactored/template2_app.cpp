// 应用程序开发人员
class Application : public Library {
protected:
  bool Step2() override {
    //... 子类重写实现
  }

  void Step4() override {
    //... 子类重写实现
  }
};

int main() {
  Library* pLib = new Application();
  lib->Run();

  delete pLib;
}
