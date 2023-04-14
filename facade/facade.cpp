class SubSystem1 {
  void Compile1();
  void Compile2();
};

class SubSystem2 {
  void Assemble1();
  void Assemble2();
};

class SubSystem3 {
  void Link1();
  void Link2();
}

class Facade {
public:
  void Method1() {
    sub_system_1_.Compile1();
    sub_system_2_.Assemble2();
    sub_system_3_.Link1();
  }

  void Method2() {
    sub_system_1_.Compile1();
    sub_system_2_.Assemble2();
    sub_system_3_.Link3();
  }

private:
  SubSystem1 sub_system_1_;
  SubSystem2 sub_system_2_;
  SubSystem3 sub_system_3_;
};

int main() {
  Facade facade;
  facade.Method1();
  return 0;
}
