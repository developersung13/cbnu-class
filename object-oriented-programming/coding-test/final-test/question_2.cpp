#include <iostream>
using namespace std;

class Person {
  string name;

public:
  int age;
  void setName(string name) { this->name = name; }
  void setAge(int age) { this->age = age; }
  string getName() { return name; }
};

int main() {
  Person person; // 이름(name)과 나이(age) 속성을 가짐
  person.setName("John");
  person.setAge(25);
  cout << person.getName() << endl;
  cout << person.age << endl;
  return 0;
}
