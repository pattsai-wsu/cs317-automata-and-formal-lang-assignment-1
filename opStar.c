#include "header.h"

struct node* opStar(struct node* beginNode) {
  struct trans* beginNodePrevious;
  struct trans* beginNodeCurrent;
  int numStates=0;
  
  beginNodePrevious = beginNode->transList;
  beginNodeCurrent = beginNodePrevious->next;
  numStates++;

  while(beginNodeCurrent->next != NULL) {
    beginNodeCurrent = beginNodeCurrent->next;
    numStates++;
  }
  numStates++;

  struct trans* newStateTrans1 = malloc(sizeof(struct trans));
  newStateTrans1->state1 = numStates;
  newStateTrans1->state2 = beginNode->transList->next->state1;
  newStateTrans1->symbol = 'E';
  newStateTrans1->isTransRoot = false;
  newStateTrans1->nfaParent = beginNode;
  newStateTrans1->next = beginNode->transList->next;

  struct trans* newStateTransEnd = malloc(sizeof(struct trans));
  newStateTransEnd->state1 = newStateTrans1->state1;
  newStateTransEnd->state2 = newStateTrans1->state2;
  newStateTransEnd->symbol = 'E';
  newStateTransEnd->isTransRoot = false;
  newStateTransEnd->nfaParent = beginNode;
  newStateTransEnd->next = NULL;

  beginNodeCurrent->next = newStateTransEnd;

  beginNodeCurrent = beginNodePrevious->next;

  while(beginNodeCurrent->state1 != beginNode->acceptStates) {
    beginNodeCurrent = beginNodeCurrent->next;
  }

  beginNodeCurrent->state2 = newStateTrans1->state1;

  beginNode->transList->next = newStateTrans1;
  beginNode->startState = newStateTrans1->state1;
  beginNode->acceptStates = newStateTrans1->state1;

return (beginNode);
}
