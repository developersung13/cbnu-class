#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board {
  static vector<string> articleVec;

public:
  static void add(string str);
  static void print();
};

vector<string> Board::articleVec = {};

void Board::add(string str) { articleVec.push_back(str); }

void Board::print() {
  cout << "************ 게시판 *************\n";
  for (int k = 0; k < articleVec.size(); k++)
    cout << k << ". " << articleVec[k] << '\n';
}

int main() {
  Board::add("다음주는 중간고사가 있습니다.");
  Board::add("코딩다이어리 많이 이용해 주세요.");
  Board::print();
  Board::add("홍길동 학생이 경진대회에 입상하였습니다.");
  Board::print();
}