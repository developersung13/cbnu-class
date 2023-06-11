#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} Node;

void freeNode(Node *p) {
  if (p) {
    freeNode(p->left);
    freeNode(p->right);
    free(p);
  }
}

void initialize(Node **h) {
  if (*h != NULL)
    freeNode(*h);

  *h = (Node *)malloc(sizeof(Node));
  (*h)->key = -999;
  (*h)->left = (*h)->right = NULL;
}

void insertNode(Node *h, int key) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;

  if (h->left == NULL) {
    h->left = newNode;
    return;
  }

  Node *p = h->left;
  Node *parentNode = NULL;

  while (p != NULL) {
    if (p->key == key || key == -1) {
      freeNode(newNode);
      return;
    }

    parentNode = p;
    if (p->key < key)
      p = p->right;
    else
      p = p->left;
  }

  if (parentNode->key < key)
    parentNode->right = newNode;
  else
    parentNode->left = newNode;
}

void preorder(Node *p) {
  if (p) {
    printf("%d ", p->key);
    preorder(p->left);
    preorder(p->right);
  }
}

void inorder(Node *p) {
  if (p) {
    inorder(p->left);
    printf("%d ", p->key);
    inorder(p->right);
  }
}

void postorder(Node *p) {
  if (p) {
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->key);
  }
}

int main() {
  Node *h = NULL;
  initialize(&h);

  int i;
  do {
    scanf("%d", &i);
    insertNode(h, i);
  } while (i != -1);

  preorder(h->left);
  printf("\n");
  inorder(h->left);
  printf("\n");
  postorder(h->left);

  freeNode(h);
}