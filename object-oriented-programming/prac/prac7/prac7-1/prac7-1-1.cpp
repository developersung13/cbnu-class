#include <iostream>
using namespace std;

class Circle {
  int radius; // 원의 반지름 값
public:
  Circle();
  void setRadius(int radius); // 반지름을 설정한다.
  double getArea();           // 면적을 리턴한다.
};

Circle::Circle() { radius = 1; }
void Circle::setRadius(int radius) { this->radius = radius; }
double Circle::getArea() { return 3.14 * radius * radius; }

int main() {
  int radius, ans = 0;
  Circle circleArray[3];
  for (int k = 0; k < 3; k++) {
    cout << "원 " << k + 1 << "의 반지름 >> ";
    cin >> radius;
    circleArray[k].setRadius(radius);
    if (circleArray[k].getArea() > 100)
      ans++;
  }

  cout << "면적이 100보다 큰 원 " << ans << "개입니다.";
  return 0;
}
