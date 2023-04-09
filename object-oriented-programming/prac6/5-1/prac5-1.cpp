#include <iostream>
using namespace std;

class Rectangle {
  double width;
  double height;

public:
  Rectangle();
  Rectangle(double width);
  Rectangle(double width, double height);
  bool isSquare();
};

Rectangle::Rectangle() { width = height = 1; }

Rectangle::Rectangle(double width) { height = this->width = width; }

Rectangle::Rectangle(double width, double height) {
  this->width = width;
  this->height = height;
}

bool Rectangle::isSquare() { return width == height; }

int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  Rectangle rect1;
  Rectangle rect2(3, 5);
  Rectangle rect3(3);
  if (rect1.isSquare())
    cout << "rect1은 정사각형이다." << endl;
  if (rect2.isSquare())
    cout << "rect2는 정사각형이다." << endl;
  if (rect3.isSquare())
    cout << "rect3는 정사각형이다." << endl;
}