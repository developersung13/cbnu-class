#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가

// print_one에 대한 함수 프로토타입 선언
void print_one(int *ptr, int rows);

int main() {
    // 0~4(5개)의 정수형 데이터를 저장하는 정수형 배열 선언 
    int one[] = {0, 1, 2, 3, 4};

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");
    
    // 정수형 배열 one에 대한 포인터 주솟값 출력
    printf("one = %p\n", one);
    // 정수형 배열 one이 저장되어 있는 메모리 주솟값을 출력
    printf("&one = %p\n", &one);
    // 정수형 배열 one의 첫 번째 데이터가 저장되어 있는 메모리 공간의 주솟값을 출력
    printf("&one[0] = %p\n", &one[0]);
    printf("\n"); // 개행
    
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    /* 정수형 배열 one의 첫 번째 데이터가 저장되어 있는 메모리 공간의 주솟값과,
    배열의 크기를 print_one의 인수로 전달 */
    print_one(&one[0], 5);
    
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    // 정수형 배열의 포인터 주솟값과, 배열의 크기를 print_one의 인수로 전달
    print_one(one, 5);
    
    // 0을 반환함으로써 프로그램을 종료
    return 0;
}
    
// 정수형 배열 one에 저장된 요소들을 지정된 크기만큼 출력하는 print_one 함수 정의
void print_one(int *ptr, int rows) {
    /* print out a one-dimensional array using a pointer */
    int i; // for문의 인덱스용 변수 선언
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++) { // 0~rows번까지 반복
        // 정수형 포인터 변수 ptr(=주솟값)에 i를 더한 주솟값과, 해당 주솟값에 저장되어 있는 데이터를 출력
        printf("%p \t %5d\n", ptr + i, *(ptr + i));
    }
    printf("\n"); // 개행
}