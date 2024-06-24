#include <stdio.h>  // 표준 입출력 함수 사용을 위한 포함
#include <stdlib.h> // atoi, malloc, free 등의 표준 라이브러리 함수 사용을 위한 포함
#include <string.h> // 문자열 처리 함수 사용하을 위한 포함

#define MAX_LINE_LEN 15 // 파일에서 읽어올 문자열 한 줄의 최대 길이를 15로 정의
#define MAX_ACCESS_LEN 50000 // 최대 50000개의 액세스를 처리할 수 있도록 배열 크기를 정의

// 프로그램의 시작 지점인 메인 함수
int main(int argc, char* argv[]) {
    // 명령어 인자에서 첫 번째 인자를 알고리즘 이름으로 받음
    const char* algorithm = argv[1];
    // 명령어 인자에서 두 번째 인자를 프레임 수로 받아 정수로 변환함
    int frameCount = atoi(argv[2]);

    // 파일에서 한 줄의 데이터를 읽어올 버퍼를 선언
    char line[MAX_LINE_LEN];
    // 페이지 번호를 저장할 정수형 배열 선언
    int pageNumbers[MAX_ACCESS_LEN];
    // 작업 유형을 저장할 문자형 배열 선언
    char operations[MAX_ACCESS_LEN];
    // 총 접근 수를 저장할 변수를 0으로 초기화
    int totalAccess = 0;
    // 읽기 수, 쓰기 수, 히트 수, 폴트 수를 저장할 변수를 0으로 초기화
    int readCnt = 0, writeCnt = 0, hitCnt = 0, faultCnt = 0;

    // 현재 디렉토리에서 access.list 파일을 읽기 모드로 엶
    FILE* file = fopen("access.list", "r");
    // 파일 열기에 실패한 경우
    if (!file) {
        // 오류 메시지를 출력하고
        printf("Cannot read the file!");
        // 프로그램을 종료함
        return 0;
    }

    // 파일에서 한 줄씩 데이터를 읽어옴
    while (fgets(line, sizeof(line), file) != NULL) {
        // 페이지 번호를 저장할 변수를 선언
        int pageNumber;
        // 작업 유형을 저장할 배열을 선언
        char operation[10];
        // 한 줄의 데이터를 페이지 번호와 작업 유형으로 파싱
        if (sscanf(line, "%d %s", &pageNumber, operation) == 2 && totalAccess < MAX_ACCESS_LEN) {
            // 페이지 번호를 배열에 저장
            pageNumbers[totalAccess] = pageNumber;
            // 작업 유형을 판별하여 'R' 또는 'W'로 저장
            operations[totalAccess] = (operation[0] == 'r' || operation[0] == 'R') ? 'R' : 'W';
            // 총 접근 수를 증가시킴
            totalAccess++;
        }
    }
    // 파일을 닫음
    fclose(file);

    // 알고리즘을 판별하여 처리하는 switch-case문
    switch (algorithm[0]) {
        case 'f': // FIFO 알고리즘인 경우
        {
            // 프레임 배열을 동적으로 할당
            int *frames = (int *)malloc(frameCount * sizeof(int));
            // 다음 교체 위치를 0으로 초기화
            int nextReplace = 0;
            // 프레임 배열을 -1로 초기화하여 비어있는 상태로 설정
            memset(frames, -1, frameCount * sizeof(int));

            // 총 접근 수만큼 순회하며 페이지를 처리함
            for (int i = 0; i < totalAccess; i++) {
                // 현재 접근하는 페이지 번호를 가져옴
                int page = pageNumbers[i];
                // 현재 접근하는 작업 유형을 가져옴
                char operation = operations[i];
                // 히트 여부를 0으로 초기화
                int hit = 0;

                // 프레임 배열에서 현재 페이지를 검색
                for (int j = 0; j < frameCount; j++) {
                    // 현재 페이지가 프레임에 존재하는 경우
                    if (frames[j] == page) {
                        // 히트 발생
                        hit = 1;
                        // 히트 수를 증가시킴
                        hitCnt++;
                        // 검색을 중단함
                        break;
                    }
                }

                // 히트가 발생하지 않은 경우
                if (!hit) {
                    // 현재 페이지를 교체할 위치에 저장
                    frames[nextReplace] = page;
                    // 다음 교체 위치를 계산하여 업데이트
                    nextReplace = (nextReplace + 1) % frameCount;
                    // 폴트 수를 증가시킴
                    faultCnt++;
                }

                // 작업 유형이 읽기인 경우
                if (operation == 'R') {
                    // 읽기 수를 증가시킴
                    readCnt++;
                }
                // 작업 유형이 쓰기인 경우
                else {
                    // 쓰기 수를 증가시킴
                    writeCnt++;
                }
            }

            // 동적으로 할당된 프레임 배열의 메모리를 해제
            free(frames);
            break;
        }
        
        case 'n': // NRU 알고리즘인 경우
        {
            // 프레임 배열을 동적으로 할당
            int *frames = (int *)malloc(frameCount * sizeof(int));
            // 참조 비트 배열을 0으로 초기화하여 동적으로 할당
            int *reference = (int *)calloc(frameCount, sizeof(int));
            // 수정 비트 배열을 0으로 초기화하여 동적으로 할당
            int *modify = (int *)calloc(frameCount, sizeof(int));
            // 시간 배열을 0으로 초기화하여 동적으로 할당
            int *time = (int *)calloc(frameCount, sizeof(int));
            // 현재 시간을 0으로 초기화
            int currentTime = 0;
            // 프레임 배열을 -1로 초기화하여 비어있는 상태로 설정
            memset(frames, -1, frameCount * sizeof(int));

            // 총 접근 수만큼 순회하며 페이지를 처리함
            for (int i = 0; i < totalAccess; i++) {
                // 현재 접근하는 페이지 번호를 가져옴
                int page = pageNumbers[i];
                // 현재 접근하는 작업 유형을 가져옴
                char operation = operations[i];
                // 현재 시간을 증가시킴
                currentTime++;
                // 히트 여부를 0으로 초기화
                int hit = 0;
                // 교체할 인덱스를 -1로 초기화
                int replaceIndex = -1;

                // 프레임 배열에서 현재 페이지를 검색
                for (int j = 0; j < frameCount; j++) {
                    // 현재 페이지가 프레임에 존재하는 경우
                    if (frames[j] == page) {
                        // 참조 비트를 1로 설정
                        reference[j] = 1;
                        // 작업 유형이 쓰기인 경우
                        if (operation == 'W') {
                            // 수정 비트를 1로 설정
                            modify[j] = 1;
                        }
                        // 현재 시간을 저장
                        time[j] = currentTime;
                        // 히트 발생
                        hit = 1;
                        // 히트 수를 증가시킴
                        hitCnt++;
                        // 교체 인덱스를 현재 인덱스로 설정
                        replaceIndex = j;
                        // 검색을 중단함
                        break;
                    }
                }

                // 히트가 발생하지 않은 경우
                if (!hit) {
                    // 최소 클래스를 4로 초기화
                    int minClass = 4;

                    // 최소 클래스를 찾기 위해 프레임 배열을 순회
                    for (int j = 0; j < frameCount; j++) {
                        // 현재 클래스 계산 (참조 비트와 수정 비트를 조합)
                        int class = reference[j] * 2 + modify[j];
                        // 현재 클래스가 최소 클래스보다 작은 경우
                        if (class < minClass) {
                            // 최소 클래스를 현재 클래스로 업데이트
                            minClass = class;
                            // 교체 인덱스를 현재 인덱스로 업데이트
                            replaceIndex = j;
                        }
                        // 현재 클래스가 최소 클래스와 같고 시간이 더 작은 경우
                        else if (class == minClass && time[j] < time[replaceIndex]) {
                            // 교체 인덱스를 현재 인덱스로 업데이트
                            replaceIndex = j;
                        }
                    }

                    // 선택된 교체 인덱스에 현재 페이지를 저장
                    frames[replaceIndex] = page;
                    // 참조 비트를 초기화 (0으로 설정)
                    reference[replaceIndex] = 0;
                    // 수정 비트를 작업 유형에 따라 초기화
                    modify[replaceIndex] = (operation == 'W') ? 1 : 0;
                    // 현재 시간을 저장
                    time[replaceIndex] = currentTime;
                    // 폴트 수를 증가시킴
                    faultCnt++;
                }

                // 작업 유형이 읽기인 경우
                if (operation == 'R') {
                    // 읽기 수를 증가시킴
                    readCnt++;
                }
                // 작업 유형이 쓰기인 경우
                else {
                    // 쓰기 수를 증가시킴
                    writeCnt++;
                }
            }

            // 동적으로 할당된 프레임 배열의 메모리를 해제
            free(frames);
            // 동적으로 할당된 참조 비트 배열의 메모리를 해제
            free(reference);
            // 동적으로 할당된 수정 비트 배열의 메모리를 해제
            free(modify);
            // 동적으로 할당된 시간 배열의 메모리를 해제
            free(time);
            break;
        }

        default: // 알고리즘이 정의되지 않은 경우
            // 오류 메시지를 출력
            printf("Undefined algorithm: %s\n", algorithm);
            // 프로그램을 종료
            return 0;
    }

    // 총 접근 수를 출력
    printf("Total number of access: %d\n", totalAccess);
    // 읽기 작업 수를 출력
    printf("Total number of read: %d\n", readCnt);
    // 쓰기 작업 수를 출력
    printf("Total number of write: %d\n", writeCnt);
    // 페이지 히트 수를 출력
    printf("Number of page hits: %d\n", hitCnt);
    // 페이지 폴트 수를 출력
    printf("Number of page faults: %d\n", faultCnt);
    // 페이지 폴트 비율을 출력
    printf("Page fault rate: %d/%d = %.2f%%\n", faultCnt, totalAccess, (double)faultCnt / totalAccess * 100);

    // 프로그램을 종료
    return 0;
}