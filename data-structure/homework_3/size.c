#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가

int main() {
    int **x; // 정수형 2중 포인터 변수 선언

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    /* 정수형 2중 포인터 변수가 메모리에서 차지하는 Byte 크기를 출력
    64비트 머신의 경우 주솟값을 저장하는 8Bytes를 차지하기 때문에 8의 값이 sizeof함수로부터 반환됨*/
    printf("sizeof(x) = %lu\n", sizeof(x));
    /* 정수형 2중 포인터 변수를 1번 dereferencing한 공간이 메모리에서 차지하는 Byte 크기를 출력
    2중 포인터 변수를 1번 dereferencing 하면 주솟값을 가리키기 때문에 8의 값이 sizeof함수로부터 반환됨*/
    printf("sizeof(*x) = %lu\n", sizeof(*x));
    /* 정수형 2중 포인터 변수를 2번 dereferencing하면 특정한 값을 가리키기 때문에
    정수형 데이터가 차지하는 크기인 4Bytes에서 4의 값이 sizeof함수로부터 반환됨 */
    printf("sizeof(**x) = %lu\n", sizeof(**x));
}