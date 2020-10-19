#include "header.h"

struct node* pop(struct node* stackIn[MAX], int *top) {
  if(*top > -1) {
    struct node *returnVal;
    returnVal=stackIn[*top];
    //printf("return val before function return: %p\n",returnVal);
    *top = *top-1;
    return (returnVal);
  }
  else {
    printf("Stack is empty\n");
    //exit(0);
  }
}

