#include "sub.h"

void Sub::setValue(int x, int y) {
  a = x;
  b = y;
}

int Sub::calculate() { return a - b; }