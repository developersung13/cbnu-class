#pragma once // 이 프로그램이 한 번만 include 되도록 하는 pragma
#define _CRT_SECURE_NO_WARNINGS // 보안 문제와 관련된 경고를 무시하는 매크로

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

#define DIM 9 // 게임판 크기

enum LabelType { Empty = 0, Bomb = 9 }; // 게임판에 사용할 enum, 비어있는 칸은 0, 지뢰는 9로 표시
enum MaskType { Hide = 0, Open, Flag }; // 게임판을 보여줄 때 사용할 enum, Hide는 가리고, Open은 보여주고, Flag는 깃발 표시
int    nx = DIM, ny = DIM; // 가로, 세로 크기 변수
int    nBomb = DIM; // 게임판에 랜덤하게 생성할 지뢰 개수

// 좌표(x, y)에 해당하는 MineMapMask 배열의 값을 반환하는 함수
inline int& mask(int x, int y, int MineMapMask[DIM][DIM]) { return MineMapMask[y][x]; }
// 좌표(x, y)에 해당하는 MineMapMask 배열의 값을 반환하는 함수
inline int& label(int x, int y, int MineMapLabel[DIM][DIM]) { return MineMapLabel[y][x]; }
// 좌표(x, y)에 해당하는 MineMapLabel 배열의 값을 반환하는 함수
inline bool    isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
// 좌표(x, y)가 지뢰인지 검사하는 함수
inline bool    isBomb(int x, int y, int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Bomb; }
// 좌표(x, y)가 빈 칸인지 검사하는 함수
inline bool    isEmpty(int x, int y, int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) { return isValid(x, y) && label(x, y, MineMapLabel) == Empty; }

// 좌표(x, y)에 해당하는 지뢰를 깨는 함수
void dig(int x, int y, int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) {
    // 유효한 좌표인지, 이미 열린 칸인지 검사
    if (isValid(x, y) && mask(x, y, MineMapMask) != Open) {
        mask(x, y, MineMapMask) = Open;
        // 좌표(x, y) 주변에 지뢰가 없다면 재귀 호출로 주변 칸들도 열기
        if (label(x, y, MineMapLabel) == 0) {
            dig(x - 1, y - 1, MineMapMask, MineMapLabel);
            dig(x - 1, y, MineMapMask, MineMapLabel);
            dig(x - 1, y + 1, MineMapMask, MineMapLabel);
            dig(x, y - 1, MineMapMask, MineMapLabel);
            dig(x, y + 1, MineMapMask,MineMapLabel);
            dig(x + 1, y - 1, MineMapMask, MineMapLabel);
            dig(x + 1, y, MineMapMask, MineMapLabel);
            dig(x + 1, y + 1, MineMapMask, MineMapLabel);
        }
    }
}

// 좌표가 유효하고, 아직 열리지 않은 칸인지 검사하는 함수
void mark(int x, int y, int MineMapMask[DIM][DIM]) {
    if (isValid(x, y) && mask(x, y, MineMapMask) == Hide)
        mask(x, y, MineMapMask) = Flag;
}

// 깃발이 표시된 칸의 개수를 세어서 반환하는 함수
int getBombCount(int MineMapMask[DIM][DIM]) {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(x, y, MineMapMask) == Flag) count++;
    return count;
}

// 화면을 지우고, 현재 상태를 출력하는 함수
void print(int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) {
    system("cls");
    printf("   발견:%2d   전체:%2d\n", getBombCount(MineMapMask), nBomb);
    printf("    ① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨\n");
    for (int y = 0; y < ny; y++) {
        printf("%2c ", 'A' + y);
        for (int x = 0; x < nx; x++) {
            if (mask(x, y, MineMapMask) == Hide)    printf(" □");
            else if (mask(x, y, MineMapMask) == Flag) printf("¤");
            else {
                if (isBomb(x, y, MineMapMask, MineMapLabel)) printf(" ※");
                else if (isEmpty(x, y, MineMapMask, MineMapLabel)) printf("  ");
                else printf("%2d", label(x, y, MineMapLabel));
            }
        }
        printf("\n");
    }
}

// 해당 칸 주변에 있는 지뢰의 개수를 반환하는 함수
int countNbrBombs(int x, int y, int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) {
    int count = 0; // count 변수를 초기화
    // (x, y) 주변 3x3 칸을 검사
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
        // 검사하는 칸이 유효하고, 해당 칸에 지뢰가 있다면 count를 증가
            if (isValid(xx, yy) && label(xx, yy, MineMapLabel) == Bomb)
                count++;
    return count; // count 반환
}

// MineMapMask를 초기화하는 함수
void init(int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM], int total = 9) {
    // srand를 호출하여 난수 생성
    srand((unsigned int)time(NULL));
    // 각 칸의 mask와 label을 Hide, 0으로 초기화
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            mask(x, y, MineMapMask) = Hide;
            label(x, y, MineMapLabel) = 0;
        }
    nBomb = total;
    // nBomb개의 지뢰를 랜덤으로 생성
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        // 빈 칸을 찾을 때까지 무작위 좌표 생성
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(x, y, MineMapLabel) != Empty);
        // 해당 칸에 Bomb 레이블 부여
        label(x, y, MineMapLabel) = Bomb;
    }

    // 각 빈 칸 주변에 있는 지뢰의 개수를 계산하여 label에 저장
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x, y, MineMapLabel) == Empty)
                label(x, y, MineMapLabel) = countNbrBombs(x, y, MineMapMask, MineMapLabel);
}

// 플레이어의 입력을 받는 함수
bool getPos(int& x, int& y) {
    // 좌표 입력 받기
    printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
    bool isBomb = false;
    y = toupper(_getch()) - 'A';
    if (y == 'P' - 'A') {
        isBomb = true;
        y = toupper(_getche()) - 'A';
    }
    x = _getch() - '1';
    return isBomb; // 반환값은 P를 입력했는지 여부
}

// 게임 종료 조건을 체크하는 함수
int checkDone(int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) {
    // 지뢰를 제외한 칸의 개수를 세기 위한 count 변수를 초기화한다.
    int count = 0;
    for (int y = 0; y < ny; y++) // 지뢰 맵의 모든 y좌표에 대해서
        for (int x = 0; x < nx; x++) { // 지뢰 맵의 모든 x좌표에 대해서
            // 해당 좌표에 대한 마스크 상태가 Open이 아니라면 (해당 좌표가 열리지 않았다면)
            if (mask(x, y, MineMapMask) != Open) count++;
            // 해당 좌표가 지뢰이면 -1을 반환한다. (패배 조건)
            else if (isBomb(x, y, MineMapMask, MineMapLabel)) return -1;
        }
    // count와 총 지뢰 개수가 같다면, 모든 지뢰가 찾아졌으므로 승리한다.
    return (count == nBomb) ? 1 : 0;
}

void playMineSweeper(int total, int MineMapMask[DIM][DIM], int MineMapLabel[DIM][DIM]) {
    int x, y, status;
    init(MineMapMask, MineMapLabel, total); // 지뢰 맵을 초기화한다.
    do {
        print(MineMapMask, MineMapLabel); // 현재 지뢰 맵의 상태를 출력한다.
        bool isBomb = getPos(x, y); // 사용자로부터 x, y 좌표를 입력받는다.
        if (isBomb) mark(x, y, MineMapMask); // 해당 좌표가 지뢰라면, 그 좌표를 깃발 상태로 변경한다.
        else dig(x, y, MineMapMask, MineMapLabel); // 해당 좌표를 열어본다.
        status = checkDone(MineMapMask, MineMapLabel); // 게임 종료 조건을 체크한다.
    } while (status == 0); // 승패 조건이 만족할 때까지 반복한다.
    print(MineMapMask, MineMapLabel); // 최종 지뢰 맵의 상태를 출력한다.
    if (status < 0)
        printf("\n실패: 지뢰 폭발!!!\n\n"); // 지뢰가 폭발하여 패배한 경우
    else    printf("\n성공: 탐색 성공!!!\n\n"); // 모든 지뢰를 찾아서 승리한 경우
}

int main() {
    int total;
    int    MineMapMask[DIM][DIM];
    int    MineMapLabel[DIM][DIM];
    printf(" <Mine Sweeper>\n");
    printf(" 매설할 총 지뢰의 개수 입력 : ");
    scanf("%d", &total);
    playMineSweeper(total, MineMapMask, MineMapLabel);
}
