/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h> // 표준출력 함수 사용을 위한 라이브러리 추가
#include <stdlib.h> // 메모리 동적할당 malloc 함수 사용을 위한 라이브러리 추가

typedef struct node {
	int key; // 노드의 데이터(key) 값을 저장하는 정수형 변수 선언
	struct node *left; // 왼쪽 자식 노드를 가리키는 포인터
	struct node *right; // 오른쪽 자식 노드를 가리키는 포인터
} Node; // 구조체 typedef로 Node라는 이름을 추가로 지정

int initializeBST(Node** h); // 이진 트리 초기화 함수

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command; // 사용자로부터 입력받을 명령을 저장할 문자형 변수
	int key; // 사용자로부터 입력받을 키 값을 저장할 정수형 변수
	Node* head = NULL; // 이진 탐색 트리의 헤드 노드를 가리키는 포인터. 초기값은 NULL.
	Node* ptr = NULL; /* temp, 임시적으로 노드를 가리키기 위한 포인터. 초기값은 NULL. */

	// [---- [Sung Yeolam, 성열암] [2020039037] ----] 문장 출력 및 개행
    printf("[---- [Sung Yeolam, 성열암] [2020039037] ----]\n");

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) { // 사용자로부터 입력받은 command에 따라 분기를 수행하는 switch문
		case 'z': case 'Z': // 사용자가 'z' 혹은 'Z'를 입력한 경우
			initializeBST(&head); // 이진 탐색 트리를 초기화
			break;
		case 'q': case 'Q': // 사용자가 'q' 혹은 'Q'를 입력한 경우
			freeBST(head); // 이진 탐색 트리를 메모리에서 해제
			break;
		case 'n': case 'N': // 사용자가 'n' 혹은 'N'를 입력한 경우
			printf("Your Key = "); // 키 값을 입력하라는 메시지 출력
			scanf("%d", &key); // 사용자로부터 키 값을 입력받음
			insert(head, key); // 해당 키 값을 가진 노드를 이진 탐색 트리에 삽입
			break;
		case 'd': case 'D': // 사용자가 'd' 혹은 'D'를 입력한 경우
			printf("Your Key = "); // 키 값을 입력하라는 메시지 출력
			scanf("%d", &key); // 사용자로부터 키 값을 입력받음
			deleteLeafNode(head, key); // 해당 키 값을 가진 노드를 이진 탐색 트리에서 삭제
			break;
		case 'f': case 'F': // 사용자가 'f' 혹은 'F'를 입력한 경우
			printf("Your Key = "); // 키 값을 입력하라는 메시지 출력
			scanf("%d", &key); // 사용자로부터 키 값을 입력받음
			ptr = searchIterative(head, key); // 해당 키 값을 가진 노드를 이진 탐색 트리에서 순차적으로 탐색
			if(ptr != NULL) // 탐색된 노드가 있으면
				printf("\n node [%d] found at %p\n", ptr->key, ptr); // 노드의 키 값과 주소를 출력
			else // 탐색된 노드가 없으면
				printf("\n Cannot find the node [%d]\n", key); // 해당 키 값을 가진 노드를 찾을 수 없다는 메시지 출력
			break;
		case 's': case 'S': // 사용자가 's' 혹은 'S'를 입력한 경우
			printf("Your Key = "); // 키 값을 입력하라는 메시지 출력
			scanf("%d", &key); // 사용자로부터 키 값을 입력받음
			// 해당 키 값을 가진 노드를 이진 탐색 트리에서 재귀적으로 탐색
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL) // 탐색된 노드가 있으면
				// 노드의 키 값과 주소를 출력
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else // 탐색된 노드가 없으면
				// 해당 키 값을 가진 노드를 찾을 수 없다는 메시지 출력
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 'i': case 'I':
			// 사용자가 'i' 혹은 'I'를 입력한 경우
			inorderTraversal(head->left); // 이진 탐색 트리를 중위 순회
			break;
		case 'p': case 'P': // 사용자가 'p' 혹은 'P'를 입력한 경우
			preorderTraversal(head->left); // 이진 탐색 트리를 전위 순회
			break;
		case 't': case 'T': // 사용자가 't' 혹은 'T'를 입력한 경우
			postorderTraversal(head->left); // 이진 탐색 트리를 후위 순회
			break;
		default: // 사용자가 위에서 명시된 명령 이외의 것을 입력한 경우
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // 사용자가 'q' 혹은 'Q'를 입력하기 전까지 반복 실행

	return 1; // 메인 함수 종료
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}

void inorderTraversal(Node* ptr)
{
	if(ptr) { // 만약 ptr이 NULL이 아니라면
		inorderTraversal(ptr->left); // 왼쪽 서브트리에 대해 중위 순회를 수행
		printf(" [%d] ", ptr->key); // 현재 노드의 키 값을 출력
		inorderTraversal(ptr->right); // 오른쪽 서브트리에 대해 중위 순회를 수행
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr) { // 만약 ptr이 NULL이 아니라면
		printf(" [%d] ", ptr->key); // 현재 노드의 키 값을 출력
		preorderTraversal(ptr->left); // 왼쪽 서브트리에 대해 전위 순회를 수행
		preorderTraversal(ptr->right); // 오른쪽 서브트리에 대해 전위 순회를 수행
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr) { // 만약 ptr이 NULL이 아니라면
		postorderTraversal(ptr->left); // 왼쪽 서브트리에 대해 후위 순회를 수행
		postorderTraversal(ptr->right); // 오른쪽 서브트리에 대해 후위 순회를 수행
		printf(" [%d] ", ptr->key); // 현재 노드의 키 값을 출력
	}
}


int insert(Node* head, int key) // 새 노드를 이진 탐색 트리에 삽입하는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드를 위한 메모리를 동적으로 할당
	newNode->key = key; // 새 노드의 키 값을 설정
	newNode->left = NULL; // 새 노드의 왼쪽 자식 노드를 NULL로 초기화
	newNode->right = NULL; // 새 노드의 오른쪽 자식 노드를 NULL로 초기화

	if (head->left == NULL) { // 만약 헤드의 왼쪽 자식 노드가 비어 있다면 (즉, 트리가 비어 있다면)
		head->left = newNode; // 헤드의 왼쪽 자식 노드로 새 노드를 설정
		return 1; // 성공적으로 노드를 삽입했음을 나타내는 1을 반환
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key) // 만약 부모 노드의 키 값이 입력된 키 값보다 크다면
		parentNode->left = newNode; // 부모 노드의 왼쪽 자식 노드로 새 노드를 설정
	else // 그렇지 않다면 (즉, 부모 노드의 키 값이 입력된 키 값보다 작다면)
		parentNode->right = newNode; // 부모 노드의 오른쪽 자식 노드로 새 노드를 설정
	return 1; // 성공적으로 노드를 삽입했음을 나타내는 1을 반환
}

// 특정 키 값을 가진 잎 노드를 이진 탐색 트리에서 삭제하는 함수
int deleteLeafNode(Node* head, int key)
{
	if (head == NULL) { // 만약 헤드 노드가 NULL이라면 (즉, 트리가 없다면)
		printf("\n Nothing to delete!!\n"); // 삭제할 노드가 없다는 메시지를 출력
		return -1; // 오류를 나타내는 -1을 반환
	}

	if (head->left == NULL) { // 트리의 루트 노드가 없다면
		printf("\n Nothing to delete!!\n");
		return -1;
	}

	/* head->left is the root */
	Node* ptr = head->left;


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head;

	while(ptr != NULL) { // 노드를 찾을 때까지 또는 더 이상 탐색할 노드가 없을 때까지 반복

		if(ptr->key == key) { // 현재 노드의 키 값이 입력된 키 값과 같다면
			if(ptr->left == NULL && ptr->right == NULL) {

				/* root node case */
				if(parentNode == head)
					head->left = NULL;

				/* left node case or right case*/
				if(parentNode->left == ptr)
					parentNode->left = NULL;
				else // 삭제할 노드가 부모 노드의 오른쪽 자식 노드라면
					parentNode->right = NULL;

				free(ptr); // 삭제할 노드의 메모리를 해제
			}
			else { // 현재 노드가 잎 노드가 아니라면
				printf("the node [%d] is not a leaf \n", ptr->key);
			}
			return 1;
		}

		/* keep the parent node */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;


	}

	printf("Cannot find the node for key [%d]\n ", key);

	return 1;
}

// 키 값을 가지는 노드를 재귀적으로 찾는 함수
Node* searchRecursive(Node* ptr, int key)
{
	if(ptr == NULL) // 현재 노드가 NULL이면
		return NULL;

	if(ptr->key < key) // 만약 현재 노드의 키가 입력된 키보다 작다면
		ptr = searchRecursive(ptr->right, key); // 오른쪽 서브 트리에서 재귀적으로 탐색
	else if(ptr->key > key) // 만약 현재 노드의 키가 입력된 키보다 크다면
		ptr = searchRecursive(ptr->left, key); // 왼쪽 서브 트리에서 재귀적으로 탐색

	/* if ptr->key == key */
	return ptr; // 키 값을 가진 노드를 찾았거나 노드가 없다면(NULL) 현재 노드 반환

}

// 키 값을 가지는 노드를 반복적으로 찾는 함수
Node* searchIterative(Node* head, int key)
{
	/* root node */
	Node* ptr = head->left; // 루트 노드로 시작

	while(ptr != NULL) // 노드가 있을 동안
	{
		if(ptr->key == key) // 만약 현재 노드의 키가 입력된 키와 같다면
			return ptr; // 현재 노드 반환

		// 만약 현재 노드의 키가 입력된 키보다 작다면
		if(ptr->key < key) ptr = ptr->right; // 오른쪽 서브 트리로 이동
		else // 만약 현재 노드의 키가 입력된 키보다 크다면
			ptr = ptr->left; // 왼쪽 서브 트리로 이동
	}

	return NULL;
}

// 노드를 해제하는 함수
void freeNode(Node* ptr)
{
	if(ptr) { // 만약 노드가 존재하면
		freeNode(ptr->left); // 왼쪽 자식 노드를 재귀적으로 해제
		freeNode(ptr->right); // 오른쪽 자식 노드를 재귀적으로 해제
		free(ptr); // 현재 노드 해제
	}
}

// 이진 탐색 트리를 해제하는 함수
int freeBST(Node* head)
{
    // 만약 헤드 노드의 왼쪽 링크가 자기 자신을 가리키면 (즉, 트리에 노드가 없으면)
	if(head->left == head)
	{
		free(head); // 헤드 노드를 해제
		return 1; // 함수 종료
	}

	Node* p = head->left; // 이진 탐색 트리의 루트 노드를 p에 저장

	freeNode(p); // 루트 노드를 시작으로 모든 노드를 재귀적으로 해제

	free(head); // 마지막으로 헤드 노드를 해제
	return 1;
}