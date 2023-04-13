# Prototype

`Prototype`针对那些结构复杂的对象，对于这些对象而言，他们的创建过程通常会很复杂，直接`new`得到的对象不能满足要求，需要对该对象执行一系列的操作，使对象处于某种中间状态。这时，直接克隆已存在的对象比从头开始创建要方便的多。

相比于[Factory Method](../factory_method/)，Prototype相当于将[ISplitterFactory.cpp](../factory_method/refactored/ISplitterFactory.cpp)中的两个类进行了合并

合并前：

```C++
// 抽象类
class ISplitter {
public:
  virtual void split() = 0;
  virtual ~ISplitter() {}
};

// 工厂基类
class SplitterFactory {
public:
  virtual ISplitter* CreateSplitter() = 0;
  virtual ~SplitterFactory() {}
};
```

合并后：

```C++
// 抽象类
class ISplitter {
public:
  virtual void split() = 0;
  virtual ISplitter* CreateSplitter() = 0;
  virtual ~ISplitter() {}
};
```

重命名：

```C++
// 抽象类
class ISplitter {
public:
  virtual void split() = 0;
  virtual ISplitter* clone() = 0;  // 通过克隆自己来创建对象
  virtual ~ISplitter() {}
};
```
