/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 *
 */

#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 if necessary */

// 이중 연결 리스트 구조체 정의
typedef struct Node {
    int key; // 노드의 데이터 값을 저장하는 정수형 변수 선언
    struct Node* llink; // 좌측 노드 링크용 구조체 포인터 변수 선언 
    struct Node* rlink; // 우측 노드 링크용 구조체 포인터 변수 선언 
} listNode;


// 헤드 노드 구조체 정의
typedef struct Head {
    struct Node* first; // 첫 번째 노드를 가리키는 구조체 포인터 변수 선언
} headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

// 데이터의 크기 순으로 노드를 삽입하는 함수 원형 선언
int insertNode(headNode* h, int key);
// 이중 연결 리스트의 마지막 노드에 새로운 노드를 삽입하는 함수 원형 선언
int insertLast(headNode* h, int key);
// 이중 연결 리스트의 첫 번째 노드에 새로운 노드를 삽입하는 함수 원형 선언
int insertFirst(headNode* h, int key);
// 이중 연결 리스트의 노드 중에서 key값을 지닌 노드를 제거하는 함수 원형 선언
int deleteNode(headNode* h, int key);
// 이중 연결 리스트의 마지막 노드를 제거하는 함수 원형 선언
int deleteLast(headNode* h);
// 이중 연결 리스트의 첫 번째 노드를 제거하는 함수 원형 선언
int deleteFirst(headNode* h);
// 이중 연결 리스트의 노드들 간의 링크를 역순으로 뒤집는 함수 원형 선언
int invertList(headNode* h);
// 이중 연결 리스트의 현재 상태를 출력하는 함수 원형 선언
void printList(headNode* h);

int main() {
    char command; // 명령을 저장하는 문자형 변수 선언
    int key; // 노드의 데이터 값으로 사용되는 정수형 변수 선언
    headNode* headnode = NULL; // 헤드 노드를 NULL 값으로 초기화

    // [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Doubly Linked  List                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize    = z           Print         = p \n");
        printf(" Insert Node   = i           Delete Node   = d \n");
        printf(" Insert Last   = n           Delete Last   = e\n");
        printf(" Insert First  = f           Delete First  = t\n");
        printf(" Invert List   = r           Quit          = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        // 입력된 명령대로 함수 호출
        switch(command) {
        case 'z': case 'Z':
            // 이중 연결 리스트 초기화 함수 호출
            initialize(&headnode);
            break;
        case 'p': case 'P':
            // 이중 연결 리스트 정보 출력 함수 호출
            printList(headnode);
            break;
        case 'i': case 'I':
            // key값이 담긴 신규 노드 삽입 함수 호출
            printf("Your Key = ");
            scanf("%d", &key);
            insertNode(headnode, key);
            break;
        case 'd': case 'D':
            // key값을 지닌 노드 삭제 함수 호출
            printf("Your Key = ");
            scanf("%d", &key);
            deleteNode(headnode, key);
            break;
        case 'n': case 'N': 
            // 이중 연결 리스트의 가장 마지막 노드에 신규 노드 삽입 함수 호출
            printf("Your Key = ");
            scanf("%d", &key);
            insertLast(headnode, key);
            break;
        case 'e': case 'E':
            // 이중 연결 리스트의 가장 마지막 노드 삭제 함수 호출
            deleteLast(headnode);
            break;
        case 'f': case 'F':
            // 이중 연결 리스트의 첫 번째 위치에 신규 노드 삽입 함수 호출
            printf("Your Key = ");
            scanf("%d", &key);
            insertFirst(headnode, key);
            break;
        case 't': case 'T':
            // 이중 연결 리스트의 첫 번째 노드 삭제 함수 호출
            deleteFirst(headnode);
            break;
        case 'r': case 'R':
            // 이중 연결 리스트의 링크를 역순으로 바꾸는 함수 호출
            invertList(headnode);
            break;
        case 'q': case 'Q':
            // 이중 연결 리스트 동적할당 해제 함수 호출
            freeList(headnode);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while(command != 'q' && command != 'Q');
    return 1;
}

// 헤드 노드 초기화 함수 정의
int initialize(headNode** h) {
    /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
    if(*h != NULL)
        freeList(*h);

    /* headNode에 대한 메모리를 할당하여 리턴 */
    *h = (headNode*)malloc(sizeof(headNode));
    (*h)->first = NULL;
    return 1;
}

// 이중 연결 리스트 동적할당 해제 함수 정의
int freeList(headNode* h){
    listNode* p = h->first;
    listNode* prev = NULL;

   // 첫 노드부터 마지막 노드까지 동적할당 해제
    while (p != NULL) {
        prev = p;
        p = p->rlink;
        free(prev);
    }

    // 헤드 노드 동적할당 해제
    free(h);
    return 0;
}

// 이중 연결 리스트 정보 출력 함수 정의
void printList(headNode* h) {
    int i = 0;
    listNode* p;

    printf("\n---PRINT\n");

    if(h == NULL) {
        printf("Nothing to print....\n");
        return;
    }

    p = h->first;

    // 첫 노드부터 마지막 노드까지 개별 노드 정보 출력
    while(p != NULL) {
        printf("[ [%d]=%d ] ", i, p->key);
        p = p->rlink;
        i++;
    }

    // 이중 연결 리스트 내 현재 노드 수 출력
    printf("  items = %d\n", i);
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
    // 추가할 노드 생성
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    // 노드 정보 추가
    newNode->key = key;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    // 노드가 하나도 없을 때의 조건
    if (h->first == NULL) {
        h->first = newNode;
    } else { // 노드가 1개 이상 존재할 때의 조건
        listNode* curr = h->first;
        // 마지막 노드에 도달할 때까지 반복
        while (curr->rlink != NULL) {
            curr = curr->rlink;
        }
        // 마지막 노드에 신규 노드 추가
        curr->rlink = newNode;
        newNode->llink = curr;
    }
    return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
    // 노드가 하나도 없을 때의 조건
    if (h->first == NULL) {
        printf("nothing to delete.\n");
        return 0;
    }

    listNode* n = h->first;
    listNode* trail = NULL;

    /* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
    if(n->rlink == NULL) {
        h->first = NULL;
        free(n);
        return 0;
    }

    /* 마지막 노드까지 이동 */
    while(n->rlink != NULL) {
        trail = n;
        n = n->rlink;
    }

    /* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
    trail->rlink = NULL;
    free(n);

    return 0;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
    // 추가할 노드 생성
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    // 노드 정보 추가
    newNode->key = key;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    // 노드가 하나도 없을 때의 조건
    if (h->first == NULL) {
        h->first = newNode;
    } else { // 노드가 1개 이상 존재할 때의 조건
        newNode->rlink = h->first;
        h->first->llink = newNode;
        h->first = newNode;
    }
    return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
    // 노드가 하나도 없을 때의 조건
    if (h->first == NULL) {
        printf("List is empty.\n");
        return 0;
    }

    listNode* curr = h->first;

    // 우측 노드가 존재할 떄의 조건
    if (curr->rlink != NULL) {
        curr->rlink->llink = NULL; // 다음 노드의 좌측 링크를 NULL로 초기화
        h->first = curr->rlink; // 첫 노드를 현재 노드의 우측 링크로 연결
    } else { // 우측 노드가 존재하지 않을 때의 조건
        h->first = NULL;
    }

    free(curr); // 삭제 대상인 현재 노드의 동적할당을 해제
    return 0;
}

/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
    // 노드가 하나도 없을 때의 조건
    if (h->first == NULL) {
        printf("nothing to invert...\n");
        return 0;
    }
    listNode *n = h->first;
    listNode *trail = NULL;
    listNode *middle = NULL;

    // 첫 노드부터 마지막 노드까지 순회하며 노드 링크 SWAP
    while(n != NULL){
        trail = middle;
        middle = n;
        n = n->rlink;
        middle->rlink = trail;
        middle->llink = n;
    }

    h->first = middle;

    return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;
    node->llink = node->rlink = NULL;

    if (h->first == NULL) {
        h->first = node;
        return 0;
    }

    listNode* n = h->first;

    /* key를 기준으로 삽입할 위치를 찾는다 */
    while(n != NULL) {
        if(n->key >= key) {
            /* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
            if(n == h->first) {
                insertFirst(h, key);
            } else { /* 중간이거나 마지막인 경우 */
                node->rlink = n;
                node->llink = n->llink;
                n->llink->rlink = node;
            }
            return 0;
        }

        n = n->rlink;
    }

    /* 마지막 노드까지 찾지 못한 경우, 마지막에 삽입 */
    insertLast(h, key);
    return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
    if (h->first == NULL) {
        printf("nothing to delete.\n");
        return 1;
    }

    listNode* n = h->first;

    while(n != NULL) {
        if(n->key == key) {
            if(n == h->first) { /* 첫 노드째 노드 인경우 */
                deleteFirst(h);
            } else if (n->rlink == NULL) { /* 마지막 노드인 경우 */
                deleteLast(h);
            } else { /* 중간인 경우 */
                n->llink->rlink = n->rlink;
                n->rlink->llink = n->llink;
                free(n);
            }
            return 1;
        }

        n = n->rlink;
    }

    /* 찾지 못 한경우 */
    printf("cannot find the node for key = %d\n", key);
    return 1;
}