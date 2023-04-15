#include <iostream>
#include <string>

using namespace std;

enum class RequestType { REQ_HANDLER1, REQ_HANDLER2, REQ_HANDLER3 };

// 请求
class Reqest {
  string description;
  RequestType reqType;

public:
  Reqest(const string &desc, RequestType type)
      : description(desc), reqType(type) {}
  RequestType getReqType() const { return reqType; }
  const string &getDescription() const { return description; }
};

// 请求接收者
class ChainHandler {
  ChainHandler *nextChain;  // 链表指针
  void sendReqestToNextHandler(const Reqest &req) {
    if (nextChain != nullptr) nextChain->handle(req);
  }

protected:
  // 判断当前对象能够处理请求
  virtual bool canHandleRequest(const Reqest &req) = 0;
  // 处理请求
  virtual void processRequest(const Reqest &req) = 0;

public:
  ChainHandler() { nextChain = nullptr; }
  void setNextChain(ChainHandler *next) { nextChain = next; }

  // 如果当前对象能处理请求，则处理；反之，传递给链表中的下一个对象
  void handle(const Reqest &req) {
    if (canHandleRequest(req))
      processRequest(req);
    else
      sendReqestToNextHandler(req);
  }
};

class Handler1 : public ChainHandler {
protected:
  bool canHandleRequest(const Reqest &req) override {
    return req.getReqType() == RequestType::REQ_HANDLER1;
  }
  void processRequest(const Reqest &req) override {
    cout << "Handler1 is handle reqest: " << req.getDescription() << endl;
  }
};

class Handler2 : public ChainHandler {
protected:
  bool canHandleRequest(const Reqest &req) override {
    return req.getReqType() == RequestType::REQ_HANDLER2;
  }
  void processRequest(const Reqest &req) override {
    cout << "Handler2 is handle reqest: " << req.getDescription() << endl;
  }
};

class Handler3 : public ChainHandler {
protected:
  bool canHandleRequest(const Reqest &req) override {
    return req.getReqType() == RequestType::REQ_HANDLER3;
  }
  void processRequest(const Reqest &req) override {
    cout << "Handler3 is handle reqest: " << req.getDescription() << endl;
  }
};

int main() {
  // 请求传递链：h1 --> h2 --> h3
  Handler1 h1;
  Handler2 h2;
  Handler3 h3;
  h1.setNextChain(&h2);
  h2.setNextChain(&h3);

  // h3将处理这个请求
  Reqest req("process task ... ", RequestType::REQ_HANDLER3);
  h1.handle(req);
  return 0;
}
