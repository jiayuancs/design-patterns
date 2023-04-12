// 只在以下情况我们才允许多重继承:
// 最多只有一个基类是非抽象类，其它基类都是抽象类(这里的IProgress是抽象类)
class MainForm : public Form, public IProgress {
  TextBox* txtFilePath;
  TextBox* txtFileNumber;

  ProgressBar* progressBar;

public:
  void Button1_Click() {
    string filePath = txtFilePath->getText();
    int number = atoi(txtFileNumber->getText().c_str());

    ConsoleNotifier cn;

    FileSplitter splitter(filePath, number);

    // 这里无论添加多少个观察者，FileSplitter都是稳定的
    splitter.addIProgress(this);  // 订阅通知
    splitter.addIProgress(&cn);   // 订阅通知

    splitter.split();

    splitter.removeIProgress(this);
  }

  virtual void DoProgress(float value) { progressBar->setValue(value); }
};

// 以.的形式展示进度条
class ConsoleNotifier : public IProgress {
public:
  virtual void DoProgress(float value) { cout << "."; }
};
