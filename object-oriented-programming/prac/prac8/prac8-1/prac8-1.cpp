#include <iostream>
using namespace std;

class Circle {
private:
  int radius;

public:
  Circle() { radius = 1; }
  Circle(int radius) { this->radius = radius; }
  double getArea() { return 3.14 * radius * radius; }
};

void swap(Circle &c1, Circle &c2) {
  Circle tmp = c1;
  c1 = c2;
  c2 = tmp;
}

int main() {
  Circle A, B(3);
  cout << "A의 면적 = " << A.getArea() << " B의 면적 = " << B.getArea() << '\n';
  swap(A, B);
  cout << "A의 면적 = " << A.getArea() << " B의 면적 = " << B.getArea();
  return 0;
}