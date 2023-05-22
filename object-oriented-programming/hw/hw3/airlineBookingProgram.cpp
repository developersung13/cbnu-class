#include <iostream>
#include <string>
using namespace std;

// 좌석 클래스 정의
class Seat {
  int number; // 좌석 번호 저장용 정수형 변수 선언
  string name; // 좌석을 예약한 고객의 이름 저장용 문자열형 변수 선언

public:
  // 기본 생성자에서 좌석 번호를 -1로, 이름을 "-----"로 초기화
  Seat() {
    number = -1;
    name = "-----";
  }
  // 고객명 설정 메소드
  void setName(string name) { this->name = name; }
  // 고객명 반환 메소드
  string getName() { return name; }
};

// 일정 클래스 생성
class Schedule {
  // Seat 클래스의 포인터 선언
  Seat *seat;

public:
  // 8개의 Seat클래스 객체를 동적 할당
  Schedule() { seat = new Seat[8]; }
  // 소멸자 내에서 동적 할당된 메모리 해제
  ~Schedule() { delete[] seat; }

  // 일정 출력 메소드
  void show(int num) {
    if (num == 1)
      cout << "07시 :";
    else if (num == 2)
      cout << "12시 :";
    else if (num == 3)
      cout << "17시 :";

    for (int i = 0; i < 8; i++)
      cout << "\t" << seat[i].getName();
    cout << endl;
  }

  // 고객명 설정 메소드 선언 및 정의
  void setN(int num, string name) { seat[num - 1].setName(name); }
  // 고객명 반환 메소드 선언 및 정의
  string getN(int num) { return seat[num - 1].getName(); }
};

// 비행기 예약 클래스 정의
class AirlineBook {
  // Schedule 클래스의 포인터 변수 선언
  Schedule *s;

public:
  // 3개의 Schedule 클래스 객체를 동적 할당
  AirlineBook() { s = new Schedule[3]; }
  // 소멸자 내에서 동적 할당된 메모리 해제
  ~AirlineBook() { delete[] s; }

  // 예약 프로그램 메소드 선언 및 정의
  void program() {
    int num;
    int seat_num;
    string name;
    cout << "*** 한성한공에 오신것을 환영합니다. ***\n";

    // 무한 루프를 이용하여 (예약, 취소, 보기, 끝내기) 메뉴를 반복
    while (1) {
      cout << "\n예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
      cin >> num;
      if (num == 1) { // 예약
        cout << "07시:1, 12시:2, 17시:3 >> ";
        cin >> num;

        // 고객이 (1, 2, 3) 중 하나를 선택한 경우에만 실행
        if (num == 1 || num == 2 || num == 3) {
          s[num - 1].show(num);
          cout << "좌석 번호 >> ";
          cin >> seat_num;
          cin.ignore(1);
          cout << "이름 입력 >> ";
          getline(cin, name);
          /*  이미 예약된 좌석을 선택한 경우 에러 메시지를
              출력하고 메뉴 선택으로 복귀 */
          if (s[num - 1].getN(seat_num) != "-----") {
            cout << "이미 예약된 자석입니다." << endl;
            continue;
          }
          // 고객명으로 해당 좌석에 예약
          s[num - 1].setN(seat_num, name);
        } else {
          // (1, 2, 3) 이외의 숫자를 입력한 경우 에러 메시지를 출력
          cout << "숫자를 잘못 입력하셨습니다." << endl;
        }
      } else if (num == 2) { // 취소
        cout << "07시:1, 12시:2, 17시:3 >> ";
        cin >> num;

        // 고객이 1, 2, 3 중 하나를 선택한 경우에만 실행됩니다.
        if (num == 1 || num == 2 || num == 3) {
          s[num - 1].show(num);
          cout << "좌석 번호 >> ";
          cin >> seat_num;
          cin.ignore(1);
          cout << "이름 입력 >> ";
          getline(cin, name);
          // 좌석이 비어있는 경우 에러 메시지를 출력
          if (s[num - 1].getN(seat_num) == "-----")
            cout << "해당 좌석을 예약한 고객이 존재하지 않습니다." << endl;
          // 고객명으로 해당 좌석의 예약자 이름과 다른 경우 에러 메시지 출력
          else if (name != s[num - 1].getN(seat_num))
            cout << "해당 좌석을 예약한 고객님의 성명과 일치하지 않습니다."
                 << endl;
          else
            s[num - 1].setN(seat_num, "-----");
        } else // (1, 2, 3) 이외의 숫자를 입력한 경우 에러 메시지를 출력
          cout << "숫자를 잘못 입력하셨습니다." << endl;
      } else if (num == 3) { // 보기
        s[0].show(1);        // 07시 항공편의 예약 현황 조회
        s[1].show(2);        // 12시 항공편의 예약 현황 조회
        s[2].show(3);        // 17시 항공편의 예약 현황 조회
      } else if (num == 4) { // 끝내기
        cout << "예약 시스템을 종료합니다." << endl;
        break;
      } else
        cout << "숫자를 잘못 입력하셨습니다." << endl;
    }
  }
};

int main() {
  // AirlineBook 객체를 동적으로 생성
  AirlineBook *Air = new AirlineBook();
  Air->program();
}