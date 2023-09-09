/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>


// 이진 탐색 트리의 개별 노드를 위한 구조체 정의
typedef struct node {
	int key; // 노드의 데이터(key) 값을 저장하는 정수형 변수 선언
	struct node *left; // 좌측 자식 노드를 가리키는 포인터
	struct node *right; // 우측 자식 노드를 가리키는 포인터
} Node; // 구조체 typedef로 Node라는 이름을 추가로 지정

/* for stack */
#define MAX_STACK_SIZE		20 // 스택의 최대 크기 정의
Node* stack[MAX_STACK_SIZE]; // 스택 표현하기 위해 Node에 대한 포인터 배열 선언
int top = -1; // 스택의 최상단 인덱스를 표현하는 정수형 변수 선언

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20 // 큐의 최대 크기 정의
Node* queue[MAX_QUEUE_SIZE]; // 큐 표현하기 위해 Node에 대한 포인터 배열 선언
int front = -1; // 큐의 앞 인덱스를 표현하는 정수형 변수 선언
int rear = -1; // 큐의 뒤 인덱스를 표현하는 정수형 변수 선언

int initializeBST(Node** h); // 이진 탐색 트리를 초기화하는 함수의 프로토타입을 선언
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* functions that you have to implement */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int deleteNode(Node* head, int key);  /* delete the node for the key */
Node* pop(); // 스택에서 pop 연산을 수행하는 함수의 프로토타입을 선언
void push(Node* aNode); // 스택에 push 연산을 수행하는 함수의 프로토타입을 선언
Node* deQueue(); // 큐에서 맨 앞의 요소를 꺼내는 함수의 프로토타입을 선언
void enQueue(Node* aNode); // 큐에 노드를 추가하는 함수의 프로토타입을 선언

/* you may add your own defined functions if necessary */


void printStack();



int main()
{
	char command;
	int key;
	Node* head = NULL;

	// [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
		    // 이진 탐색 트리 초기화
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			// 이진 탐색 트리에 할당된 동적 메모리를 해제
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			// 입력받은 키 값을 이진 탐색 트리에 삽입
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			// 입력받은 키 값을 가진 노드를 이진 탐색 트리에서 삭제
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			// 이진 탐색 트리를 inorder 방식으로 출력
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			// 이진 탐색 트리를 inorder 방식으로 출력(반복적 방법)
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			// 이진 탐색 트리를 레벨 순서로 출력합니다.
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			// 스택의 내용을 출력
			printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

// 이진 탐색 트리를 초기화하는 함수
int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h); // 이진 탐색 트리의 모든 노드를 제거

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); // 헤드 노드를 생성
	(*h)->left = (*h)->right = NULL;
	(*h)->key = -9999; // 헤드 노드의 키 값을 -9999로 설정

	top = -1; // 스택의 상단 인덱스를 -1로 초기화

	front = rear = -1; // 큐의 front와 하단 인덱스를 -1로 초기화

	return 1;
}


// 재귀적으로 이진 트리를 inorder 방식으로 순회하는 함수
void recursiveInorder(Node* ptr)
{
	// 만약 ptr이 NULL이 아닐 때
	if(ptr) {
		recursiveInorder(ptr->left); // ptr이 가리키는 노드의 좌측 서브트리를 재귀적으로 중위 순회
		printf(" [%d] ", ptr->key); // ptr이 가리키는 노드의 키 값을 출력
		recursiveInorder(ptr->right); // ptr이 가리키는 노드의 우측 서브트리를 재귀적으로 중위 순회
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node)
{
	for(;;) // 무한 루프 시작
	{
		// node가 NULL이 아닌 동안 반복하며, node를 node의 좌측 자식으로 이동
		for(; node; node = node->left)
			push(node);  // node를 스택에 push
		node = pop(); // node를 스택에서 pop하여 node에 저장

		if(!node) break; // node가 NULL이면, 무한 루프 해제
		printf(" [%d] ", node->key); // node의 키 값을 출력

		// node를 node의 우측 자식으로 이동
		node = node->right;
	}
}

/**
 * textbook: p 225
 */
// 이진 트리를 레벨 순서(너비 우선)로 순회하는 함수
void levelOrder(Node* ptr)
{
	// int front = rear = -1;

	// 만약 ptr이 NULL이면 즉시 함수를 종료
	if(!ptr) return; /* empty tree */

	enQueue(ptr); // ptr을 큐에 삽입합니다.

	for(;;) // 무한 루프를 시작
	{
		ptr = deQueue(); // ptr을 큐에서 뺌
		if(ptr) { // 만약 ptr이 NULL이 아닐 때
			printf(" [%d] ", ptr->key); // ptr의 키 값을 출력합니다.

			if(ptr->left) // 만약 ptr의 좌측 자식이 있을 때
				enQueue(ptr->left); // ptr의 좌측 자식을 큐에 삽입
			if(ptr->right) // 만약 ptr의 우측 자식이 있을 때
				enQueue(ptr->right); // ptr의 우측 자식을 큐에 삽입
		}
		else // ptr이 NULL일 때
			break; // 무한 루프 해제

	}

}

// 이진 탐색 트리에 신규 노드를 삽입하는 함수
int insert(Node* head, int key)
{
	// 신규 노드를 동적으로 할당
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key; // 신규 노드의 키 값을 입력받은 키 값으로 설정
	// 신규 노드의 좌측 자식과 우측 자식을 NULL로 초기화
	newNode->left = NULL;
	newNode->right = NULL;

	// 헤드 노드의 좌측 자식이 NULL일 때
	if (head->left == NULL) {
		head->left = newNode; // 헤드 노드의 좌측 자식을 신규 노드로 설정
		return 1; // 함수 종료
	}

	/* head->left is the root */
	Node* ptr = head->left; // ptr을 트리의 루트 노드로 설정

	// parentNode를 NULL로 초기화
	Node* parentNode = NULL;

	// ptr이 NULL이 아닌 동안 반복
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		// 만약 현재 노드의 키 값이 삽입하려는 노드의 키값과 같다면, 함수 종료
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		// parentNode를 ptr로 업데이트해 현재 노드를 부모 노드로 설정
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		// 현재 노드의 키 값이 삽입하려는 키 값보다 작을 때
		if(ptr->key < key)
			ptr = ptr->right; // ptr을 현재 노드의 우측 자식으로 이동
		else
			ptr = ptr->left; // ptr을 현재노드의 우측 자식으로 이동
	}

	/* linking the new node to the parent */
	if(parentNode->key > key) // 만약 부모 노드의 키 값이 삽입하려는 키 값보다 클 때
		parentNode->left = newNode; // 부모 노드의 좌측 자식을 신규 노드로 설정
	else
		parentNode->right = newNode; // 부모 노드의 우측 자식을 신규 노드로 설정
	return 1;
}

// 이진 탐색 트리에서 노드를 삭제하는 함수
int deleteNode(Node* head, int key)
{
	 // 만약 헤드가 NULL일 때 삭제할 노드가 없으므로 함수 종료
	if (head == NULL) {
		printf("\n Nothing to delete!!\n");
		return -1;
	}

	// 만약 헤드의 좌측 자식 노드가 NULL일 때 삭제할 노드가 없으므로 함수 종료
	if (head->left == NULL) {
		printf("\n Nothing to delete!!\n");
		return -1;
	}

	/* head->left is the root */
	Node* root = head->left; // 루트 노드를 설정

	Node* parent = NULL; // 부모 노드를 NULL로 설정
	Node* ptr = root; // ptr 변수에 루트 노드를 설정

	// 삭제할 노드를 찾기 위해 트리를 탐색
	while((ptr != NULL)&&(ptr->key != key)) {
		if(ptr->key != key) {

			parent = ptr;	/* save the parent */

			if(ptr->key > key) // 찾는 키가 현재 노드의 키보다 작으면 좌측 서브트리로 이동
				ptr = ptr->left;
			else // 찾는 키가 현재 노드의 키보다 크면 우측 서브트리로 이동
				ptr = ptr->right;
		}
	}

	/* there is no node for the key */
	// 만약 삭제할 노드를 찾지 못했을 때 함수 종료
	if(ptr == NULL)
	{
		printf("No node for key [%d]\n ", key);
		return -1;
	}

	/*
	 * case 1: the node which has to be removed is a leaf node
	 */
	// 삭제할 노드가 리프 노드일 때
	if(ptr->left == NULL && ptr->right == NULL)
	{
		if(parent != NULL) { /* parent exists, parent's left and right links are adjusted */
			if(parent->left == ptr)
				parent->left = NULL;
			else
				parent->right = NULL;
		} else {
			/* parent is null, which means the node to be deleted is the root */
			head->left = NULL;

		}

		free(ptr); // 노드 동적 메모리 해제
		return 1;
	}

	/**
	 * case 2: if the node to be deleted has one child
	 */
	// 삭제할 노드가 한 개의 자식 노드를 가지고 있을 때
	if ((ptr->left == NULL || ptr->right == NULL))
	{
		Node* child; // 자식 노드를 가리킬 포인터
		if (ptr->left != NULL)
			child = ptr->left;
		else
			child = ptr->right;

		if(parent != NULL)
		{
			if(parent->left == ptr) // 부모의 좌측 자식이면, 부모의 좌측 링크를 조정
				parent->left = child;
			else // 부모의 우측 자식이면, 부모의 우측 링크를 조정
				parent->right = child;
		} else {
			/* parent is null, which means the node to be deleted is the root
			 * and the root has one child. Therefore, the child should be the root
			 */
			root = child;
		}

		free(ptr); // 노드 동적 메모리 해제
		return 1;
	}

	/**
	 * case 3: the node (ptr) has two children
	 *
	 * we have to find either the biggest descendant node in the left subtree of the ptr
	 * or the smallest descendant in the right subtree of the ptr.
	 *
	 * we will find the smallest descendant from the right subtree of the ptr.
	 *
	 */

	Node* candidate;
	parent = ptr;


	candidate = ptr->right;

	// 가장 좌측 깊이의 노드를 찾을 때까지 이동
	while(candidate->left != NULL)
	{
		parent = candidate;
		candidate = candidate->left;
	}

	/* the candidate node is the right node which has to be deleted.
	 * note that candidate's left is null
	 */
	if (parent->right == candidate)
		parent->right = candidate->right;
	else
		parent->left = candidate->right;

	/* instead of removing ptr, we just change the key of ptr
	 * with the key of candidate node and remove the candidate node
	 */
	// ptr을 제거하는 대신 ptr의 키를 후보 노드의 키로 변경하고 후보 노드를 제거
	ptr->key = candidate->key;

	free(candidate); // 후보 노드 동적 메모리를 해제
	return 1;
}


void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left); // 좌측 자식 노드를 재귀적으로 해제
		freeNode(ptr->right); // 우측 자식 노드를 재귀적으로 해제
		free(ptr); // 현재 노드를 해제
	}
}

int freeBST(Node* head)
{
	// 헤드 노드가 가리키는 노드가 자신인 경우
	if(head->left == head)
	{
		free(head); // 헤드 노드를 해제합니다.
		return 1; // 함수 종료
	}

	Node* p = head->left; // 헤드 노드의 좌측 자식 노드를 가리킴

	freeNode(p); // p노드와 그 자식 노드들을 재귀적으로 동적 할당 해제

	free(head); // 헤드 노드를 동적 해제
	return 1; // 함수 종료
}



Node* pop()
{
	if (top < 0) return NULL; // 스택이 비어 있는 경우 NULL을 반환
	return stack[top--]; // 스택의 가장 상위에 있는 노드를 반환하고 top을 하나 감소
}

void push(Node* aNode)
{
	stack[++top] = aNode; // 스택의 top 위치에 노드를 추가하고 top을 하나 증가
}


void printStack()
{
	int i = 0;
	printf("--- stack ---\n");
	while(i <= top)
	{
		// 스택의 각 위치와 해당 위치의 노드 키 값을 출력
		printf("stack[%d] = %d\n", i, stack[i]->key);
	}
}


Node* deQueue()
{
	if (front == rear) { // 큐가 비어 있을 때
		// printf("\n....Now Queue is empty!!\n" );
		return NULL;
	}

	// front 위치를 하나 증가
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front]; // 새로운 front 위치의 노드를 반환

}

void enQueue(Node* aNode)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE; // rear 위치를 하나 증가
	if (front == rear) { // 큐가 가득 찼을 때
		// printf("\n....Now Queue is full!!\n");
		return;
	}

	queue[rear] = aNode; // 새로운 rear위치에 노드를 추가
}