// 程序界面
class MainForm : public Form {
  TextBox* txtFilePath;
  TextBox* txtFileNumber;

  // 改变：添加进度条
  ProgressBar* progressBar;

public:
  void Button1_Click() {
    string filePath = txtFilePath->getText();
    int number = atoi(txtFileNumber->getText().c_str());

    FileSplitter splitter(filePath, number, progressBar);

    splitter.split();
  }
};
