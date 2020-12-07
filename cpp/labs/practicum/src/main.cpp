#include "Rectangle.hpp"
#include <iostream>

using namespace std;

int main() {
  Rectangle rect{3, 2};
  Rectangle rect1{};

  cout << "Enter sides for rect1: ";
  cin >> rect1;

  Rectangle r = rect + rect1;
  Rectangle d = rect - rect1;

  cout << "rect: " << rect << endl;
  cout << "P = " << rect.perimeter() << "\tS = " << rect.square() << endl;

  cout << "rect1: " << rect1 << endl;
  cout << "P = " << rect1.perimeter() << "\tS = " << rect1.square() << endl;

  cout << "r: " << r << endl;
  cout << "P = " << r.perimeter() << "\tS = " << r.square() << endl;

  cout << "d: " << d << endl;
  cout << "P = " << d.perimeter() << "\tS = " << d.square() << endl;

  return 0;
}