#include "Rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(double a, double b) : sides{a, b} {}

auto Rectangle::perimeter() const -> double {
  return 2 * (sides[0] + sides[1]);
}
auto Rectangle::square() const -> double { return sides[0] * sides[1]; }

auto Rectangle::operator-(const Rectangle &rhs) -> Rectangle {
  double b = sqrt(std::abs(std::abs((sides[0] + sides[1]) - (rhs.sides[0] + rhs.sides[1])) -
             std::abs(sides[0] * sides[1] - rhs.sides[0] * rhs.sides[1])));
  double a = std::abs(sides[0] * sides[1] - rhs.sides[0] * rhs.sides[1]) / b;
  return Rectangle{a, b};
}

auto Rectangle::operator+(const Rectangle &rhs) -> Rectangle {
  double b = sqrt(sides[0] + sides[1] + rhs.sides[0] + rhs.sides[1] +
                  sides[0] * sides[1] + rhs.sides[0] * rhs.sides[1]);
  double a = (sides[0] * sides[1] + rhs.sides[0] * rhs.sides[1]) / b;
  return Rectangle{a, b};
}

auto operator>>(std::istream &is, Rectangle &rect) -> std::istream & {
  is >> rect.sides[0];
  is >> rect.sides[1];
  return is;
}

auto operator<<(std::ostream &os, const Rectangle &rect) -> std::ostream & {
  os << rect.sides[0] << ", " << rect.sides[1];
  return os;
}
