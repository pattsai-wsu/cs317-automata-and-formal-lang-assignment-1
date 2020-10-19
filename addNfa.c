#include "header.h"

struct node* addNfa(struct node* nfaLL, char fullString[120]) {

  while(nfaLL->next != NULL) {
    nfaLL = nfaLL->next;
  }

  char *addFullString = fullString;
  //printf("inside addNfa func fullString var: %s", addFullString);

  struct node* previous;
  struct node* current;

  previous = nfaLL;
  current = nfaLL->next;

  struct node *newNode = malloc(sizeof(struct node));
  transition transListInit;
  transListInit = transitionInit(newNode);

  newNode->startState = 1;
  newNode->acceptStates = 2;
  newNode->isNfaRoot = false;
  newNode->isValid = true;
  newNode->nfaFullString = addFullString;
  newNode->transList = transListInit;
  newNode->next = NULL;

  previous->next = newNode;

  return (newNode);
}
