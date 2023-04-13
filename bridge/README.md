# Bridge

## Bridge1

类的总数是$1 + n + n*m$，其中`n`是平台实现部分的变化数目，`m`是业务抽象部分的变化数目

这里的业务抽象部分是不能进行组合的，细品与[Decorator](../decorator/)的区别

```mermaid
%% 不绘制类图，是因为这里只是用来展示继承关系
%% 使用流程图更加简洁

%% 从下向上绘制
graph BT
	PCMessagerBase --> Messager
    MobileMessagerBase --> Messager
    PCMessagerLite --> PCMessagerBase
    PCMessagerPerfect --> PCMessagerBase
	MobileMessagerLite --> MobileMessagerBase
    MobileMessagerPerfect --> MobileMessagerBase
```

## Bridge2

`Messager`类成员中含有指向`MessagerImp`的指针

类的总数变为$1 + n + 1 + m$

```mermaid
graph BT
	PCMessagerTmp --> MessagerImp
    MobileMessagerImp --> MessagerImp
    MessagerLite --> Messager
    MessagerPerfect --> Messager
```
