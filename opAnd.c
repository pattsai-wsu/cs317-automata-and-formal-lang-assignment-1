#include "header.h"

struct node* opAnd(struct node* beginNode, struct node* nextNode) {
  struct trans* newTransRoot = beginNode->transList;
  struct node* newNfaParent = beginNode;

  struct trans* beginNodePrevious;
  struct trans* beginNodeCurrent;
  beginNodePrevious = beginNode->transList;
  beginNodeCurrent = beginNodePrevious->next;

  while(beginNodeCurrent->next != NULL) {
    beginNodeCurrent = beginNodeCurrent->next;
  }
  beginNodeCurrent->state2 = (beginNodeCurrent->state1) + 1;

  struct trans* nextNodePrevious;
  struct trans* nextNodeCurrent;
  nextNodePrevious = nextNode->transList;
  nextNodeCurrent = nextNodePrevious->next;

  beginNodeCurrent->next = nextNodeCurrent;
  nextNodePrevious->next = NULL;  //remove pointer from transition root
  nextNodePrevious = beginNodeCurrent;

  while(nextNodeCurrent->next != NULL){
    nextNodeCurrent->nfaParent = newNfaParent;
    nextNodeCurrent->transRootPtr = newTransRoot;
    nextNodeCurrent->state1 = nextNodePrevious->state2;
    nextNodeCurrent->state2 = (nextNodeCurrent->state1) + 1;
    nextNodePrevious = nextNodeCurrent;
    nextNodeCurrent = nextNodeCurrent->next;
  }
  nextNodeCurrent->nfaParent = newNfaParent;
  nextNodeCurrent->transRootPtr = newTransRoot;
  nextNodeCurrent->state1 = nextNodePrevious->state2;

  beginNode->next = NULL;
  nextNode->transList = NULL;   // remove pointer from next node 
  beginNode->acceptStates = nextNodeCurrent->state1;

return (beginNode);
}
