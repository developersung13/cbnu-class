/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* í•„ìš”í•œ í—¤ë”íŒŒì¼ ì¶”ê°€ */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
} headNode;


/* í•¨ìˆ˜ ë¦¬ìŠ¤íŠ¸ */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNodeê°€ NULLì´ ì•„ë‹ˆë©´, freeNodeë¥¼ í˜¸ì¶œí•˜ì—¬ í• ë‹¹ëœ ë©”ëª¨ë¦¬ ëª¨ë‘ í•´ì œ */
	if(h != NULL)
		freeList(h);

	/* headNodeì— ëŒ€í•œ ë©”ëª¨ë¦¬ë¥¼ í• ë‹¹í•˜ì—¬ ë¦¬í„´ */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* hì™€ ì—°ê²°ëœ listNode ë©”ëª¨ë¦¬ í•´ì œ
	 * headNodeë„ í•´ì œë˜ì–´ì•¼ í•¨.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list ì²˜ìŒì— keyì— ëŒ€í•œ ë…¸ë“œí•˜ë‚˜ë¥¼ ì¶”ê°€
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ë¦¬ìŠ¤íŠ¸ë¥¼ ê²€ìƒ‰í•˜ì—¬, ìž…ë ¥ë°›ì€ keyë³´ë‹¤ í°ê°’ì´ ë‚˜ì˜¤ëŠ” ë…¸ë“œ ë°”ë¡œ ì•žì— ì‚½ìž… */
int insertNode(headNode* h, int key) {

	return 0;
}

/**
 * listì— keyì— ëŒ€í•œ ë…¸ë“œí•˜ë‚˜ë¥¼ ì¶”ê°€
 */
int insertLast(headNode* h, int key) {

	return 0;
}


/**
 * listì˜ ì²«ë²ˆì§¸ ë…¸ë“œ ì‚­ì œ
 */
int deleteFirst(headNode* h) {


	return 0;
}


/**
 * listì—ì„œ keyì— ëŒ€í•œ ë…¸ë“œ ì‚­ì œ
 */
int deleteNode(headNode* h, int key) {

	return 0;

}

/**
 * listì˜ ë§ˆì§€ë§‰ ë…¸ë“œ ì‚­ì œ
 */
int deleteLast(headNode* h) {

	return 0;
}


/**
 * ë¦¬ìŠ¤íŠ¸ì˜ ë§í¬ë¥¼ ì—­ìˆœìœ¼ë¡œ ìž¬ ë°°ì¹˜
 */
int invertList(headNode* h) {

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
