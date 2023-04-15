enum NetworkState {
  Network_Open,
  Network_Close,
  Network_Connect,
  // 变化
};

class NetworkProcessor {
  NetworkState state;

public:
  void Operation1() {
    // 对象的状态如果改变，则其行为也进行变化
    if (state == Network_Open) {
      //**********
      state = Network_Close;
    } else if (state == Network_Close) {
      //..........
      state = Network_Connect;
    } else if (state == Network_Connect) {
      //$$$$$$$$$$
      state = Network_Open;
    }
    // 变化
  }

  void Operation2() {
    if (state == Network_Open) {
      //**********
      state = Network_Connect;
    } else if (state == Network_Close) {
      //.....
      state = Network_Open;
    } else if (state == Network_Connect) {
      //$$$$$$$$$$
      state = Network_Close;
    }
    // 变化
  }

  void Operation3() {
    // 变化
  }
};
