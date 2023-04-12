// 文件分割器：将一个文件分割为若干个小文件
class FileSplitter {
  string m_filePath;
  int m_fileNumber;

  // 改变：添加进度条 违背依赖导致原则
  // 编译时依赖：ProgressBar是实现细节，不应该依赖实现细节
  // ProgressBar可能有很多方式(变化): GUI方式、非GUI方式等
  ProgressBar* m_progressBar;  // 扮演的角色：通知

public:
  FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar)
      : m_filePath(filePath),
        m_fileNumber(fileNumber),
        m_progressBar(progressBar) {}

  void split() {
    // 1.读取大文件

    // 2.分批次向小文件中写入
    for (int i = 0; i < m_fileNumber; i++) {
      //...

      // 改变：更新进度条
      float progressValue = m_fileNumber;
      progressValue = (i + 1) / progressValue;
      m_progressBar->setValue(progressValue);
    }
  }
};
