#include "header.h"

void push(struct node* nfaIn, struct node* stackIn[MAX], int *top) {
  if (*top<MAX) {
    *top = *top+1;
    stackIn[*top] = nfaIn;
  }
  else {
    printf("Stack is Full\n");
    exit(0);
  }
  return;
}

