class MainForm : public Form {
  TextBox* txtFilePath;
  TextBox* txtFileNumber;
  ProgressBar* progressBar;

public:
  void Button1_Click() {
    // 等号左边是抽象，等号右边是实现细节
    // 违反：依赖倒置原则
    ISplitter* splitter = new BinarySplitter();  // 依赖具体类

    splitter->split();
  }
};
