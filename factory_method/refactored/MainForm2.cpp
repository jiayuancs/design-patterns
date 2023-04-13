// MainForm不再依赖任何细节
class MainForm : public Form {
  SplitterFactory* factory;  // 工厂  依赖抽象

public:
  MainForm(SplitterFactory* factory) { this->factory = factory; }

  void Button1_Click() {
    ISplitter* splitter = factory->CreateSplitter();  // 多态new 依赖抽象

    splitter->split();
  }
};
