#include "header.h"

void addTransEnd(struct trans* beforeTrans) {

  struct trans *newTrans = malloc(sizeof(struct trans));

  newTrans->state1 = beforeTrans->state2;
  newTrans->state2 = -999;
  newTrans->symbol = 'E';
  newTrans->isTransRoot = false;
  newTrans->transRootPtr = beforeTrans->transRootPtr;
  newTrans->nfaParent = beforeTrans->nfaParent;
  newTrans->next = NULL;

  beforeTrans->next = newTrans;

  return;
}

