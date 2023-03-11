#include <stdio.h> // 표준출력함수(printf)를 사용(호출)하기 위해 stdio.h 헤더파일을 #include로 포함

// int형 데이터를 반환하는 main 함수 정의
int main() {
    int i; // (정수형 변수)i 선언
    int *ptr; // (정수형 포인터 변수)ptr 선언
    int **dptr; // (정수형 2중 포인터 변수)dptr 선언
    i = 1234; // (정수형 변수)i에 1234의 값으로 초기화

    // [----- [Yeolam Sung, 성열암] [2020039037] -----] 문장 출력 및 개행
    printf("[----- [Yeolam Sung, 성열암] [2020039037] -----]\n");

    printf("[checking values before ptr = &i] \n"); // [checking values before ptr = &i] 문장 출력 및 개행
     // (정수형 변수)i의 값을 부호가 있는 10진수 정수로 출력 => value of i == 1234
    printf("value of i == %d\n", i);
    // (정수형 변수)i가 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of i == %p\n", &i);
    /** (정수형 포인터 변수)ptr의 값을 포인터 16진수로 출력, 이때 (정수형 포인터 변수)ptr은 초기화가 되어있지 않으므로, 프로그램이
      * 실행될 때 메모리에 있었던 임의의 값이 출력될 수도 있다. 다른 컴파일러의 경우 (nil)값이 나타나기도 한다.
        => value of ptr = 0x?????? */
    printf("value of ptr == %p\n", ptr);
    // (정수형 포인터 변수)ptr이 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of ptr == %p\n", &ptr);

    /** (정수형 변수)i가 저장되어 있는 메모리 공간의 주솟값을 (정수형 포인터 변수)ptr에 초기화
        (정수형 포인터 변수)ptr이 (정수형 변수)i에 저장되어 있는 메모리 공간을 참조할 수 있게됨 */
    ptr = &i;
    printf("\n[checking values after ptr = &i] \n"); // [checking values after ptr = &i] 문장 출력 및 개행
    // (정수형 변수)i의 값을 부호가 있는 10진수 정수로 출력 => value of i == 1234
    printf("value of i == %d\n", i);
    // (정수형 변수)i가 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of i == %p\n", &i);
    /** (정수형 포인터 변수)ptr의 값을 포인터 16진수로 출력, 이때 ptr은 (정수형 변수)i의 주솟값으로 초기화되어 있기 때문에
        i의 주솟값과 동일한 결과를 출력함 => value of ptr == 0x?????? */
    printf("value of ptr == %p\n", ptr);
    // (정수형 포인터 변수)ptr이 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of ptr == %p\n", &ptr);
    /** (정수형 포인터 변수)ptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터를 참조하여 출력함(=i의 값)
        => value of *ptr == 1234 */
    printf("value of *ptr == %d\n", *ptr);

    /** (정수형 포인터 변수)ptr이 저장되어 있는 메모리 공간의 주솟값을 (정수형 2중 포인터 변수)dptr에 초기화
        (정수형 2중 포인터 변수)dptr가 (정수형 포인터 변수)ptr에 저장되어 있는 메모리 공간을 참조할 수 있게됨 */
    dptr = &ptr;
    printf("\n[checking values after dptr = &ptr] \n"); // [checking values after dptr = &ptr] 문장 출력 및 개행
    // (정수형 변수)i의 값을 부호가 있는 10진수 정수로 출력 => value of i == 1234
    printf("value of i == %d\n", i);
    // (정수형 변수)i가 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of i == %p\n", &i);
    /** (정수형 포인터 변수)ptr의 값을 포인터 16진수로 출력, 이때 ptr은 (정수형 변수)i의 주솟값으로 초기화되어 있기 때문에
        i의 주솟값과 동일한 결과를 출력함 => value of ptr == 0x?????? */
    printf("value of ptr == %p\n", ptr);
    // (정수형 포인터 변수)ptr가 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of i == 0x??????
    printf("address of ptr == %p\n", &ptr);
    /** (정수형 포인터 변수)ptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터를 참조하여 출력함(=i의 값)
        => value of *ptr == 1234 */
    printf("value of *ptr == %d\n", *ptr);
    /** (정수형 2중 포인터 변수)dptr의 값을 포인터 16진수로 출력, 이때 dptr은 (정수형 포인터 변수)ptr의 주솟값으로 초기화되어 있기 때문에
        ptr의 주솟값과 동일한 결과를 출력함 => value of dptr == 0x?????? */
    printf("value of dptr == %p\n", dptr);
    // (정수형 2중 포인터 변수)dptr가 저장되어 있는 메모리 공간의 주솟값을 포인터 16진수로 출력 => address of dptr == 0x??????
    printf("address of dptr == %p\n", &dptr);
    /** (정수형 2중 포인터 변수)dptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터를 참조하여 출력함(=ptr의 값 == i의 주솟값)
        => value of *dptr == 0x?????? */
    printf("value of *dptr == %p\n", *dptr);
    /** (정수형 2중 포인터 변수)dptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터가 다시 참조하고 있는 데이터를 출력함(=i의 값)
        => value of **dptr == 1234 */
    printf("value of **dptr == %d\n", **dptr);

    /** (정수형 포인터 변수)ptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터의 값을 7777로 변경
        결과적으로, i의 값이 1234에서 7777로 변경됨 */
    *ptr = 7777;
    printf("\n[after *ptr = 7777] \n"); // [after *ptr = 7777] 문장 출력 및 개행
    // (정수형 변수)i의 값을 부호가 있는 10진수 정수로 출력 => value of i == 7777
    printf("value of i == %d\n", i);
    /** (정수형 포인터 변수)ptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터를 참조하여 출력함(=i의 값)
        => value of *ptr == 7777 */
    printf("value of *ptr == %d\n", *ptr);
    /** (정수형 2중 포인터 변수)dptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터가 다시 참조하고 있는 데이터를 출력함(=i의 값)
        => value of **dptr == 7777 */
    printf("value of **dptr == %d\n", **dptr);

    /** (정수형 2중 포인터 변수)dptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터가 다시 참조하고 있는 데이터의 값을 8888로 변경
        결과적으로, i의 값이 7777에서 8888로 변경됨 */
    **dptr = 8888;
    printf("\n[after **dptr = 8888] \n"); // [after **dptr = 8888] 문장 출력 및 개행
    // (정수형 변수)i의 값을 부호가 있는 10진수 정수로 출력 => value of i == 8888
    printf("value of i == %d\n", i);
    /** (정수형 포인터 변수)ptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터를 참조하여 출력함(=i의 값)
        => value of *ptr == 8888 */
    printf("value of *ptr == %d\n", *ptr);
    /** (정수형 2중 포인터 변수)dptr이 현재 가리키고 있는 메모리 주소 내에 저장되어 있는 데이터가 다시 참조하고 있는 데이터를 출력함(=i의 값)
        => value of **dptr == 8888 */
    printf("value of **dptr == %d\n", **dptr);

    return 0; // 0을 반환함으로써 main함수 종료(=프로그램 종료)
}