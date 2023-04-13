class ISplitter {
public:
  virtual void split() = 0;
  virtual ~ISplitter() {}
};

// 变化：增加了若干种文件分割器，分别适用于二进制、文本、图片、视频

class BinarySplitter : public ISplitter {};

class TxtSplitter : public ISplitter {};

class PictureSplitter : public ISplitter {};

class VideoSplitter : public ISplitter {};
