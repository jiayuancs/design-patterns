enum TaxBase {
  CN_Tax,
  US_Tax,
  DE_Tax,
  FR_Tax  // 更改
};

class SalesOrder {
  TaxBase tax;

public:
  double CalculateTax() {
    //...

    // 含有很多条件判断语句的代码通常都需要Strategy模式
    if (tax == CN_Tax) {
      // CN***********
    } else if (tax == US_Tax) {
      // US***********
    } else if (tax == DE_Tax) {
      // DE***********
    } else if (tax == FR_Tax) {  // 更改 违背了开闭原则
      //...
    }

    //....
  }
};
