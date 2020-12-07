#pragma once
#include <fstream>

class Rectangle {
public:
  Rectangle() = default;

  Rectangle(double a, double b);

  friend auto operator<<(std::ostream &os, const Rectangle &rect)
      -> std::ostream &;

  friend auto operator>>(std::istream &is, Rectangle &rect) -> std::istream &;

  /// Returns the perimeter of rectangle
  auto perimeter() const -> double;

  /// Returns the square of rectangle
  auto square() const -> double;

  ~Rectangle() = default;

  auto operator+(const Rectangle &rhs) -> Rectangle;

  auto operator-(const Rectangle &rhs) -> Rectangle;

private:
  double sides[2] = {0};
};