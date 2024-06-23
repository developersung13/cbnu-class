#include <stdio.h>  // printf, perror 함수 사용을 위해 stdio 헤더 파일을 사용함
#include <stdlib.h> // atoi, exit 함수 사용을 위해 stdlib 헤더 파일을 사용함
#include <unistd.h> // fork, execlp 함수 사용을 위해 unistd 헤더 파일을 사용함
#include <sys/wait.h> // wait 함수 사용을 위해 sys/wait 헤더 파일을 사용함

// 메인 함수: 프로그램의 시작을 의미함
int main(int argc, char *argv[]) {
    int k, stat, N = atoi(argv[1]); // 정수형 변수 k, 상태변수 stat 선언 및 N에 명령줄 인자를 정수로 변환하여 저장
    long res = 0; // long 타입 변수 res 선언 및 0으로 초기화
    pid_t pid = fork(); // fork 함수 호출을 통해 child 프로세스 생성 후 결과를 pid 변수에 저장

    if (pid == -1) // fork 호출 실패에 대한 검사
        exit(1); // 실패 시 프로그램 종료 후 에러 코드 1 반환

    if (pid == 0) { // 자식 프로세스인 경우
        printf("launch : start sumfact %d\n", N); // 자식 프로세스의 시작을 알리는 문장을 출력
        execlp("./sumfact", "sumfact", argv[1], NULL); // execlp 함수를 통해 sumfact 프로그램 실행
        perror("execelp failed!!"); // execlp 실패 시 에러 메시지를 출력
        exit(1); // 프로그램을 종료 후 에러 코드 1 반환
    } else { // 부모 프로세스인 경우
        wait(&stat); // 자식 프로세스가 종료될 때까지 대기함
        for (k = 1; k <= N; k++) // 1부터 N까지 반복함
	    res += k; // res에 k값을 누적시킴
        printf("launch : sum = %ld\n", res); // 계산된 합계를 출력함
    }

    return 0; // 메인 함수 종료, 성공적 종료 코드 0 반환
}
