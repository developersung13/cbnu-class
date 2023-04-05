#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가
#include <stdlib.h> // 메모리 동적할당 malloc 함수 사용을 위한 라이브러리 추가

int main() {
    int list[5]; // 정수형 데이터 5개를 저장할 수 있는 정수형 배열 선언.
    /* 데이터의 주솟값을 5개 저장할 수 있는 정수형 포인터 배열 선언 및
    할당된 메모리 공간에는 NULL로 일괄 초기화 */
    int *plist[5] = {NULL,};
    
    // plist 배열의 첫 번째 데이터 공간에 int 크기(=4Bytes)의 메모리 할당
    plist[0] = (int *)malloc(sizeof(int));
    
    list[0] = 1; // list[0](=list 배열의 첫 번째 공간)에 1의 값을 할당
    list[1] = 100; // list[1](=list 배열의 두 번째 공간)에 100의 값을 할당
    
    *plist[0] = 200; // plist[0](=plist 배열의 첫 번째 공간)에 200의 값을 할당

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");
    
    printf("list[0] = %d\n", list[0]); // list 배열에 저장된 첫 번째 데이터를 출력
    // list 배열에 저장된 첫 번째 데이터가 위치한 메모리 공간의 주솟값을 출력
    printf("&list[0] = %p\n", &list[0]);
    // list 배열의 시작 주솟값을 출력(=&list[0])
    printf("list = %p\n", list);
    // list 배열이 가리키고 있는 메모리 공간의 주솟값을 출력(=&list[0], list)
    printf("&list = %p\n", &list);
    
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]); // list 배열에 저장된 두 번째 데이터를 출력
    // list 배열에 저장된 두 번째 데이터가 위치한 메모리 공간의 주솟값을 출력
    printf("&list[1] = %p\n", &list[1]);
    // list 배열의 두 번째 공간에 저장되어 있는 데이터를 출력
    printf("*(list+1) = %d\n", *(list + 1));
    // list 배열의 두 번째 요소가 저장되는 메모리 공간의 주솟값을 출력
    printf("list+1 = %p\n", list+1);
    
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); // plist 배열에 저장된 첫 번째 데이터를 출력
    // plist 배열에 저장된 첫 번째 데이터가 위치한 메모리 공간의 주솟값을 출력
    printf("&plist[0] = %p\n", &plist[0]);
    // plist 배열이 가리키고 있는 메모리 공간의 주솟값을 출력(=&plist[0], plist)
    printf("&plist = %p\n", &plist);
    // plist 배열이 가리키고 있는 메모리 공간의 주솟값을 출력
    // plist 배열의 시작 주솟값을 출력(=&plist[0], &plist)
    printf("plist = %p\n", plist);
    // plist[0] 데이터가 저장된 메모리 공간의 주솟값을 출력
    printf("plist[0] = %p\n", plist[0]);
    // plist[1] 데이터가 저장된 메모리 공간의 주솟값을 출력 (할당된 메모리 공간이 존재하지 않으므로, 0x0 또는 (nil) 출력)
    printf("plist[1] = %p\n", plist[1]);
    // plist[2] 데이터가 저장된 메모리 공간의 주솟값을 출력 (할당된 메모리 공간이 존재하지 않으므로, 0x0 또는 (nil) 출력)
    printf("plist[2] = %p\n", plist[2]);
    // plist[3] 데이터가 저장된 메모리 공간의 주솟값을 출력 (할당된 메모리 공간이 존재하지 않으므로, 0x0 또는 (nil) 출력)
    printf("plist[3] = %p\n", plist[3]);
    // plist[4] 데이터가 저장된 메모리 공간의 주솟값을 출력 (할당된 메모리 공간이 존재하지 않으므로, 0x0 또는 (nil) 출력)
    printf("plist[4] = %p\n", plist[4]);
    
    free(plist[0]); // 메모리 동적할당 해제
    
    return 0; // 0을 반환함으로써 프로그램을 종료
}