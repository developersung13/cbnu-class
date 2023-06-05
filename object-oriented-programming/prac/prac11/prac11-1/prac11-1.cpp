
#include <iostream>
#include <string>
using namespace std;
class Shape {
protected:
    string name;
    int width, height;
public:
    Shape(string name = "", int width = 0, int height = 0) { 
        this->name = name;
        this->width = width;
        this->height = height; 
    } 
    virtual double getArea() = 0;
    string getName() { return name; }
    virtual ~Shape() {}
};

class Oval : public Shape {
public:
    Oval(string n, int w, int h) : Shape(n, w, h) {}
    double getArea() { return 3.14 * width * height; }
};

class Rect : public Shape {
public:
    Rect(string n, int w, int h) : Shape(n, w, h) {}
    double getArea() { return width * height; }
};

class Triangular : public Shape {
public:
    Triangular(string n, int w, int h) : Shape(n, w, h) {}
    double getArea() { return width * height / 2; }
};

int main() {
    Shape *p[3];

    p[0] = new Oval("빈대떡", 10, 20);
    p[1] = new Rect("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30, 40);

    for (int k = 0; k < 3; k++)
        cout << p[k]->getName() << " 넓이는 " << p[k]->getArea() << endl;

    for (int k = 0; k < 3; k++) delete p[k];
}