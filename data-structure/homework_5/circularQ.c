/* circularQ.c
 *
 *  Data Structures, Homework #5
 *  School of Computer Science at Chungbuk National University
 */

#include <stdio.h> // 표준 입출력 함수(printf, scanf) 사용을 위한 라이브러리 추가
#include <stdlib.h> // 메모리 동적할당 malloc 함수 사용을 위한 라이브러리 추가

// 원형 큐의 크기를 4로 정의
#define MAX_QUEUE_SIZE 4 

// 큐의 원소들을 char형 대신 element라는 데이터형으로 치환
typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE]; // 큐의 원소들을 저장하는 배열 선언
	int front, rear;  // 큐의 맨 앞과 뒤의 인덱스 값을 저장하는 정수형 변수 선언
} QueueType;

// 원형 큐 기능 구현에 대한 함수 프로토타입 선언
QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element *item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void) {
	QueueType *cQ = createQueue();  // 원형 큐의 생성 및 초기화 수행
	element data; // 큐에 추가할 데이터를 저장하는 용도로 사용될 element형 변수 선언
	char command; // 명령어를 저장하는 용도로 사용될 문자형 변수 선언

	// [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
	printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

	do {
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // 명령을 입력 받음

		switch (command) {
		case 'i':
		case 'I':
			// 원소 입력 및 저장
			data = getElement();
			 // 큐에 입력받았던 원소를 추가
			enQueue(cQ, data);
			break;
		case 'd':
		case 'D':
			// 큐에서 원소를 삭제하고 data 변수에 저장
			deQueue(cQ, &data);
			break;
		case 'p':
		case 'P':
			// 큐에 저장된 모든 원소들을 출력
			printQ(cQ);
			break;
		case 'b':
		case 'B':
			// 큐에 대하여 디버그된 데이터들을 출력
			debugQ(cQ);
			break;
		case 'q':
		case 'Q':
			// 큐를 초기화
			freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q'); // q 또는 Q가 입력될 때까지 while문 반복

	return 1; // 1을 반환함으로써 프로그램을 종료
}

// 원형 큐 생성 및 초기화 수행 함수 정의
QueueType *createQueue() {
	QueueType *cQ;  // 원형 큐에 대한 포인터 변수 선언
	// 원형 큐 크기에 맞는 동적 메모리 할당 수행
	cQ = (QueueType *)malloc(sizeof(QueueType));
	// 큐의 front 인덱스 데이터를 0으로 초기화
	cQ->front = 0;
	// 큐의 rear 인덱스 데이터를 0으로 초기화
	cQ->rear = 0;
	// 생성 및 초기화 작업이 완료된 원형 큐의 주소를 반환
	return cQ;
}

// 원형 큐의 동적 메모리 할당 해제 기능 수행 함수
int freeQueue(QueueType *cQ) {
	// 큐가 존재하지 않으면 동적 메모리 할당 해제 수행 없이 함수 종료
	if (cQ == NULL)
		return 1;
	free(cQ); // 원형 큐 동적 메모리 할당 해제
	return 1; // 함수 종료
}

// 큐에 저장될 원소를 입력 받는 함수
element getElement() {
	element item;
	printf("Input element = ");
	scanf(" %c", &item);  // 원소를 입력 받음
	return item; // 입력받은 원소 데이터를 반환
}

// 원형 큐가 비어있는지 확인하는 함수
/* complete the function */
int isEmpty(QueueType *cQ) {
	// front와 rear가 같다면, 큐가 비어있음을 의미함
	if (cQ->front == cQ->rear)
		return 1; // 큐가 비어있음을 의미
	else
		return 0; // 큐가 비어있지 않음을 의미
}

// 원형 큐가 가득 차 있는지 확인하는 함수
/* complete the function */
int isFull(QueueType *cQ) {
	// rear+1의 값이 front와 같으면 큐가 가득 참 있음을 의미함
	if ((cQ->rear + 1) % MAX_QUEUE_SIZE == cQ->front)
		return 1; // 큐가 가득 참 있음을 의미
	else
		return 0; // 가득 차지 않음을 의미
}

// 원형 큐에 원소를 추가하는 함수
/* complete the function */
void enQueue(QueueType *cQ, element item) {
	if (isFull(cQ)) {  // 큐에 데이터 추가 전, 해당 큐가 현재 가득 차 있는지 확인
		printf("Can not enqueue, queue is full now.\n");
		return;
	}
	// rear+1한 값을 원형 큐의 크기로 나눈 나머지의 값을 토대로 rear값을 갱신
	cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
	cQ->queue[cQ->rear] = item; // 증가된 rear 위치에 원소를 저장
}

// 원형 큐에서 원소를 삭제하고 반환하는 함수
/* complete the function */
void deQueue(QueueType *cQ, char *item) {
	if (isEmpty(cQ)) {  // 큐에서 데이터 제거 전, 해당 큐가 현재 비어 있는지 확인
		printf("Can not dequeue, queue is empty now.\n");
		return;
	}
	 // front+1한 값을 원형 큐의 크기로 나눈 나머지의 값을 토대로 front값을 갱신
	cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
	// 증가된 front 인덱스에 위치한 큐의 원소를 item 변수에 저장
	*item = cQ->queue[cQ->front];
}

// 원형 큐의 내용을 출력하는 함수
void printQ(QueueType *cQ) {
	int i, first, last;

	// 원형 큐에서 출력될 첫 번째 원소의 인덱스 값을 계산
	first = (cQ->front + 1) % MAX_QUEUE_SIZE;
	// 마지막에 출력될 원소의 인덱스 값을 계산
	last = (cQ->rear + 1) % MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while (i != last) { // 큐의 첫 번째 원소부터 마지막 원소까지 반복
		printf("%3c", cQ->queue[i]); // 큐의 각 원소들을 출력
		// 다음 원소의 인덱스 값을 계산하고 배열의 끝에 도달했을 때 인덱스 값을 처음으로 되돌림
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
	printf(" ]\n");
}

// 원형 큐의 디버그 데이터들을 출력하는 함수
void debugQ(QueueType *cQ) {
	printf("\n---DEBUG\n");
	// 원형 큐 배열의 사이즈 만큼 반복
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i == cQ->front) { // 인덱스 값이 큐의 front 인덱스 값과 같은 경우
			printf("  [%d] = front\n", i); // front 인덱스 값을 출력
			continue;
		}
		// 인덱스 값과 해당 인덱스 위치의 큐 원소를 출력
		printf("  [%d] = %c\n", i, cQ->queue[i]);
	}
	// front와 rear 인덱스 값을 함께 출력
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}