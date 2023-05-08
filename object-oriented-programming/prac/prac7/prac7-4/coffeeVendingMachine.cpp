#include "CoffeeVendingMachine.h"
#include <iostream>
using namespace std;

void CoffeeVendingMachine::fill() {
  for (int k = 0; k < 3; k++)
    tong[k].fill(10);
}

void CoffeeVendingMachine::selectEspresso() {
  if (tong[0].getSize() - 1 < 0 || tong[1].getSize() - 1 < 0) {
    cout << "원료가 부족합니다.\n";
    return;
  }

  cout << "에스프레소입니다.\n\n";

  // tong[0]:커피, tong[1]:물, tong[2]:설탕통
  // 에스프레소: 커피(1), 물(1) 소모
  tong[0].consume(1);
  tong[1].consume(1);
}

void CoffeeVendingMachine::selectAmericano() {
  if (tong[0].getSize() - 1 < 0 || tong[1].getSize() - 2 < 0) {
    cout << "원료가 부족합니다.\n";
    return;
  }

  cout << "아메리카노입니다.\n\n";

  // tong[0]:커피, tong[1]:물, tong[2]:설탕
  // 아메리카노: 커피(1), 물(2) 소모
  tong[0].consume(1);
  tong[1].consume(2);
}

void CoffeeVendingMachine::selectSugarCoffee() {
  if (tong[0].getSize() - 1 < 0 || tong[1].getSize() - 2 < 0 ||
      tong[2].getSize() - 1 < 0) {
    cout << "원료가 부족합니다.\n";
    return;
  }

  cout << "설탕커피입니다.\n\n";

  // tong[0]:커피, tong[1]:물, tong[2]:설탕
  // 에스프레소: 커피(1), 물(2), 설탕(1) 소모
  tong[0].consume(1);
  tong[1].consume(2);
  tong[2].consume(1);
}

void CoffeeVendingMachine::show() {
  cout << "커피 " << tong[0].getSize() << ", ";
  cout << "물 " << tong[1].getSize() << ", ";
  cout << "설탕 " << tong[2].getSize() << "\n\n";
}

void CoffeeVendingMachine::run() {
  int selectedMenu;
  cout << "***** 커피자판기를 작동합니다. *****\n";
  while (1) {
    cout << "메뉴를 눌러주세요(1:에스프레소 2:아메리카노 3:설탕커피 4:잔량보기 "
            "5:채우기) >> ";
    cin >> selectedMenu;
    switch (selectedMenu) {
    case 1:
      selectEspresso();
      break;
    case 2:
      selectAmericano();
      break;
    case 3:
      selectSugarCoffee();
      break;
    case 4:
      show();
      break;
    case 5:
      fill();
      show();
      break;
    default:
      return;
    }
  }
}