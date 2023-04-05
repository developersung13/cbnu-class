#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가

// 학생에 대한 구조체 student 선언
struct student {
    char lastName[13]; /* 13 bytes */
    int studentId; /* 4 bytes */
    short grade; /* 2 bytes */
};

int main() {
    // 구조체 변수 pst 정의
    struct student pst;

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    /* 구조체 변수 pst가 메모리에서 차지하는 크기를 Byte값으로 반환
    13 + (3) + 4 + 2 + (2) = 24Bytes */
    printf("size of student = %ld\n", sizeof(struct student));
    // int 타입이 메모리에서 차지하는 크기 4Bytes
    printf("size of int = %ld\n", sizeof(int));
    // short 타입이 메모리에서 차지하는 크기 2Bytes
    printf("size of short = %ld\n", sizeof(short));
    return 0; // 0을 반환함으로써 프로그램을 종료
}