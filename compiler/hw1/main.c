#include <stdio.h>

#define MAX 100

int action_tb[12][6] = {
    { 5, 0, 0, 4, 0, 0 },
    { 0, 6, 0, 0, 0, 999 },
    { 0, -2, 7, 0, -2, -2 },
    { 0, -4, -4, 0, -4, -4 },
    { 5, 0, 0, 4, 0, 0 },
    { 0, -6, -6, 0, -6, -6 },
    { 5, 0, 0, 4, 0, 0 },
    { 5, 0, 0, 4, 0, 0 },
    { 0, 6, 0, 0, 11, 0 },
    { 0, -1, 7, 0, -1, -1 },
    { 0, -3, -3, 0, -3, -3 },
    { 0, -5, -5, 0, -5, -5 }
};

int goto_tb[12][4] = {
    { 0, 1, 2, 3 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 8, 2, 3 },
    { 0, 0, 0, 0 },
    { 0, 0, 9, 3 },
    { 0, 0, 0, 10},
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
};

char lhs[] = { ' ', 'E', 'E', 'T', 'T', 'F', 'F' }; // dummy in 0 idx
char rhs_len[] = { 0, 3, 1, 3, 1, 3, 1 }; // rhs length: 0 for dummy rule

char token[] = { 'd', '+', '*', '(', ')', '$' };
char NT[] = { ' ', 'E', 'T', 'F' }; // non-terminals: dummy in 0 idx
int stack[MAX], sp;

// 주어진 토큰 배열에서 대상 문자의 인덱스를 찾는 함수
int findActionTableColumnIdx(char token[], char target) {
    int index = -1;
    int i = 0;

    // 토큰 배열을 순회하면서 대상 문자를 탐색
    while (token[i] != '\0') {
        if (token[i] == target) {
            index = i;
            break;
        }
        i++;
    }
    return index; // 찾은 대상 문자의 인덱스를 반환
}

// 주어진 논-터미널 배열에서 대상 문자의 인덱스를 찾는 함수
int findGotoTableColumnIdx(char NT[], char target) {
    int index = -1;
    int i = 0;

    // 논-터미널 배열을 순회하면서 대상 문자를 탐색
    while (NT[i] != '\0') {
        if (NT[i] == target) {
            index = i;
            break;
        }
        i++;
    }
    return index; // 찾은 대상 문자의 인덱스를 반환
}

// LR 파싱을 수행하는 함수
void LR_Parser(char *input) {
    // 스택을 초기화
    for (int k=0; k < MAX; k++) stack[k] = 0;
    // 입력 문자열의 시작 인덱스, GoTo 테이블에서의 열 인덱스, 스택 포인터를 선언
    int inputStartIdx = 0, gotoTableColumnIdx, sp = 0;
    printf("(1) %-8s:\t0\t%s\n", "initial", input); // 초기 상태 출력
    
    // 파싱 단계의 표현을 위한 무한 루프 수행
    for (int k=2;; k++) {
        // 입력 토큰에 대한 액션 테이블의 열 인덱스 탐색
        int actionTableColumnIdx = findActionTableColumnIdx(token, input[inputStartIdx]);
        // 스택의 상태와 입력 토큰에 대한 액션 확인
        int action = action_tb[stack[sp]][actionTableColumnIdx];
        
        // 무한루프 탈출 조건(파싱의 accept 조건)
        if (action_tb[stack[sp]][actionTableColumnIdx] == 999) {
            printf("(%d) %-7s\n", k, "accept");
            break;
        }
        
        // Shift 액션인 경우
        if (action > 0) {
            // Shift 동작 출력
            printf("(%d) %-7s%d:\t0", k, "shift", action);
            
            // 스택 내용 출력
            for (int z=1; stack[z] != 0; z++) {
                if (stack[z] > 12) {
                    printf("%c", stack[z]);
                    continue;
                }
                printf("%d", stack[z]);
            }
            
            // 입력 문자를 스택에 PUSH
            stack[++sp] = input[inputStartIdx];
            // 액션을 스택에 PUSH
            stack[++sp] = action;
            // PUSH 한 문자와 액션을 출력
            printf("%c%d\t", input[inputStartIdx++], action);
        } else if (action < 0) { // Reduce 액션인 경우
            switch (action) {
                case -1: // 문법 규칙(1) : E -> E + T
                case -3: // 문법 규칙(3): T -> T * F
                    // 스택에서 규칙에 맞는 항목을 제거
                    for (int z=0; z < rhs_len[-action] * 2 - 1; z++)
                        stack[sp--] = 0;
                    // GoTo 테이블을 참조하여 스택에 새로운 상태를 추가
                    gotoTableColumnIdx = findGotoTableColumnIdx(NT, stack[sp]);
                    stack[++sp] = goto_tb[stack[sp-1]][gotoTableColumnIdx];
                    
                    // Reduce 동작을 출력
                    printf("(%d) %-7s%d:\t0", k, "reduce", -action);
                    
                    // 스택 내용 출력
                    for (int z=1; stack[z] != 0; z++) {
                        if (stack[z] > 12) {
                            printf("%c", stack[z]);
                            continue;
                        }
                        printf("%d", stack[z]);
                    }
                    printf("\t");
                    break;
                case -2: // 문법 규칙(2) : E -> T
                    // 스택에서 규칙에 맞게 항목을 제거하고 새로운 항목을 추가
                    for (int z=1; stack[z] != 0; z++)
                        if (stack[z] == 'T') {
                            stack[z] = lhs[-action];
                            gotoTableColumnIdx = findGotoTableColumnIdx(NT, stack[z]);
                            stack[z+1] = goto_tb[stack[z-1]][gotoTableColumnIdx];                            
                        }
                        
                    // Reduce 동작을 출력
                    printf("(%d) %-7s%d:\t0", k, "reduce", -action);
                    
                    // 스택 내용 출력
                    for (int z=1; stack[z] != 0; z++) {
                        if (stack[z] > 12) {
                            printf("%c", stack[z]);
                            continue;
                        }
                        printf("%d", stack[z]);
                    }
                    printf("\t");
                    break;
                case -4: // 문법 규칙(4) : T -> F
                    // 스택에서 규칙에 맞게 항목을 제거하고 새로운 항목을 추가
                    for (int z=1; stack[z] != 0; z++)
                        if (stack[z] == 'F') {
                            stack[z] = lhs[-action];
                            gotoTableColumnIdx = findGotoTableColumnIdx(NT, stack[z]);
                            stack[z+1] = goto_tb[stack[z-1]][gotoTableColumnIdx];         
                        }
                        
                    // Reduce 동작을 출력
                    printf("(%d) %-7s%d:\t0", k, "reduce", -action);
                    
                    // 스택 내용 출력
                    for (int z=1; stack[z] != 0; z++) {
                        if (stack[z] > 12) {
                            printf("%c", stack[z]);
                            continue;
                        }
                        printf("%d", stack[z]);
                    }
                    printf("\t");
                    break;
                case -5: // 문법 규칙(5) : F -> (E)
                    // 스택에서 규칙에 맞게 항목을 제거하고 새로운 항목을 추가
                    for (int z=0; z < rhs_len[-action]; z++)
                        stack[sp--] = 0;
                    stack[sp] = lhs[-action];
                    gotoTableColumnIdx = findGotoTableColumnIdx(NT, stack[sp]);
                    stack[++sp] = goto_tb[stack[sp-1]][gotoTableColumnIdx];
                    
                    // Reduce 동작을 출력
                    printf("(%d) %-7s%d:\t0", k, "reduce", -action);
                    
                    // 스택 내용 출력
                    for (int z=1; stack[z] != 0; z++) {
                        if (stack[z] > 12) {
                            printf("%c", stack[z]);
                            continue;
                        }
                        printf("%d", stack[z]);
                    }
                    printf("\t");
                    break;
                case -6: // 문법 규칙(6) : F -> id
                    // 스택에서 규칙에 맞게 항목을 제거하고 새로운 항목을 추가
                    for (int z=1; stack[z] != 0; z++)
                        if (stack[z] == 'd') {
                            stack[z] = lhs[-action];
                            gotoTableColumnIdx = findGotoTableColumnIdx(NT, stack[z]);
                            stack[z+1] = goto_tb[stack[z-1]][gotoTableColumnIdx];
                        }
                        
                    // Reduce 동작을 출력
                    printf("(%d) %-7s%d:\t0", k, "reduce", -action);
                    
                    // 스택 내용 출력
                    for (int z=1; stack[z] != 0; z++) {
                        if (stack[z] > 12) {
                            printf("%c", stack[z]);
                            continue;
                        }
                        printf("%d", stack[z]);
                    }
                    printf("\t");
            }
        } else { // 에러 발생한 경우
            if (actionTableColumnIdx == -1) {  // 액션 테이블에서 찾지 못한 경우
                // 잘못된 토큰 에러를 출력
                printf("(%d) invalid token (%c) error\n", k, input[inputStartIdx]);    
                break; // 루프 종료
            }
            
            // 그 외의 경우에는 일반 에러를 출력
            printf("(%d) %-7s\n", k, "error");
                inputStartIdx++;
            break; // 루프 종료
        }
        
        // 나머지 입력 문자열을 출력
        for (int z=inputStartIdx; input[z] != '\0'; z++)
            printf("%c", input[z]);
        printf("\n");
    }
}

int main() {
    char input[MAX];
    while (1) {
        printf("\nInput: ");
        scanf("%s", input);
        if (input[0] == '$') break;
        LR_Parser(input);
    }
}