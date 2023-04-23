#include <iostream>
using namespace std;

class Oval {
  int width, height;

public:
  Oval();
  Oval(int, int);
  int getWidth();
  int getHeight();
  void set(int, int);
  void show();
  ~Oval();
};

Oval::Oval() { width = height = 1; }

Oval::Oval(int width, int height) {
  this->width = width;
  this->height = height;
}

int Oval::getWidth() { return width; }
int Oval::getHeight() { return height; }
void Oval::set(int width, int height) {
  this->width = width;
  this->height = height;
}
void Oval::show() {
  cout << "width = " << width << ", height = " << height << '\n';
}

Oval::~Oval() {
  cout << "Oval 소멸 : ";
  show();
}

int main() {
  Oval a, b(3, 4);
  a.set(10, 20);
  a.show();
  cout << b.getWidth() << ", " << b.getHeight() << endl;
  return 0;
}