#include <iostream>
using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person() {
    name = "None";
    age = 0;
    cout << name << " " << age << endl;
  }

  // name과 age를 출력하는 소멸자 작성
  ~Person() { cout << name << " " << age << endl; }

  string getName() { return name; }

  int getAge() { return age; }

  void setPerson(string n, int a) {
    name = n;
    age = a;
  };
};

int main() {
  // Person 클래스형 포인터 personPtr를 이용하여 객체를 동적 생성
  Person *personPtr = new Person();

  personPtr->setPerson("John", 25);
  cout << personPtr->getName() << " " << personPtr->getAge() << endl;

  //동적 객체 소멸
  delete personPtr;

  return 0;
}