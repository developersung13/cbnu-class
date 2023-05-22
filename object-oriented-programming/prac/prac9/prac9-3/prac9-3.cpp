#include <iostream>
using namespace std;

class Circle {
private:
  int radius;

public:
  Circle(int radius = 0) { this->radius = radius; }
  void show() { cout << "radius = " << radius << " 인 원" << endl; }
  friend Circle &operator++(Circle &);
  friend Circle operator++(Circle &, int);
};

Circle &operator++(Circle &c) {
  c.radius++;
  return c;
}

Circle operator++(Circle &c, int) {
  Circle temp = c;
  c.radius++;
  return temp;
}

int main() {
  Circle a(5), b(4);
  ++a;     // 반지름을 1 증가시킨다.
  b = a++; // 반지름을 1 증가시킨다.
  a.show();
  b.show();
}
