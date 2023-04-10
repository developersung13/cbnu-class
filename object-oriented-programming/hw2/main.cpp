#include "add.h"
#include "div.h"
#include "mul.h"
#include "sub.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);

  Add a;
  Sub s;
  Mul m;
  Div d;

  int operand, operand2;
  char operation;
  bool tf = true;

  while (tf) {
    cout << "두 정수와 연산자를 입력하세요 : ";
    cin >> operand >> operand2 >> operation;
    switch (operation) {
    case '+':
      a.setValue(operand, operand2);
      cout << a.calculate() << '\n';
      break;
    case '-':
      s.setValue(operand, operand2);
      cout << s.calculate() << '\n';
      break;
    case '*':
      m.setValue(operand, operand2);
      cout << m.calculate() << '\n';
      break;
    case '/':
      d.setValue(operand, operand2);
      cout << d.calculate() << '\n';
      break;
    default:
      tf = false;
    }
  }

  return 0;
}