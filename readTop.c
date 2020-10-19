#include "header.h"

void readTop(char *stackIn, int *top) {
  if(*top == -1) {
    printf("Stack is Empty\n");
  }
  else {
    printf("%c\n",stackIn[*top]);
  }
  return;
}

