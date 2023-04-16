#include "Ram.h"
#include <algorithm>
#include <iostream>
using namespace std;

Ram::Ram() {
  size = 100 * 1024;
  fill(begin(mem), end(mem), 0);
}

Ram::~Ram() { cout << "메모리 제거됨\n"; }

char Ram::read(int address) {
  isOutOfMemory(address);
  return mem[address];
}

void Ram::write(int address, char value) {
  isOutOfMemory(address);
  mem[address] = value;
}

void Ram::isOutOfMemory(int address) {
  if (address < 0 || address > size) {
    cout << "Out of memory!!\n";
    exit(1);
  }
}