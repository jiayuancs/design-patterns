
class TaxStrategy {
public:
  virtual double Calculate(const Context& context) = 0;
  virtual ~TaxStrategy() {}
};

class CNTax : public TaxStrategy {
public:
  virtual double Calculate(const Context& context) override {
    //***********
  }
};

class USTax : public TaxStrategy {
public:
  virtual double Calculate(const Context& context) override {
    //***********
  }
};

class DETax : public TaxStrategy {
public:
  virtual double Calculate(const Context& context) override {
    //***********
  }
};

// 扩展
//*********************************
class FRTax : public TaxStrategy {
public:
  virtual double Calculate(const Context& context) override {
    //.........
  }
};

class SalesOrder {
private:
  TaxStrategy* strategy;

public:
  // 使用工厂模式返回策略对象，需要修改工厂但不会要修改SalesOrder
  SalesOrder(StrategyFactory* strategyFactory) {
    this->strategy = strategyFactory->NewStrategy();
  }
  ~SalesOrder() { delete this->strategy; }

public
  double CalculateTax() {
    //...
    Context context();

    double val = strategy->Calculate(context);  // 多态调用
    //...
  }
};
