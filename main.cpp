#include <iostream>
// #define _USE_BASE_HOGE

class Hoge {
 public:
  Hoge(){};
  ~Hoge(){};

 protected:  // C++ では private でも行ける。
  void Method1() { std::cout << "method1" << std::endl; }
  virtual void Method2() { std::cout << "method2" << std::endl; }
  virtual void Method3() { std::cout << "method3" << std::endl; }
  void Method4() { std::cout << "method4" << std::endl; }

 public:
  void ExecutePipeline() {
    this->Method1();
    this->Method2();
    this->Method3();
    this->Method4();
  }
};

class DerivedHoge : public Hoge {
 public:
  DerivedHoge(){};
  ~DerivedHoge(){};

 protected:  // C++ では private でも行ける。
  virtual void Method2() override {
    std::cout << "derived method2" << std::endl;
  }
  virtual void Method3() override {
    std::cout << "derived method3" << std::endl;
  }
};

int main() {
#ifdef _USE_BASE_HOGE
  Hoge hoge;
#else
  DerivedHoge hoge;
#endif

  hoge.ExecutePipeline();

  return 0;
}