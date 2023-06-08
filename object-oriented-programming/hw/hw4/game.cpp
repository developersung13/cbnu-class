#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// 게임 객체에 대한 클래스 선언
class GameObject {
protected:
  int distance; // 이동 거리 저장용 변수
  int x, y; // 객체의 위치값 저장용 변수
public:
  GameObject(int startX, int startY,
             int distance) {
    this->x = startX; // 게임 초기 x값 설정
    this->y = startY; // 게임 초기 y값 설정
    this->distance = distance; // 이동 거리 설정
  }
  virtual ~GameObject() {};
  virtual void move() = 0;
  virtual char getShape() = 0;
  int getX() { return x; } // x값 반환 함수 정의 및 선언
  int getY() { return y; } // y값 반환 함수 정의 및 선언
  // 기존 GameObject와 충돌을 확인하는 함수
  bool collide(GameObject *p) {
    if (this->x == p->getX() && this->y == p->getY())
      return true;
    else
      return false;
  }
};

class Human : public GameObject { // 인간 객체 대한 클래스 선언
public:
  Human(int x, int y, int dis)
      : GameObject(x, y, dis) {}
  void move(); // 사용자의 입력에 따라 객체를 이동시키는 함수
  char getShape() { return 'H'; } // 'H'를 반환하는 함수
};
void Human::move() { // Human 클래스의 move 메서드 정의
  string key; // 사용자 입력용 변수 선언
  for (;;) { // 무한 루프
    cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
    cin >> key; // 사용자로부터 입력을 받음
    if (key == "a") {
      if (y != 0) {
        y -= distance; // 왼쪽으로 이동
        break;
      } else
        cout << "이동불가" << endl;
    } else if (key == "s") {
      if (x != 9) {
        x += distance; // 아래로 이동
        break;
      } else
        cout << "이동불가" << endl;
    } else if (key == "d") {
      if (x != 0) {
        x -= distance; // 위로 이동
        break;
      } else
        cout << "이동불가" << endl;
    } else if (key == "f") {
      if (y != 19) {
        y += distance; // 오른쪽으로 이동
        break;
      } else
        cout << "이동불가" << endl;
    } else
      cout << "입력 에러" << endl;
  }
}

class Monster : public GameObject { // 몬스터 객체 대한 클래스 선언
public:
  Monster(int x, int y, int dis) : GameObject(x, y, dis) {
    srand((unsigned)time(0));
  } // 랜덤하게 이동하기때문에
  void move(); // 몬스터를 이동시키는 함수
  char getShape() { return 'M'; } // 'M'를 반환하는 함수
};

// Monster 클래스의 move 메서드 정의
void Monster::move() {
  for (;;) {
    int n = rand() % 4; // 상하좌우 방향 중 임의의 방향으로 설정
    if (n == 0) {
      if (y > 1) {
        y -= distance; // 왼쪽으로 이동
        break;
      }
    } else if (n == 1) { 
      if (x < 8) {
        x += distance; // 아래쪽으로 이동
        break;
      }
    } else if (n == 2) {
      if (x > 1) {
        x -= distance; // 위쪽으로 이동
        break;
      }
    } else {
      if (y < 18) {
        y += distance; // 오른쪽으로 이동
        break;
      }
    }
  }
}

class Food : public GameObject { // 음식 객체 대한 클래스 선언
public:
  Food(int x, int y, int dis) : GameObject(x, y, dis) {}
  void move(); // 음식 객체를 이동시키는 함수
  char getShape() { return '@'; } // '@'를 반환하는 함수
};

// Food 클래스의 move 메서드 정의
void Food::move() {
  for (;;) {
    int n = rand() % 4;
    if (n == 0) {
      if (y != 0) {
        y -= distance;  // 왼쪽으로 이동
        break;
      }
    } else if (n == 1) {
      if (x != 9) {
        x += distance;  // 아래로 이동
        break;
      }
    } else if (n == 2) {
      if (x != 0) {
        x -= distance;  // 위로 이동
        break;
      }
    } else {
      if (y != 19) {
        y += distance; // 오른쪽으로 이동
        break;
      }
    }
  }
}

class Game { // 게임에 메뉴에 대한 클래스 선언
  string board[10][20];          // 10 x 20 크기의 게임판 설정
  Human *h = new Human(0, 0, 1); // 인간 객체 시작 위치, 이동거리 설정 (0, 0, 1)
  Monster *m = new Monster(5, 5, 2); // 몬스터 객체 시작 위치, 이동거리 설정 (5, 5, 2)
  Food *f = new Food(9, 9, 1); // 음식 객체 시작 위치, 이동거리 설정 (9, 9, 1)
public:
  Game() {
    srand((unsigned)time(0));
    cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl << endl;
    // 게임판 배열 초기화
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 20; ++j)
        board[i][j] = '-'; // 각 칸을 '-' 문자로 채움
    }
  }
  ~Game() {
    delete h; // Human 객체 메모리 해제
    delete m; // Monster 객체 메모리 해제
    delete f; // Food 객체 메모리 해제
  }
  void game(); // 게임 진행 함수 선언
  void clr1() {
    board[h->getX()][h->getY()] = "-"; // Human 객체의 이전 위치를 게임판에서 제거
    board[m->getX()][m->getY()] = "-"; // Monster 객체의 이전 위치를 게임판에서 지움
  }

  void clr2() {
    board[f->getX()][f->getY()] = "-"; // Food 객체의 이전 위치를 게임판에서 지움
  }

  void setXY() {
    board[h->getX()][h->getY()] = h->getShape(); // Human 객체의 현재 위치를 게임판에 표시
    board[m->getX()][m->getY()] = m->getShape(); // Monster 객체의 현재 위치를 게임판에 표시
    board[f->getX()][f->getY()] = f->getShape(); // Food 객체의 현재 위치를 게임판에 표시
  }

  void show() {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 20; ++j)
        cout << board[i][j]; // 게임판의 현재 상태를 나타냄
      cout << endl; // 한 행을 출력 후 개행
    }
  }
};

// Game 클래스의 game 메서드 정의
void Game::game() {
  int count = 0, gamecount = 0; // 게임 횟수 및 음식 이동 횟수를 관리하는 변수 선언
  for (;;) { // 무한 루프
    setXY(); // 각 객체의 위치를 게임판 위에 설정
    show(); // 게임판을 표시
    clr1(); // Human 객체와 Monster 객체의 위치 초기화
    h->move(); // Human 객체를 이동
    m->move(); // Monster 객체를 이동
    int n = rand(); // 난수 생성
    cout << endl;
    if (n % 2 == 0 && count < 2 &&
        gamecount <= 3) { // 조건에 따라서 Food 객체를 임의로 이동
      clr2();  // Food 객체 위치 초기화
      f->move(); // Food 객체를 이동
      ++count; // 음식 이동 횟수 증가
    }

    // 3번의 게임 진행 후 Food 객체가 2번 이하로 이동했을 때 나머지 이동 횟수를 채움
    if (gamecount > 3 && count < 2) {
      clr2(); // Food 객체 위치 초기화
      f->move(); // Food 객체를 이동
      ++count; // 음식 이동 횟수 증가
    }

    if (f->collide(h)) { // Human 객체가 Food 객체에 닿았을 경우
      setXY(); // 각 객체의 위치를 게임판 위에 설정
      board[f->getX()][f->getY()] = "H"; // Human 객체가 Food 객체에 닿았음을 게임판에 표시
      show(); // 게임판을 출력
      cout << "Human is Winner!!" << endl; // 인간의 승리 메시지 출력
      break;
    } else if (h->collide(m)) {  // Monster 객체가 Food 객체에 닿았을 경우
      setXY(); // 각 객체의 위치를 게임판 위에 설정
      board[f->getX()][f->getY()] = "M"; // Monster 객체가 Food 객체에 닿았음을 게임판에 표시
      show(); // 게임판을 출력
      cout << "Monster is Winner!!" << endl; // 몬스터에 대한 승리 메시지 출력
      break;
    } else if (f->collide(m)) { // Monster 객체가 Human 객체에 닿았음을 경우
      setXY(); // 각 객체의 위치를 게임판 위에 설정
      board[f->getX()][f->getY()] = "M"; // Monster 객체가 Human 객체에 닿았음을 게임판에 표시
      show(); // 게임판을 출력
      cout << "Monster is Winner!!" << endl; // 몬스터에 대한 승리 메시지 출력
      break;
    }
    ++gamecount; // 게임 횟수 1증가
    if ((gamecount % 5) ==
        0) {
      count = 0;
      gamecount = 0;
    }
  }
}

int main() {
  Game *g = new Game; // Game 클래스에 대한 객체를 생성
  g->game(); // Game 클래스 내 game 함수 실행하여 게임을 시작
  delete g;  // Game 객체 메모리 해제
}