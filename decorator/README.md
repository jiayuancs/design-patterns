# Decorator

## Decorator1

类的总数是 $1 + n + n*(2^m - 1)$ ，其中`n`是组件数量（文件流、网络流、内存流等），`m`是操作数量（加密、缓存等）

因为这里的操作是可以进行**组合**的，所以操作的数量应该是:

$$\sum_{k=1}^{m}C_{m}^{k} = 2^m - 1$$

![](../images/decorator1.png)

## Decorator3

![](../images/decorator3.png)
