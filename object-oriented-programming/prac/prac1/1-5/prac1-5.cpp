#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name, addr;
    int age;
public:
    Person(string name, string addr, int age) {
        this->name = name;
        this->addr = addr;
        this->age = age;
    }

    string getName() { return name; }
    string getAddr() { return addr; }
    int getAge() { return age; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string name, addr;
    int age;

    cout << "�̸���? ";
    getline(cin, name);

    cout << "�ּҴ�? ";
    getline(cin, addr);

    cout << "���̴�? ";
    cin >> age;

    Person person = Person(name, addr, age);
    cout << "--------------------------------------------------\n";
    cout << person.getName() << ". " << person.getAddr() << ". " << person.getAge() << "��";
    return 0;
}