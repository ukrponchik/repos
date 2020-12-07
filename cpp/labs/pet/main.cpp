#include <iostream>
#include <string>

class Pet {
private:
  bool hasTail_;
  unsigned int weight_;
  std::string name_;

  std::string type;

public:
  auto hasTail() const -> bool { return hasTail_; }

  auto weight() const -> unsigned int { return weight_; }

  auto name() const -> const std::string & { return name_; }

  auto changeName(const std::string &name) -> void { this->name_ = name; }

  auto setWeight(const unsigned int weight) -> void { this->weight_ = weight; }
  auto who() const -> const std::string & { return type; }

  Pet(bool tail, unsigned int weight, const std::string &name,
      const std::string &type)
      : hasTail_(tail), weight_(weight), name_(name), type(type) {}

  virtual auto say() const -> void = 0;

  friend auto operator<<(std::ostream &os, const Pet &p) -> std::ostream & {
    os << p.who() << " " << p.name() << ", вага: " << p.weight()
      << ", має хвіст: " << (p.hasTail() ? "так" : "ні");
    return os;
  }
};

class Dog : public Pet {
public:
  Dog(unsigned int weight, const std::string &name)
      : Pet(true, weight, name, "Собака") {}

  auto say() const -> void override {
    std::cout << "Гав-гав-гав!" << std::endl;
  }
};

class Cat : public Pet {
public:
  Cat(unsigned int weight, const std::string &name)
    : Pet(true, weight, name, "Кіт") {}

  auto say() const -> void override {
    std::cout << "Мяу-мяу-мяу!" << std::endl;
  }
};

class Parrot : public Pet {
public:
  Parrot(unsigned int weight, const std::string &name)
    : Pet(true, weight, name, "Папуга") {}

  auto say() const -> void override {
    std::cout << "Ц-ц-ц!" << std::endl;
  }
};

int main() {
  using namespace std;

  Dog myDog(30, "Сірко");
  Cat myCat(30, "Мурка");
  Parrot myParrot(30, "Доля");

  cout << myDog << endl;
  cout << myCat << endl;
  cout << myParrot << endl;
}