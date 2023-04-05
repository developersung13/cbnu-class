#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가
#include <stdlib.h>  // 메모리 동적할당 malloc 함수 사용을 위한 라이브러리 추가

int main() {
    int list[5]; // 정수형 데이터 5개를 저장할 수 있는 정수형 배열 선언
    int *plist[5]; // 데이터의 주솟값을 5개 저장할 수 있는 정수형 포인터 배열 선언

    list[0] = 10; // list[0](=list 배열의 첫 번째 공간)에 10의 값을 할당
    list[1] = 11; // list[1](=list 배열의 두 번째 공간)에 11의 값을 할당

    // plist 배열의 첫 번째 데이터 공간에 int 크기(=4Bytes)의 메모리 할당
    plist[0] = (int*)malloc(sizeof(int));

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    printf("list[0] \t= %d\n", list[0]); // list 배열에 저장된 첫 번째 데이터를 출력
    printf("list \t\t= %p\n", list); // list 배열의 시작 주솟값을 출력(=&list[0]);
    // list 배열에 저장된 첫 번째 데이터가 위치한 메모리 공간의 주솟값을 출력
    printf("&list[0] \t= %p\n", &list[0]);
    // list 배열의 첫 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list + 0 \t= %p\n", list+0);
    // list 배열의 두 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list + 1 \t= %p\n", list+1);
    // list 배열의 세 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list + 2 \t= %p\n", list+2);
    // list 배열의 네 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list + 3 \t= %p\n", list+3);
    // list 배열의 다섯 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list + 4 \t= %p\n", list+4);
    // list 배열의 다섯 번 째 요소가 저장되는 메모리 공간의 주솟값을 출력(=list+4)
    printf("&list[4] \t= %p\n", &list[4]);
    
    free(plist[0]); // malloc 함수를 이용하여 동적할당된 plist[0] 메모리 공간을 해제함
}