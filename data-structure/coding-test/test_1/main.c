#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node *link;
} listNode;

typedef struct Head {
	listNode *first;
} headNode;

void insertLast(headNode *h, int key) {
	listNode *p = h->first;
	listNode *newNode = (listNode*)malloc(sizeof(listNode));
	newNode->key = key;
	newNode->link = NULL;
	if (p == NULL) {
		h->first = newNode;
		return;
	}
	
	while (p->link != NULL) {
		p = p->link;
	}
	
	p->link = newNode;
}

void invert(headNode *h) {
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
}

void freeList(headNode *h) {
	listNode *p = h->first;
	listNode *prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
}

void makelist (headNode **h, int N) {
	int k;
	
	if (*h != NULL) freeList(*h);
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;
	
	for (k=1; k <= N; k++)
		insertLast(*h, k);
}

void printList(headNode *h) {
	listNode *p = h->first;
	while (p != NULL) {
		printf("%d ", p->key);
		p = p->link;
	}
}

int main() {
	int N;
	headNode *h = NULL;
	
	scanf("%d", &N);
	makelist(&h, N);	
	
	printList(h);
	invert(h);
	printList(h);
	freeList(h);
	return 0;
}