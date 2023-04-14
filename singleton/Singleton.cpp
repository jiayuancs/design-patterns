

class Singleton {
private:
  // 构造函数设置为私有的
  Singleton();
  Singleton(const Singleton& other);

public:
  static Singleton* getInstance();
  static Singleton* m_instance;
};

// 静态成员定义
Singleton* Singleton::m_instance = nullptr;

// 线程非安全版本
// （单线程下使用此方法）
Singleton* Singleton::getInstance() {
  if (m_instance == nullptr) {
    m_instance = new Singleton();
  }
  return m_instance;
}

// 线程安全版本，但锁的代价过高，因为普通的读操作也需要获取锁
// （多线程下，如果对性能要求不高，则可以用此方法）
Singleton* Singleton::getInstance() {
  Lock lock;  // 执行完该函数，lock才会被释放
  if (m_instance == nullptr) {
    m_instance = new Singleton();
  }
  return m_instance;
}

// 双检查锁，但由于内存读写reorder不安全
// （任何时候都不要用此方法）
Singleton* Singleton::getInstance() {
  if (m_instance == nullptr) {
    Lock lock;
    if (m_instance == nullptr) {
      m_instance = new Singleton();
    }
  }
  return m_instance;
}

// C++ 11版本之后的跨平台实现 (volatile)
// （多线程下，对性能要求较高，则用该方法）
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
  Singleton* tmp = m_instance.load(std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_acquire);  // 获取内存fence
  if (tmp == nullptr) {
    std::lock_guard<std::mutex> lock(m_mutex);
    tmp = m_instance.load(std::memory_order_relaxed);
    if (tmp == nullptr) {
      tmp = new Singleton;
      std::atomic_thread_fence(std::memory_order_release);  // 释放内存fence
      m_instance.store(tmp, std::memory_order_relaxed);
    }
  }
  return tmp;
}
