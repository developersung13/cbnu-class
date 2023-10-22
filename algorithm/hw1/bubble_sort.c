#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    int k, z;
    bool swapped;
    for (k = 0; k < n - 1; k++){
        swapped = false;
        for (z = 0; z < n - k - 1; z++){
            if (arr[z] < arr[z + 1]) {
                swap(&arr[z], &arr[z + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main() {
    // 난수 생성을 위한 초기화
    srand(time(NULL));

    int arr[100];

    printf("Before Bubble Sorting: ");
    for (int k = 0; k < 100; k++) {
        // 1~3000 사이의 임의의 정수 생성
        arr[k] = rand() % 3000 + 1; 
        printf("%d ", arr[k]);
    } printf("\n\n");

    int n = sizeof(arr)/sizeof(arr[0]);
    
    clock_t s_time = clock();  // 실행 시작 시간 기록
    bubble_sort(arr, n);
    clock_t e_time = clock();  // 실행 종료 시간 기록
    
    printf("After Bubble Sorting: ");
    for (int k = 0; k < n; k++)
        printf("%d ", arr[k]);
    printf("\n");

    // 실행 시간 계산 (단위: ms)
    double runtime = ((double)(e_time - s_time) / CLOCKS_PER_SEC) * 1000;
    printf("Run-time: %.5f milliseconds\n", runtime);  // 실행 시간 출력
    
    return 0;
}
