#include <ctime>
#include <iostream>

class VISTAVA {
private:
  std::string Nazva;
  std::tm Date;
  float Cost;
  int Day_week;

public:
  VISTAVA(std::string &nazva, std::tm &date, float cost)
      : Nazva{nazva}, Date{date}, Cost{cost}, Day_week{Date.tm_wday} {}
};

int main() { return 0; }
