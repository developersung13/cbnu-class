#include <stdio.h> // 표준출력함수(printf)를 사용(호출)하기 위해 stdio.h 헤더파일을 #include로 포함

// int형 데이터를 반환하는 main 함수 정의
int main() {
    char charType; // (문자형 변수)charType과 선언
    int integerType; // (정수형 변수)integerType 선언
    float floatType; // (4Bytes 메모리 크기의 실수형 변수)floatType 선언
    double doubleType; // // (8Bytes 메모리 크기의 실수형 변수)doubleType 선언

    // [----- [Yeolam Sung, 성열암] [2020039037] -----] 문장 출력 및 개행
    printf("[----- [Yeolam Sung, 성열암] [2020039037] -----]\n");

    // (문자형)charType 변수가 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of char: 1 byte
    printf("Size of char: %ld byte\n",sizeof(charType));
    // (정수형)integerType 변수가 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of int: 4 bytes
    printf("Size of int: %ld bytes\n",sizeof(integerType));
    // (4Bytes, 실수형)floatType 변수가 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of float: 4 bytes
    printf("Size of float: %ld bytes\n",sizeof(floatType));
    // (8Bytes, 실수형)doubleType 변수가 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of double: 8 bytes
    printf("Size of double: %ld bytes\n",sizeof(doubleType));
    printf("-----------------------------------------\n"); // 구분선 출력
    // char 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of char: 1 byte
    printf("Size of char: %ld byte\n",sizeof(char));
    // int 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of int: 4 bytes
    printf("Size of int: %ld bytes\n",sizeof(int));
    // float 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of float: 4 bytes
    printf("Size of float: %ld bytes\n",sizeof(float));
    // double 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of double: 8 bytes
    printf("Size of double: %ld bytes\n",sizeof(double));
    printf("-----------------------------------------\n"); // 구분선 출력
    // (사전 해석, 포인터 자료형들의 경우 가용할 수 있는 모든 메모리의 경우의 수를 표현하기 위해서 프로그램이 실행되는 OS의 비트수를 기준으로 자료형의 크기가 결정된다)
    // char* 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of char*: 8 byte (64비트 OS 기준, 32비트는 4bytes)
    printf("Size of char*: %ld byte\n",sizeof(char*));
    // int* 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of int*: 8 bytes (64비트 OS 기준, 32비트는 4bytes)
    printf("Size of int*: %ld bytes\n",sizeof(int*));
    // float* 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of float*: 8 bytes (64비트 OS 기준, 32비트는 4bytes)
    printf("Size of float*: %ld bytes\n",sizeof(float*));
    // double* 데이터 타입이 메모리에서 차지하는 Byte 값을 long 데이터 타입으로 출력 => Size of double*: 8 bytes (64비트 OS 기준, 32비트는 4bytes)
    printf("Size of double*: %ld bytes\n",sizeof(double*));

    return 0; // 0을 반환함으로써 main함수 종료(=프로그램 종료)
}