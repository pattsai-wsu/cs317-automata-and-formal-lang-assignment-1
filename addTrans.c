#include "header.h"

struct trans* addTrans(struct node* curNfa, char cIn) {
  struct trans* previous;
  struct trans* current;
  struct trans* end;

  previous = curNfa->transList;
  current = curNfa->transList->next;

  struct trans *newTrans = malloc(sizeof(struct trans));

  newTrans->state1 = 1;
  newTrans->state2 = 2;
  newTrans->symbol = cIn;
  newTrans->isTransRoot = false;
  newTrans->transRootPtr = previous->transRootPtr;
  newTrans->nfaParent = previous->nfaParent;
  newTrans->next = NULL;

  addTransEnd(newTrans);
  previous->next = newTrans;

  return (newTrans);
}
