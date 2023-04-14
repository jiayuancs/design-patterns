# Singleton

## 内存读写reorder问题


内存读写reorder不安全是指在多线程程序中，由于编译器、CPU等因素的影响，程序执行时可能会改变原本的执行顺序，导致程序的行为与预期不一致，从而出现问题。

在`双检查锁`版本中，可能会出现内存读写reorder问题：

```C++
Singleton* Singleton::getInstance() {
  if (m_instance == nullptr) {
    Lock lock;
    if (m_instance == nullptr) {
      m_instance = new Singleton();
    }
  }
  return m_instance;
}
```
`new`表达式通常被认为执行如下三个步骤：
1. 分配一块内存
2. 在该内存上执行构造函数
3. 返回指向该内存的指针

在多线程中，上述三个步骤有可能被`reorder`，变为：
1. 分配一块内存
2. 返回指向该内存的指针
3. 在该内存上执行构造函数

假设线程A已经执行完步骤2，但还没有开始执行或者没有执行完步骤3

此时，线程B开始调用`Singleton::getInstance()`函数，这时`m_instance!=nullptr`，因此函数直接返回`m_instance`，
`m_instance`指向的是一块未构造完成的对象的内存空间，线程B如果对`m_instance`进行读写，则导致错误

