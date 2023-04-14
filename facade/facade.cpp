class SubSystem1 {
  void Compile();
};

class SubSystem2 {
  void Assemble();
};

class SubSystem3 {
  void Link();
}

class Facade {
public:
  void Method() {
    sub_system_1_.Compile();
    sub_system_2_.Assemble();
    sub_system_3_.Link();
  }

private:
  SubSystem1 sub_system_1_;
  SubSystem2 sub_system_2_;
  SubSystem3 sub_system_3_;
};

int main() {
  Facade facade;
  facade.Method();
  return 0;
}
