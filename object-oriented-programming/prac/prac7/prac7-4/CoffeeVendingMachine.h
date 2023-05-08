#include "Container.h"

#ifndef COFFEEVENDINGMACHINE_H
#define COFFEEVENDINGMACHINE_H

// 커피 자판기를 표현하는 클래스
class CoffeeVendingMachine {
  // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕을 나타냄
  Container tong[3];
  void fill();           // 3개의 통을 모두 10으로 채움
  void selectEspresso(); // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
  void selectAmericano(); // 아메리카노를 선택한 경우, 커피 1, 물 2 소모
  void
  selectSugarCoffee(); // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
  void show(); // 현재 커피, 물, 설탕의 잔량 출력
public:
  void run(); // 커피 자판기 작동
};

#endif
