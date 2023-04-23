#include <iostream>
using namespace std;

class Rectangle {
  public:
    double width, height;
    double getArea();
};

double Rectangle::getArea() { return width * height; }

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "사각형의 면적은 " << rect.getArea();
    
    return 0;
}