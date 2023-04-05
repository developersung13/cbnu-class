#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가

#define MAX_SIZE 100

// sum1~sum3까지의 함수 프로토타입 선언
float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

// 100개의 4Bytes 실수형 데이터를 저장할 수 있는 배열 및 일반 실수형 변수 선언
float input[MAX_SIZE], answer;
// for문의 인덱스 변수로 사용될 정수형 변수 선언
int i;

int main() {
    // 100번(0~99) 반복
    for(i=0; i < MAX_SIZE; i++)
        input[i] = i; // input 배열의 1번 째~100번 째 공간에 각각 0~99 데이터 대입

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");
    
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 시작 주솟값을 출력
    
    answer = sum1(input, MAX_SIZE); // sum1 함수를 호출
    printf("The sum is: %f\n\n", answer); // sum1함수의 반환값을 출력
    
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 시작 주솟값을 출력
    
    answer = sum2(input, MAX_SIZE); // sum2 함수를 호출
    printf("The sum is: %f\n\n", answer); // sum2함수의 반환값을 출력
    
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 시작 주솟값을 출력
    
    answer = sum3(MAX_SIZE, input); // sum3함수를 호출
    printf("The sum is: %f\n\n", answer); // sum3함수의 반환값을 출력
}

float sum1(float list[], int n) {
    printf("list \t= %p\n", list); // 매개변수 list 배열의 주솟값을 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열의 주소를 저장한 포인터 변수의 주솟값을 출력
    
    int i;
    float tempsum = 0;
    for (i=0; i < n; i++)
        tempsum += list[i]; // 배열의 모든 요소를 누적하여 더함
    return tempsum; // 배열의 모든 요소가 누적된 총합을 반환함
}

float sum2(float *list, int n) {
    printf("list \t= %p\n", list); // 매개변수 list 배열의 주솟값을 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열의 주소를 저장한 포인터 변수의 주솟값을 출력

    int i;
    float tempsum = 0;
    for (i=0; i < n; i++)
        tempsum += *(list + i); // 배열의 모든 요소를 누적하여 더함
    return tempsum; // 배열의 모든 요소가 누적된 총합을 반환함
}

/* stack variable reuse test */
float sum3(int n, float *list) {
    printf("list \t= %p\n", list); // 매개변수 list 배열의 주솟값을 출력
    printf("&list \t= %p\n\n", &list); // 매개변수 list 배열의 주소를 저장한 포인터 변수의 주솟값을 출력

    int i;
    float tempsum = 0;
    for (i=0; i < n; i++)
        tempsum += *(list + i); // 배열의 모든 요소를 누적하여 더함
    return tempsum; // 배열의 모든 요소가 누적된 총합을 반환함
}