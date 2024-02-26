#include <iostream>

class Outer {
 public:
  Outer(int value) : privateValue(value) {}

  void showInner() {
    Inner inner(this);
    inner.display();
  }
  void lol() {
    std::cout << "получилось" << std::endl;
  }
 private:
  int privateValue;

  // Вложенный класс Inner
  class Inner {
   public:
    Inner(Outer* outer) : outerPtr(outer) {}
  
    void display() {
      // Вложенный класс может доступиться к private членам внешнего класса
      std::cout << "Value from Outer: " << outerPtr->privateValue << std::endl;
    }

   private:
    Outer* outerPtr;  // Указатель на экземпляр внешнего класса
  };
};

int main() {
  Outer outer(100);
  outer.showInner();

  return 0;
}