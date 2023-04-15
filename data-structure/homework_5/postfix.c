/* postfix.c
 *
 *  Data Structures, Homework #5
 *  School of Computer Science at Chungbuk National University
 */

#include <stdio.h> // 표준 입출력 함수(printf, scanf) 사용을 위한 라이브러리 추가
#include <stdlib.h>
#include <string.h> // strncat, strncpy 함수 사용을 위한 라이브러리 추가

#define MAX_STACK_SIZE 10 // 스택의 크기 정의
#define MAX_EXPRESSION_SIZE 20 // 입력될 수식의 최대 길이 정의

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum {
    lparen = 0, /* ( 왼쪽 괄호 */
    rparen = 9, /* ) 오른쪽 괄호*/
    times = 7,  /* * 곱셈 */
    divide = 6, /* / 나눗셈 */
    plus = 5,   /* + 덧셈 */
    minus = 4,  /* - 뺄셈 */
    operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   /* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE]; /* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];    /* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];        /* 계산을 위해 필요한 스택 */

int postfixStackTop = -1; /* postfixStack용 top */
int evalStackTop = -1;    /* evalStack용 top */

int evalResult = 0; /* 계산 결과를 저장 */

// 스택 응용 계산기 프로그램 기능 구현에 대한 함수 프로토타입 선언
void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char *c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main() {
    char command;

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    // 명령어를 입력받아 그에 맞는 기능을 수행하는 do-while문
    do {
        printf("----------------------------------------------------------------\n");
        printf("               Infix to Postfix, then Evaluation               \n");
        printf("----------------------------------------------------------------\n");
        printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        // 입력된 명령어에 따라 해당 기능 수행
        switch (command) {
        case 'i':
        case 'I':
            getInfix(); // 중위 표기식 입력
            break;
        case 'p':
        case 'P':
            toPostfix(); // 중위 표기식을 후위 표기식으로 변환
            break;
        case 'e':
        case 'E':
            evaluation(); // 후위 표기식으로 표현된 수식을 계산
            break;
        case 'd':
        case 'D':
            debug(); // 디버깅 데이터들을 출력
            break;
        case 'r':
        case 'R':
            reset(); // 스택 초기화
            break;
        case 'q':
        case 'Q':
            break; // 프로그램을 종료
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

// postfixStack에 입렫받은 문자 데이터를 추가하는 함수
void postfixPush(char x) {
    postfixStack[++postfixStackTop] = x;
}

// postfixStack에서 문자를 제거하여 반환하는 함수
char postfixPop() {
    char x;
    if (postfixStackTop == -1)
        return '\0';
    else
    {
        x = postfixStack[postfixStackTop--];
    }
    return x;
}

// evalStack에 정수 데이터를 추가하는 함수
void evalPush(int x) {
    evalStack[++evalStackTop] = x;
}

// evalStack에서 정수 데이터를 제거한 후 반환하는 함수
int evalPop() {
    if (evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix() {
    printf("Type the expression >>> ");
    scanf("%s", infixExp);
}

// symbol에 해당되는 precedence 값을 반환하는 함수
precedence getToken(char symbol) {
    switch (symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '/':
        return divide;
    case '*':
        return times;
    default:
        return operand;
    }
}

// 문자의 우선순위 값을 반환하는 함수
precedence getPriority(char x) {
    return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char *c) {
    if (postfixExp == '\0')
        strncpy(postfixExp, c, 1);
    else
        strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix() {
    /* infixExp의 문자 하나씩을 읽기위한 포인터 */
    char *exp = infixExp;
    char x; /* 문자하나를 임시로 저장하기 위한 변수 */

    /* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
    while (*exp != '\0') {
        /* 필요한 로직 완성 */
        x = *exp;
        precedence token = getToken(x);
        if (token == operand)
        {
            charCat(exp);
        }
        else if (token == rparen)
        {
            while (postfixStack[postfixStackTop] != '(')
            {
                char c = postfixPop();
                charCat(&c);
            }
            postfixPop(); // 왼쪽 괄호 '('를 스택에서 제거
        }
        else
        {
            if (token != lparen)
            {
                while (postfixStackTop != -1 && getPriority(postfixStack[postfixStackTop]) >= token)
                {
                    char c = postfixPop();
                    charCat(&c);
                }
            }
            postfixPush(x);
        }
        exp++;
    }

    // 스택에 남아있는 연산자들을 모두 postfixExp에 추가
    while (postfixStackTop != -1) {
        char c = postfixPop();
        charCat(&c);
    }
}

// 현재 스택에 저장된 데이터들의 상태를 출력하는 함수
void debug() {
    printf("\n---DEBUG\n");
    // 입력된 중위 표기식을 출력
    printf("infixExp =  %s\n", infixExp);
    // 변환된 후위 표기식을 출력
    printf("postExp =  %s\n", postfixExp);
    // 계산 결과값을 출력
    printf("eval result = %d\n", evalResult);

    printf("postfixStack : ");
    for (int i = 0; i < MAX_STACK_SIZE; i++)
        printf("%c  ", postfixStack[i]);

    printf("\n");
}

// 모든 변수와 스택 배열을 초기화하는 함수
void reset() {
    infixExp[0] = '\0';
    postfixExp[0] = '\0';

    for (int i = 0; i < MAX_STACK_SIZE; i++)
        postfixStack[i] = '\0';

    postfixStackTop = -1;
    evalStackTop = -1;
    evalResult = 0;
}

// 후위 표기식을 계산하는 함수
void evaluation() {
    /* postfixExp, evalStack을 이용한 계산 */
    char *exp = postfixExp;
    int op1, op2;
    int value;
    precedence token;

    while (*exp != '\0') {
        token = getToken(*exp);
        if (token == operand)
        {
            value = *exp - '0'; // 문자를 숫자로 변환
            evalPush(value);
        }
        else
        {
            op2 = evalPop();
            op1 = evalPop();
            switch (token)
            {
            case plus:
                evalPush(op1 + op2);
                break;
            case minus:
                evalPush(op1 - op2);
                break;
            case times:
                evalPush(op1 * op2);
                break;
            case divide:
                evalPush(op1 / op2);
                break;
            }
        }
        exp++;
    }
    // 최종적으로 계산된 결괏값을 evalResult에 저장
    evalResult = evalPop();
}