#include <cstring>
#include <iostream>
using namespace std;

class Book {
  char *title; // 제목 문자열
  int price;   // 가격
public:
  Book(const Book &book);
  Book(const char *title, int price);
  ~Book();
  void set(const char *title, int price);
  void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char *title, int price) {
  this->price = price;
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);
}

Book::Book(const Book &book) {
  this->price = book.price;
  this->title = new char[strlen(book.title) + 1];
  strcpy(this->title, book.title);
}

void Book::set(const char *title, int price) {
  this->price = price;
  /*  생성자로 이미 객체의 title이 초기화되어 있기 때문에
      set함수에서는 기존에 동적할당된 메모리 공간을 아래 조건식을
      통해 해제해야 한다. */
  if (this->title)
    delete[] this->title;
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);
}

Book::~Book() { delete[] title; }

int main() {
  Book cpp("명품C++", 10000);
  Book java = cpp;
  java.set("명품자바", 12000);
  cpp.show();
  java.show();
}