#include <stdio.h> // 표준 입출력 함수(printf, scanf) 사용을 위한 라이브러리 추가
#include <stdlib.h> // (rand) 함수 호출을 위한 라이브러리 추가
#include <time.h> // (srand, time) 함수 호출을 위한 라이브러리 추가

int matrixA_row, matrixA_column, matrixB_row, matrixB_column;

// 매개변수로 받은 행렬 변수의 동적할당을 해제하는 함수
void free_matrix(int **matrix) {
    free(matrix); // 메모리 heap 공간에 동적할당된 변수를 해제
}

// 행렬 A와 B 그리고 행렬의 연산 결과를 출력하는 함수
void print_matrix(int **matrixA, int **matrixB, int **matrixResult, char op) {
    int k, z; // for문의 인덱스 변수로써 사용될 변수 k, z 선언

    printf("\n<Matrix A>\n");
    for (k=0; k < matrixA_row; k++) { // matrixA_row번 만큼 반복
        for (z=0; z < matrixA_column; z++) // matrixA_column번 만큼 반복
            printf("%d ", matrixA[k][z]); // 행렬 A의 값을 차례대로 출력
        printf("\n"); // 개행
    }

    printf("\n<Matrix B>\n");
    for (k=0; k < matrixB_row; k++) { // matrixB_row번 만큼 반복
        for (z=0; z < matrixB_column; z++) // matrixB_column번 만큼 반복
            printf("%d ", matrixB[k][z]); // 행렬 B의 값을 차례대로 출력
        printf("\n"); // 개행
    }
    
    // 행렬에 수행된 연산을 기반으로 해당 연산 결과를 출력
    switch(op) {
        case '+': // 행렬 A + B의 연산이 수행된 후 print_matrix가 호출된 케이스
            printf("\n<Matrix A + B>\n");
            for (k=0; k < matrixA_row; k++) { // matrixA_row번 만큼 반복
               for (z=0; z < matrixA_column; z++) // matrixA_column번 만큼 반복
                    printf("%d ", matrixResult[k][z]); // // 행렬 result의 값을 차례대로 출력
                printf("\n"); // 개행
            }
            break;
        case '-': // 행렬 A - B의 연산이 수행된 후 print_matrix가 호출된 케이스
            printf("\n<Matrix A - B>\n");
            for (k=0; k < matrixA_row; k++) { // matrixA_row번 만큼 반복
               for (z=0; z < matrixA_column; z++) // matrixA_column번 만큼 반복
                    printf("%d ", matrixResult[k][z]); // // 행렬 result의 값을 차례대로 출력
                printf("\n"); // 개행
            }
            break;
        case 'X': // 행렬 A X B의 연산이 수행된 후 print_matrix가 호출된 케이스
            printf("\n<Matrix A X B>\n");
            for (k=0; k < matrixA_row; k++) { // matrixA_row번 만큼 반복
               for (z=0; z < matrixB_column; z++) // matrixB_column번 만큼 반복
                    printf("%d ", matrixResult[k][z]); // // 행렬 result의 값을 차례대로 출력
                printf("\n"); // 개행
            }
            break;
        case '~': // 행렬 A의 전치행렬 변환이 수행된 후 print_matrix가 호출된 케이스
            // print_matrix 함수 초반에 전치행렬된 A를 이미 출력하므로, 별도의 출력을 수행하지 않음
            break;
        default:
            /* op가 (+, -, X, ~)외에 다른 문자로 print_matrix 함수의 매개변수에 담겨
            호출되었을 때 문제가 발생하였음을 알림 */
            printf("invalid op value is called...\n");
            return; // print_matrix 함수 종료
    }
    
    printf("\n===========\n"); // 구분선 출력
    
    // matrixResult 변수 동적 메모리 할당 해제
    free_matrix(matrixResult);
}

// 행렬 A + B 연산을 수행하는 함수
void addition_matrix(int **matrixA, int **matrixB) {
    int k, z; // for문의 인덱스 변수로써 사용될 변수 k, z 선언
    
    // 행렬 A + B한 연산 결괏값을 저장하는 용도로 사용될 행렬 result선언
    // 행렬 result의 행에 대한 동적 메모리 할당
    int **matrixResult = (int**)malloc(sizeof(int *) * matrixA_row);
    // 행렬 result의 열에 대한 동적 메모리 할당
    for (k=0; k < matrixA_row; k++)
        matrixResult[k] = (int*)malloc(sizeof(int) * matrixA_column);
        
    // 행렬 A, B의 값을 각각 합한 값을 결과 행렬에 저장
    for (k=0; k < matrixA_row; k++) // matrixA_row번 만큼 반복
        for (z=0; z < matrixA_column; z++) // matrixA_column번 만큼 반복
            matrixResult[k][z] = matrixA[k][z] + matrixB[k][z];
    
    // 행렬 A, B와 A + B된 결괏값을 출력하는 print_matrix함수 호출
    print_matrix(matrixA, matrixB, matrixResult, '+');
}

// 행렬 A - B 연산을 수행하는 함수
void subtraction_matrix(int **matrixA, int **matrixB) {
    int k, z; // for문의 인덱스 변수로써 사용될 변수 k, z 선언
    
    // 행렬 A, B의 연산 결괏값을 저장하는 용도로 사용될 행렬 result선언
    // 행렬 result의 행에 대한 동적 메모리 할당
    int **matrixResult = (int**)malloc(sizeof(int *) * matrixA_row);
    // 행렬 result의 열에 대한 동적 메모리 할당
    for (k=0; k < matrixA_row; k++)
        matrixResult[k] = (int*)malloc(sizeof(int) * matrixA_column);
    
    // 행렬 A, B의 값을 각각 뺀 값을 결과 행렬에 저장
    for (k=0; k < matrixA_row; k++) // matrixA_row번 만큼 반복
        for (z=0; z < matrixA_column; z++) // matrixA_column번 만큼 반복
            matrixResult[k][z] = matrixA[k][z] - matrixB[k][z];

    // 행렬 A, B와 A - B된 결괏값을 출력하는 print_matrix함수 호출
    print_matrix(matrixA, matrixB, matrixResult, '-');
}

// 행렬 A의 전치행렬 T를 구하는 함수
void transpose_matrix(int **matrixA, int **matrixB) {
    int k, z; // for문의 인덱스 변수로써 사용될 변수 k, z 선언
    
    // 행렬 A의 전치행렬로써 연산 결괏값을 저장하는 용도로 사용될 행렬 result선언
    // 행렬 result의 행에 대한 동적 메모리 할당
    int **matrixResult = (int**)malloc(sizeof(int *) * matrixA_column);
    // 행렬 result의 열에 대한 동적 메모리 할당
    for (k=0; k < matrixA_column; k++)
        matrixResult[k] = (int*)malloc(sizeof(int) * matrixA_row);
    
    // 행렬 A를 전치시킨 값을 행렬 result에 저장
    for (k=0; k < matrixA_row; k++) // row번 만큼 반복
        for (z=0; z < matrixA_column; z++) // column번 만큼 반복
            matrixResult[z][k] = matrixA[k][z];
            
    /* 행렬 A를 전치된 행렬로써 다시 저장할 수 있도록 realloc 함수를 사용하여
    row와 column이 서로 바뀐 크기로 동적 메모리 재할당, 행렬 A의 행에 대한 동적 메모리 재할당*/
    matrixA = (int**)realloc(matrixA, sizeof(int*) * matrixA_column);
    // 행렬 A의 열에 대한 동적 메모리 재할당
    for (k=0; k < matrixA_column; k++)
        matrixA[k] = (int*)realloc(matrixA[k], sizeof(int) * matrixA_row);
        
    /* 행렬 A의 전치행렬로써 저장된 행렬 result의 값을
    다시 동적 메모리 재할당된 행렬 A에 대입 */
    for (k=0; k < matrixA_column; k++) // matrixA_column번 만큼 반복
        for (z=0; z < matrixA_row; z++) // matrixA_row번 만큼 반복
            matrixA[k][z] = matrixResult[k][z];
    
    // 행렬 A를 전치행렬로 변환하기 위해 기존 행렬 A의 행과 열의 값을 서로 교환(SWAP)
    int temp = matrixA_row;
    matrixA_row = matrixA_column;
    matrixA_column = temp;
    
    // 행렬 A, B와 전치된 행렬 A의 결괏값을 출력하는 print_matrix함수 호출
    print_matrix(matrixA, matrixB, matrixResult, '~');
}

// int형 데이터를 반환하는 main 함수 정의
int main() {
    srand(time(NULL)); // 난수 생성 시 초기 시드 값을 설정
    int k, z; // for문의 인덱스 변수로써 사용될 변수 k, z 선언

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    printf("Enter the row value of matrix: ");
    scanf("%d", &matrixA_row); // 행렬 A의 행 값을 입력
    matrixB_row = matrixA_row; // 행렬 A의 행 값을 행렬 B의 행 값에 대입

    printf("Enter the column value of matrix: ");
    scanf("%d", &matrixA_column); // 행렬 A의 열 값을 입력
    matrixB_column = matrixA_column; // 행렬 A의 열 값을 행렬 B의 열 값에 대입

    // 행렬 A의 행에 대한 동적 메모리 할당
    int **matrixA = (int**)malloc(sizeof(int *) * matrixA_row);
    // 행렬 A의 열에 대한 동적 메모리 할당
    for (k=0; k < matrixA_row; k++)
        matrixA[k] = (int*)malloc(sizeof(int) * matrixA_column);

    // 행렬 B의 행에 대한 동적 메모리 할당
    int **matrixB = (int**)malloc(sizeof(int *) * matrixB_row);
    // 행렬 A의 열에 대한 동적 메모리 할당
    for (k=0; k < matrixB_row; k++)
        matrixB[k] = (int*)malloc(sizeof(int) * matrixB_column);

    // 행렬 A, B에 1~9 사이의 임의의 값을 대입
    for (k=0; k < matrixA_row; k++)
        for (z=0; z < matrixB_column; z++) {
            matrixA[k][z] = rand() % 9 + 1;
            matrixB[k][z] = rand() % 9 + 1;
        }

    // 행렬 A + B 연산을 수행하는 함수 호출
    addition_matrix(matrixA, matrixB);

    // 행렬 A - B 연산을 수행하는 함수 호출
    subtraction_matrix(matrixA, matrixB);

    // 행렬 A를 전치행렬로 만드는 함수 호출
    transpose_matrix(matrixA, matrixB);

    // matrixA 변수(=행렬 A) 동적 메모리 할당 해제
    free_matrix(matrixA);

    // matrixB 변수(=행렬 B) 동적 메모리 할당 해제
    free_matrix(matrixB);

    return 0; // 0을 반환함으로써 main함수 종료(=프로그램 종료)
}