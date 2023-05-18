/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  School of Computer Science
 *  at Chungbuk National University
 *
 */

#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가
#include <stdlib.h> // 메모리 동적할당 malloc 함수 사용을 위한 라이브러리 추가
/* 필요한 헤더파일 추가 */

typedef struct Node {
  int key; // 노드의 데이터(key) 값을 저장하는 정수형 변수 선언
     // 노드의 좌측 링크에 대한 주솟값을 저장하는 구조체 포인터 변수 선언
  struct Node *llink;
  // 노드의 우측 링크에 대한 주솟값을 저장하는 구조체 포인터 변수 선언
  struct Node *rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode **h); // 이중 원형 연결 리스트 생성 함수 원형
int freeList(listNode *h); // 이중 원형 연결 리스트 초기화 함수 원형
int insertLast(listNode *h, int key); // 리스트의 마지막 위치에 신규 노드 추가 함수 원형
int deleteLast(listNode *h); // 리스트의 마지막 위치의 노드 제거 함수 원형
int insertFirst(listNode *h, int key); // 리스트의 첫 번째 위치에 신규 노드 추가 함수 원형
int deleteFirst(listNode *h); // 리스트의 첫 번째 위치의 노드 제거 함수 원형
int invertList(listNode *h); // 이중 원형 연결 리스트의 link를 역으로 설정하는 함수 원형

// 리스트 내 key값을 크기 순으로 비교 후 신규 노드를 추가하는 함수 원형
int insertNode(listNode *h, int key);
// 리스트 내 주어진 key값이 존재하는 노드를 탐색 후 제거하는 함수 원형
int deleteNode(listNode *h, int key);

// 리스트 내에 링킹되어 있는 모든 노드들의 key값을 순차적으로 출력하는 함수 원형
void printList(listNode *h);

// main 함수 정의
int main() {
  // 사용자의 입력 명령을 저장하기 위한 문자형 변수 선언
  char command;
  int key; // 리스트에 대한 노드 조작 시 key값을 저장할 정수형 변수 선언
  // 이중 원형 연결 리스트의 headNode로 사용될 구조체 포인터 변수 선언
  listNode *headnode = NULL;

  // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

  do {
    printf(
        "----------------------------------------------------------------\n");
    printf(
        "                  Doubly Circular Linked List                   \n");
    printf(
        "----------------------------------------------------------------\n");
    printf(" Initialize    = z           Print         = p \n");
    printf(" Insert Node   = i           Delete Node   = d \n");
    printf(" Insert Last   = n           Delete Last   = e\n");
    printf(" Insert First  = f           Delete First  = t\n");
    printf(" Invert List   = r           Quit          = q\n");
    printf(
        "----------------------------------------------------------------\n");

    printf("Command = ");
    scanf(" %c", &command);

    switch (command) {
	// z(Z)입력 시 initialize함수를 호출하여 이중 원형 연결 리스트를 초기화 및 생성한다.
    case 'z':
    case 'Z':
      initialize(&headnode);
      break;
	/*  p(P)입력 시 printList함수를 호출하여 이중 원형 연결 리스트 내에
        저장된 모든 노드들의 key값을 차례대로 출력한다. */
    case 'p':
    case 'P':
      printList(headnode);
      break;
	/*  i(I)입력 시 신규 노드에 대한 key값을 입력받고 insertNode함수를 호출하여 연결 리스트
        내에 추가되어 있던 기존 노드들의 key값이 새로 입력받은 key값보다 큰 노드 위치의 좌측
        link에 신규 노드를 추가한다. */
    case 'i':
    case 'I':
      printf("Your Key = ");
      scanf("%d", &key);
      insertNode(headnode, key);
      break;
	/*  d(D)입력 시 삭제할 노드에 대한 key값을 입력받고, deleteNode함수를 호출하여 연결 리스트
        내에서 삭제할 노드가 지니고 있는 key값의 위치에 도달하여 해당 노드와 링킹되어 있는 노드들의
        정보를 변경하고 대상 노드를 제거한다. */
    case 'd':
    case 'D':
      printf("Your Key = ");
      scanf("%d", &key);
      deleteNode(headnode, key);
      break;
	/*  n(N)입력 시 신규 노드에 대한 key값을 입력받고, insertLast함수를 호출하여 연결 리스트의
        마지막 노드에 신규 노드를 추가한다. */
    case 'n':
    case 'N':
      printf("Your Key = ");
      scanf("%d", &key);
      insertLast(headnode, key);
      break;
	/*  e(E)입력 시 deleteLast함수를 호출하여 연결 리스트의 마지막 노드와 링킹되어 있는 연관
        노드들의 정보를 변경하고, 마지막 노드를 제거한다. */
    case 'e':
    case 'E':
      deleteLast(headnode);
      break;
    /*  f(F)입력 시 신규 노드에 대한 key값을 입력받고, insertFirst함수를 호출하여 연결 리스트의
        첫 번째 위치에 신규 노드를 추가한다. */
    case 'f':
    case 'F':
      printf("Your Key = ");
      scanf("%d", &key);
      insertFirst(headnode, key);
      break;
    /*  t(T)입력 시 deleteFirst 함수를 호출하여 연결 리스트의 첫 번째 노드와 링킹되어 있는 연관
        노드들의 정보를 변경하고, 첫 번째 노드를 제거한다. */
    case 't':
    case 'T':
      deleteFirst(headnode);
      break;
    //  r(R)입력 시 invertList함수를 호출하여 이중 원형 연결 리스트의 링크 정보들을 역으로 변경한다.
    case 'r':
    case 'R':
      invertList(headnode);
      break;
    // q(Q)입력 시 freeLis함수를 호출하여 이중 연결 리스트에 추가된 노드들의 동적 메모리에 대한 할당을 
    case 'q':
    case 'Q':
      freeList(headnode);
      break;
	// 정해진 입력 외의 명령이 확인되면 경구 문구를 출력하는 역할을 한다.
    default:
      printf("\n       >>>>>   Concentration!!   <<<<<     \n");
      break;
    }

  } while (command != 'q' && command != 'Q');
  return 1; // 프로그램 종료
}

int initialize(listNode **h) {
  /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
  if (*h != NULL)
    freeList(*h);

  /* headNode에 대한 메모리를 할당하여 리턴 */
  *h = (listNode *)malloc(sizeof(listNode));
  (*h)->rlink = *h;
  (*h)->llink = *h;
  (*h)->key = -9999;
  return 1;
}

int freeList(listNode *h) {
  // 헤드 노드의 우측 링크가 스스로를 가리키는지 비교(유일 노드 판단)
  if (h->rlink == h) {
    free(h);
    return 1;
  }

// 헤드 노드의 우측 링크를 p에 할당
  listNode *p = h->rlink;

  // 이전 노드를 NULL로 설정
  listNode *prev = NULL;
// p가 NULL이 아니고, p가 헤드 노드가 아닐 때 동안 반복
  while (p != NULL && p != h) {
    prev = p; // 현재 노드를 이전 노드로 설정
    p = p->rlink; // 현재 노드를 우측 노드로 이동
    free(prev); // 이전 노드의 동적 메모리 해제
  }
  free(h); // 헤드 노드의 동적 메모리 해제
  return 0;
}

void printList(listNode *h) {
// 노드 위치에 대한 인덱스 변수로 사용할 정수형 변수 선언
  int i = 0;
  // 현재 노드에 대한 구조체 포인터 선언
  listNode *p;

  printf("\n---PRINT\n");

  // 헤드 노드가 비어있는지 판단
  if (h == NULL) {
    printf("Nothing to print....\n");
    return; // 함수 종료
  }

  // 헤드 노드의 우측 링크를 현재 노드로 설정
  p = h->rlink;

  // p가 NULL이 아니고, p가 헤드 노드가 아닐 때 동안 반복
  while (p != NULL && p != h) {
	// 현재 노드의 위치 & key값을 출력
    printf("[ [%d]=%d ] ", i, p->key);
    p = p->rlink; // 현재 노드를 우측 노드로 이동
    i++; // 인덱스 변수 1증가
  }
  
  printf("  items = %d\n", i);

  /* print addresses */
  printf("\n---checking addresses of links\n");
  printf("-------------------------------\n");
  // 헤드 노드의 주소 및 양쪽 링크의 주소를 출력
  printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h,
         h->rlink);

  i = 0; // 인덱스 변수 초기화
  p = h->rlink; // 헤드 노드의 우측 링크를 현재 노드로 설정
  // p가 NULL이 아니고, p가 헤드 노드가 아닐 때 동안 반복
  while (p != NULL && p != h) {
	// 현재 노드의 위치 & key값, 그리고 양쪽 링크 및 현재 노드의 주소를 출력
    printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key,
           p->llink, p, p->rlink);
    p = p->rlink; // 현재 노드를 우측 노드로 이동
    i++; // 인덱스 변수 1증가
  }
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode *h, int key) {

  // 헤드 노드가 NULL이면 함수 종료
  if (h == NULL)
    return -1;

  // 신규 노드 생성 및 동적 메모리를 할당
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key; // 신규 노드에 대한 key값 설정
  // 신규 노드의 양측 링크를 NULL로 초기화
  node->rlink = NULL;
  node->llink = NULL;

  if (h->rlink == h) /* 첫 노드로 삽입 */
  {
    h->rlink = node; // 헤드 노드의 우측 링크를 신규 노드로 설정
    h->llink = node; // 헤드 노드의 좌측 링크를 신규 노드로 설정
    node->rlink = h; // 신규 노드의 우측 링크를 헤드 노드로 설정 
    node->llink = h; // 신규 노드의 좌측 링크를 헤드 노드로 설정
  } else {
	// 헤드 노드 좌측 노드의 우측 링크를 신규 노드로 설정
    h->llink->rlink = node;
	// 신규 노드의 좌측 링크를 헤드 노드의 좌측 노드로 설정
    node->llink = h->llink;
	// 헤드 노드의 좌측 링크를 신규 노드로 설정
    h->llink = node;
	// 신규 노드의 우측 링크를 헤드 노드로 설정
    node->rlink = h;
  }

  return 1;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode *h) {

  // 헤드의 좌측 링크가 헤드 노드이거나, 헤드 노드가 NULL인 경우
  if (h->llink == h || h == NULL) {
    printf("nothing to delete.\n");
    return 1; // 함수 종료
  }

  // 삭제할 노드를 변수에 할당
  listNode *nodetoremove = h->llink;

  /* link 정리 */
  nodetoremove->llink->rlink = h;
  h->llink = nodetoremove->llink;

  // 삭제할 노드의 동적 메모리 해제
  free(nodetoremove);

  return 1;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode *h, int key) {
  // 신규 노드 생성 및 동적 메모리를 할당
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key; // 신규 노드에 대한 key값 설정
  // 신규 노드의 양측 링크를 NULL로 초기화
  node->rlink = NULL;
  node->llink = NULL;

  // 신규 노드의 우측 링크를 헤드 노드의 우측 노드로 설정
  node->rlink = h->rlink;
  // 헤드 노드의 우측 링크를 신규 노드로 설정
  h->rlink->llink = node;
  // 신규 노드의 좌측 링크를 헤드 노드로 설정
  node->llink = h;
  // 헤드 노드의 우측 링크를 신규 노드로 설정
  h->rlink = node;

  return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode *h) {
  // 삭제할 노드가 없는 경우
  if (h == NULL || h->rlink == h) {
    printf("nothing to delete.\n");
    return 0;
  }

  // 삭제할 노드를 nodetoremove에 저장
  listNode *nodetoremove = h->rlink;

  /* link 정리 */
  nodetoremove->rlink->llink = h;
  h->rlink = nodetoremove->rlink;

  // nodetoremove의 동적 메모리 해제
  free(nodetoremove);

  return 1;
}

/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode *h) {
  // 리스트가 비어 있거나, 헤드 노드만 있는 경우
  if (h->rlink == h || h == NULL) {
    printf("nothing to invert...\n");
    return 0; // 함수 종료
  }
  // n을 첫 번째 노드로 설정, trail과 middle을 헤드 노드로 설정
  listNode *n = h->rlink;
  listNode *trail = h;
  listNode *middle = h;

  /* 최종 바뀔 링크 유지 */
  h->llink = h->rlink;

  // 리스트를 순회하며 각 노드의 링크를 반대로 설정
  while (n != NULL && n != h) {
    trail = middle; // trail을 middle로 이동
    middle = n; // middle을 n으로 이동
    n = n->rlink; // n을 다음 노드로 이동
    middle->rlink = trail; // middle의 오른쪽 링크를 trail로 설정
    middle->llink = n; // middle의 왼쪽 링크를 n으로 설정
  }

  // 헤드 노드의 우측 링크를 마지막 노드로 설정
  h->rlink = middle;

  return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode *h, int key) {
  // 리스트가 비어있는 경우 처리
  if (h == NULL)
    return -1;

  // 신규 노드 생성 및 동적 메모리를 할당
  listNode *node = (listNode *)malloc(sizeof(listNode));
  node->key = key; // 신규 노드에 대한 key값 설정
  // 신규 노드의 양측 링크를 NULL로 초기화
  node->llink = node->rlink = NULL;

  // 헤드 노드의 우측 링크가 스스로를 가리키는지 비교
  if (h->rlink == h) {
    insertFirst(h, key); // 첫 노드로 삽입
    return 1; // 함수 종료
  }

  // n을 첫 번째 노드로 설정
  listNode *n = h->rlink;

  /* key를 기준으로 삽입할 위치를 찾는다 */
  while (n != NULL && n != h) {
    if (n->key >= key) {
      /* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
      if (n == h->rlink) {
        insertFirst(h, key);
      } else { /* 중간이거나 마지막인 경우 */
      // 삽입할 신규 노드의 링크를 설정 후 기존 노드의 링크를 갱신
        node->rlink = n;
        node->llink = n->llink;
        n->llink->rlink = node;
        n->llink = node;
      }
      return 0;
    }

    n = n->rlink; // n을 다음 노드로 이동
  }

  /* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
  insertLast(h, key);
  return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode *h, int key) {
  // 리스트가 비어있는 경우 처리
  if (h->rlink == h || h == NULL) {
    printf("nothing to delete.\n");
    return 0; // 함수 종료
  }

  // n을 첫 번째 노드로 설정
  listNode *n = h->rlink;

  // n이 NULL이 아니고, 헤드 노드가 아닌 동안 반복
  while (n != NULL && n != h) {
    if (n->key == key) {
      if (n == h->rlink) { /* 첫 노드째 노드 인경우 */
        deleteFirst(h);
      } else if (n->rlink == h) { /* 마지막 노드인 경우 */
        deleteLast(h);
      } else { /* 중간인 경우 */
        n->llink->rlink = n->rlink;
        n->rlink->llink = n->llink;
        free(n);
      }
      return 0;
    }

    // n을 다음 노드로 이동
    n = n->rlink;
  }

  /* 찾지 못 한경우 */
  printf("cannot find the node for key = %d\n", key);
  return 0;
}
