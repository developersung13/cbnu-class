#include <iostream>
using namespace std;

class Oval {
  int width;
  int height;

public:
  Oval();
  Oval(int width, int height);
  ~Oval();
  int getWidth();
  int getHeight();
  void set(int w, int h);
  void show();
};

Oval::Oval() { width = height = 1; }

Oval::Oval(int width, int height) {
  this->width = width;
  this->height = height;
}

Oval::~Oval() {
  cout << "Oval 소멸 : width = " << width << ", "
       << "height = " << height << '\n';
}

int Oval::getWidth() { return width; }

int Oval::getHeight() { return height; }

void Oval::set(int w, int h) {
  width = w;
  height = h;
}

void Oval::show() { cout << "width = " << width << ", height = " << height << '\n'; }

int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  Oval a, b(3, 4);
  a.set(10, 20);
  a.show();
  cout << b.getWidth() << ", " << b.getHeight() << '\n';

  return 0;
}