#include <stdio.h>   // printf, perror 함수 사용을 위해 stdio 헤더 파일을 사용함
#include <stdlib.h>  // atoi, malloc, free, exit 함수 사용을 위해 stdlib 헤더 파일을 사용함
#include <pthread.h> // pthread_create, pthread_join 함수 사용을 위해 pthread.h 헤더 파일을 사용함

int N; // 전역 변수로, 스레드에 의해 공유되는 변수

// 스레드 함수: 각 스레드에 의해 실행되며, 누적 합산 또는 팩토리얼 연산을 수행함
void *threadCalcSumOrFactorial(void *arg) {
    int k, thread_id = *(int*)arg; // 정수형 변수 k, 스레드 ID를 인자로부터 가져와 초기화 하여 선언
    long res = 0; // 결과값을 저장할 lonng 자료형의 변수
    if (thread_id == 0) { // 첫 번째 스레드인 경우, 팩토리얼을 계산함
        res = 1; // 누적 곱셈 연산을 위해 res를 기본적으로 1로 초기화 함
        for (k = 1; k <= N; k++) // 1부터 N까지 반복함
            res *= k; // res에 res * k 연산을 통해 계산된 값을 누적시킴
        printf("sumfact : factorial = %ld\n", res); // 계산된 팩토리얼 값을 출력
        free(arg); // 동적 할당된 메모리 해제
        return NULL; // 함수 종료
    }

    // 그 외의 스레드는 합을 계산
    for (k = 1; k <= N; k++) // 1부터 N까지 반복
        res += k; // res에 res + k 연산을 통해 계산된 값을 누적시킴
    printf("sumfact : sum = %ld\n", res); // 계산된 누적 합산 값을 출력
    free(arg); // 동적 할당된 메모리 해제
    return NULL; // 함수 종료
}

// 메인 함수: 프로그램의 시작점
int main(int argc, char *argv[]) {
    int k, z, createdThreadCnt = 0; // 정수형 변수 k, z, 생성된 스레드의 수를 저장하는 createdThreadCnt 변수 선언
    N = atoi(argv[1]); // 명령줄 인자를 정수로 변환하여 N에 저장
    pthread_t threads[N]; // 스레드 식별자 배열

    // N개의 스레드를 생성함
    for (k = 0; k < N; k++) { // 0부터 N-1까지 반복함
        int *id = malloc(sizeof(int)); // 스레드 ID를 위한 메모리 할당
        if (id == NULL) { // 메모리 할당 실패 검사
            for (z = 0; z < createdThreadCnt; z++) // 0부터 스레드가 생성된 수만큼 반복함
                pthread_join(threads[z], NULL); // 생성된 각 스레드가 종료될 때까지 대기함
            return 1; // 메모리 할당 실패시 프로그램 종료
        }

        *id = k; // 스레드 ID를 설정함
        if (pthread_create(&threads[k], NULL, threadCalcSumOrFactorial, id) != 0) { // 스레드 생성
            perror("pthread_create failed!!"); // 스레드 생성 실패 시 에러 메시지 출력
            free(id); // 메모리 해제
            for (z = 0; z < createdThreadCnt; z++) // 0부터 스레드가 생성된 수만큼 반복함
                pthread_join(threads[z], NULL); // 생성된 스레드를 정리
            return 1; // 스레드 생성 실패시 프로그램 종료
        }

        createdThreadCnt++; // 생성된 스레드 수를 증가시킴
    }

    for (k = 0; k < N; k++) // 0부터 N까지 반복
        pthread_join(threads[k], NULL); // 반복문을 통해 모든 스레드의 종료를 위해 대기함

    return 0; // 프로그램을 정상 종료시킴
}
