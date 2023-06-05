#include <iostream>
using namespace std;

class Calculator {
public:
  virtual int add(int a, int b) = 0;
  virtual int subtract(int a, int b) = 0;
  virtual double average(int a[], int size) = 0;
  virtual ~Calculator() {}
};

class GoodCalc : public Calculator {
public:
  int add(int a, int b) { return a + b; }
  int subtract(int a, int b) { return a - b; }
  double average(int a[], int size) {
    double tot = 0;
    for (int k = 0; k < size; k++)
      tot += a[k];
    return tot / size;
  }
};

int main() {
  int a[] = {1, 2, 3, 4, 5};
  Calculator *p = new GoodCalc();
  cout << p->add(2, 3) << endl;
  cout << p->subtract(2, 3) << endl;
  cout << p->average(a, 5) << endl;
  delete p;
}