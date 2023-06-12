#include <iostream>
using namespace std;

template <class T> class Calculator {
private:
  T operand1;
  T operand2;

public:
  Calculator(T op1, T op2) {
    operand1 = op1;
    operand2 = op2;
  }
  T add();
  T subtract();
  T multiply();
  T divide();
};

template <class T> T Calculator<T>::add() { return operand1 + operand2; }
template <class T> T Calculator<T>::subtract() { return operand1 - operand2; }
template <class T> T Calculator<T>::multiply() { return operand1 * operand2; }
template <class T> T Calculator<T>::divide() { return operand1 / operand2; }

int main() {
  Calculator<int> intCalculator(5, 3);
  cout << "Integers: " << endl;
  cout << "Addition: " << intCalculator.add() << endl;
  cout << "Subtraction: " << intCalculator.subtract() << endl;
  cout << "Multiplication: " << intCalculator.multiply() << endl;
  cout << "Division: " << intCalculator.divide() << endl;
  Calculator<double> doubleCalculator(5.5, 2.5);
  cout << "\nDoubles: " << endl;
  cout << "Addition: " << doubleCalculator.add() << endl;
  cout << "Subtraction: " << doubleCalculator.subtract() << endl;
  cout << "Multiplication: " << doubleCalculator.multiply() << endl;
  cout << "Division: " << doubleCalculator.divide() << endl;
  return 0;
}