#include <iostream>
using namespace std;

class Book {
  string title;
  int price, pages;

public:
  Book(string title = "", int price = 0, int pages = 0) {
    this->title = title;
    this->price = price;
    this->pages = pages;
  }
  void show() {
    cout << title << ' ' << price << "원 " << pages << "페이지" << endl;
  }

  bool operator==(int);
  bool operator==(string);
  bool operator==(Book op);
};

bool Book::operator==(int price) { return this->price == price; }

bool Book::operator==(string title) { return this->title == title; }

bool Book::operator==(Book op2) {
  return title == op2.title && price == op2.price && pages == op2.pages;
}

int main() {
  Book a("C++", 30000, 500), b("파이썬", 30000, 500);
  if (a == 30000)
    cout << "정가 30000원" << endl;
  if (a == "C++")
    cout << "C++" << endl;
  if (a == b)
    cout << "두 책이 같은 책입니다." << endl;
}