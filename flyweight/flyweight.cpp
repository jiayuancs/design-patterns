// 字体对象 只读 可共享
class Font {
private:
  // unique object key
  string key;

  // object state
  //....

public:
  Font(const string& key) {
    //...
  }
};

class FontFactory {
private:
  map<string, Font*> fontPool;

public:
  Font* GetFont(const string& key) {
    map<string, Font*>::iterator item = fontPool.find(key);

    // 如果需要的字体已存在于对象池，则直接返回
    if (item != footPool.end()) {
      return fontPool[key];
    } else {  // 反之，创建新的字体对象，并将其添加到对象池
      Font* font = new Font(key);
      fontPool[key] = font;
      return font;
    }
  }

  void clear() {
    //...
  }
};
