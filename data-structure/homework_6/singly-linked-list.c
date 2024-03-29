/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science
 *  at Chungbuk National University
 */

/* 필요한 헤더파일 추가 */
#include <stdio.h>
#include <stdlib.h>

// 연결리스트에서 사용될 노드 구조체 정의
typedef struct Node {
  int key; // 노드에 저장될 정수 값
  struct Node *link; // 다음 노드를 가리키는 포인터
} listNode;

// 헤드(시작 노드를 가리키는) 노드 구조체 정의
typedef struct Head {
  // 연결 리스트의 첫 번째 노드를 가리키는 포인터
  struct Node *first;
} headNode;

/* 연결 리스트 조작 관련 함수 원형 선언 */
headNode *initialize(headNode *h);
int freeList(headNode *h);

int insertFirst(headNode *h, int key);
int insertNode(headNode *h, int key);
int insertLast(headNode *h, int key);

int deleteFirst(headNode *h);
int deleteNode(headNode *h, int key);
int deleteLast(headNode *h);
int invertList(headNode *h);

void printList(headNode *h);

int main() {
  char command; // 명령어 값 저장 변수 선언
  int key; // 연결리스트의 각 노드에 저장될 key값 변수 선언
  headNode *headnode = NULL; // 연결 리스트의 헤드 노드로 사용될 포인터 변수 선언

  // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
	printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

  do {
    printf(
        "----------------------------------------------------------------\n");
    printf(
        "                     Singly Linked List                         \n");
    printf(
        "----------------------------------------------------------------\n");
    printf(" Initialize    = z           Print         = p \n");
    printf(" Insert Node   = i           Delete Node   = d \n");
    printf(" Insert Last   = n           Delete Last   = e\n");
    printf(" Insert First  = f           Delete First  = t\n");
    printf(" Invert List   = r           Quit          = q\n");
    printf(
        "----------------------------------------------------------------\n");

	// 명령어 입력
    printf("Command = ");
    scanf(" %c", &command);

	// 명령어에 따라 특정 코드 수행
    switch (command) {
    case 'z':
    case 'Z':
      headnode = initialize(headnode);
      break;
    case 'p':
    case 'P':
      printList(headnode);
      break;
    case 'i':
    case 'I':
      printf("Your Key = ");
      scanf("%d", &key);
      insertNode(headnode, key);
      break;
    case 'd':
    case 'D':
      printf("Your Key = ");
      scanf("%d", &key);
      deleteNode(headnode, key);
      break;
    case 'n':
    case 'N':
      printf("Your Key = ");
      scanf("%d", &key);
      insertLast(headnode, key);
      break;
    case 'e':
    case 'E':
      deleteLast(headnode);
      break;
    case 'f':
    case 'F':
      printf("Your Key = ");
      scanf("%d", &key);
      insertFirst(headnode, key);
      break;
    case 't':
    case 'T':
      deleteFirst(headnode);
      break;
    case 'r':
    case 'R':
      invertList(headnode);
      break;
    case 'q':
    case 'Q':
      freeList(headnode);
      break;
    default:
      printf("\n       >>>>>   Concentration!!   <<<<<     \n");
      break;
    }

  } while (command != 'q' && command != 'Q');

  return 1;
}

// 연결 리스트 초기화 함수 정의
headNode *initialize(headNode *h) {

  /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
  if (h != NULL)
    freeList(h);

  /* headNode에 대한 메모리를 할당하여 리턴 */
  headNode *temp = (headNode *)malloc(sizeof(headNode));
  temp->first = NULL;
  return temp;
}

// 연결 리스트 동적할당 해제 함수 정의
int freeList(headNode *h) {
  /* h와 연결된 listNode 메모리 해제
   * headNode도 해제되어야 함.
   */
  listNode *p = h->first;

  listNode *prev = NULL;
  while (p != NULL) {
    prev = p;
    p = p->link;
    free(prev);
  }
  free(h);
  return 0;
}

/**
 * list 처음에 key에 대한 노드 하나를 추가
 */
int insertFirst(headNode *h, int key) {
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key;

  node->link = h->first;
  h->first = node;

  return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode *h, int key) {
  listNode *p = h->first;
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key;
  node->link = NULL;

  // 리스트가 비어있는 조건
  if (p == NULL) {
    h->first = node;
    return 0;
  }

  // key가 첫번째 노드보다 작은 조건
  if (p->key > key) {
    node->link = p;
    h->first = node;
    return 0;
  }

  // 중간에 삽입하는 단계
  while (p->link != NULL && p->link->key <= key) {
    p = p->link;
  }
  node->link = p->link;
  p->link = node;

  return 0;
}

/**
 * list 마지막에 key에 대한 노드 하나를 추가
 */
int insertLast(headNode *h, int key) {
  listNode *p = h->first;
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key;
  node->link = NULL;

  // 리스트가 비어있는 조건
  if (p == NULL) {
    h->first = node;
    return 0;
  }

  while (p->link != NULL) {
    p = p->link;
  }

  p->link = node;

  return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode *h) {
  listNode *p = h->first;

  if (p == NULL) {
    free(p);
    printf("Nothing to delete....\n");
    return 0;
  }

  h->first = p->link;
  free(p);

  return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode *h, int key) {
  listNode *p = h->first;
  listNode *prev = NULL;

  // 리스트가 비어있는 조건
  if (p == NULL) {
    free(p);
    printf("Nothing to delete....\n");
    return 0;
  }

  while (p != NULL && p->key != key) {
    prev = p;
    p = p->link;
  }

  // key를 찾지 못 한 조건
  if (p == NULL) {
    printf("Cannot found the key....\n");
    free(p);
    return 0;
  }

  // 첫 번째 노드를 삭제하는 조건
  if (prev == NULL) {
    h->first = p->link;
    free(p);
    return 0;
  }

  // 중간에 있는 노드를 삭제하는 단계
  prev->link = p->link;
  free(p);

  return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode *h) {
  listNode *p = h->first;
  listNode *prev = NULL;

  // 리스트가 비어있는 조건
  if (p == NULL) {
    free(p);
    printf("Nothing to delete....\n");
    return 0;
  }

  if (p->link == NULL) {
    free(p);
    h->first = NULL;
    return 0;
  }

  while (p->link != NULL) {
    prev = p;
    p = p->link;
  }
  prev->link = NULL;
  free(p);

  return 0;
}

/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode *h) {
  listNode *prev = NULL;
  listNode *current = h->first;
  listNode *next = NULL;

  while (current != NULL) {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  h->first = prev;

  return 0;
}

// 연결 리스트의 현재 정보를 출력하는 함수 정의
void printList(headNode *h) {
  int i = 0;
  listNode *p;

  printf("\n---PRINT\n");

  if (h == NULL) {
    printf("Nothing to print....\n");
    return;
  }

  p = h->first;

  while (p != NULL) {
    printf("[ [%d]=%d ] ", i, p->key);
    p = p->link;
    i++;
  }

  printf("  items = %d\n", i);
}
