// #define DEBUG
#include <iostream>

/// @brief First base class
class B1 {
private:
  int b1;

public:
  B1(int _b1) : b1{_b1} { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  /// @brief Print `b1`
  virtual auto show() const -> void {
    std::cout << "b1: " << b1 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

/// @brief Second base class
class B2 {
private:
  int b2;

public:
  B2(int _b2) : b2{_b2} { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  /// @brief print `b2`
  auto show() const -> void {
    std::cout << "b2: " << b2 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

/// @brief First dauther class
class D1 : virtual private B1, virtual public B2 {
private:
  int d1;

public:
  D1(int _b1, int _b2, int _d1) : B1{_b1}, B2{_b2}, d1{_d1} {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  /// @brief Print `d1`
  auto show() const -> void override {
    std::cout << "d1: " << d1 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

/// @brief Second dauther class
class D2 : virtual public B1, virtual private B2 {
private:
  int d2;

public:
  D2(int _b1, int _b2, int _d2) : B1{_b1}, B2{_b2}, d2{_d2} {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  /// @brief Print `d2`
  auto show() const -> void override {
    std::cout << "d2: " << d2 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

/// @brief Final class
class D3 : private D1, public D2 {
private:
  int d3;

public:
  D3(int _b1, int _b2, int _d1, int _d2, int _d3)
      : B1{_b1}, B2{_b2}, D1{_b1, _b2, _d1}, D2{_b1, _b2, _d2}, d3{_d3} {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  /// @brief print `b1`, `b2`, `d1`, `d2`, `d3`
  auto show() const -> void override {
    B1::show();
    B2::show();
    D1::show();
    D2::show();
    std::cout << "d3: " << d3 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

int main() {
  D3 d3{1, 2, 3, 4, 5};

  d3.show();

  return 0;
}