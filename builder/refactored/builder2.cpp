
class House {
  //....
};

class HouseBuilder {
public:
  House* GetResult() { return pHouse; }
  virtual ~HouseBuilder() {}

protected:
  House* pHouse;
  virtual void BuildPart1() = 0;
  virtual void BuildPart2() = 0;
  virtual void BuildPart3() = 0;
  virtual void BuildPart4() = 0;
  virtual void BuildPart5() = 0;
};

class StoneHouse : public House {};

// 各部件的构造过程
class StoneHouseBuilder : public HouseBuilder {
protected:
  virtual void BuildPart1() {
    // pHouse->Part1 = ...;
  }
  virtual void BuildPart2() {}
  virtual void BuildPart3() {}
  virtual void BuildPart4() {}
  virtual void BuildPart5() {}
};


// 指导者：各部件的装配过程
// 当不是很复杂时，可以将HouseDirector与HouseBuilder合并
class HouseDirector {
public:
  HouseBuilder* pHouseBuilder;

  HouseDirector(HouseBuilder* pHouseBuilder) {
    this->pHouseBuilder = pHouseBuilder;
  }

  House* Construct() {
    pHouseBuilder->BuildPart1();

    for (int i = 0; i < 4; i++) {
      pHouseBuilder->BuildPart2();
    }

    bool flag = pHouseBuilder->BuildPart3();

    if (flag) {
      pHouseBuilder->BuildPart4();
    }

    pHouseBuilder->BuildPart5();

    return pHouseBuilder->GetResult();
  }
};

int main() {
  StoneHouseBuilder stone_house_builder;
  HouseDirector director(stone_house_builder);
  House* pHouse = director.Construct();
  return 0;
}
