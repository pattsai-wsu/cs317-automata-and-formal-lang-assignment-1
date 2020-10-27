#include "header.h"

struct node* opAnd(struct node* beginNode, struct node* nextNode) {
  struct trans* newTransRoot = beginNode->transList;
  struct node* newNfaParent = beginNode;
  int addState,diff;

  struct trans* beginNodePrevious;
  struct trans* beginNodeCurrent;
  struct trans* beginNodeSaveEnd;
  beginNodePrevious = beginNode->transList;
  beginNodeCurrent = beginNodePrevious->next;

  while(beginNodeCurrent->next != NULL) {
    beginNodeCurrent = beginNodeCurrent->next;
  }

  beginNodeSaveEnd = beginNodeCurrent;

  struct trans* nextNodePrevious;
  struct trans* nextNodePreviousDelete;
  struct trans* nextNodeCurrent;
  struct trans* nextNodeSaveStart;
  nextNodePrevious = nextNode->transList;
  nextNodeCurrent = nextNodePrevious->next;
  nextNodeSaveStart = nextNodeCurrent;
  addState=beginNodeCurrent->state1; //should be 4 in my ex

  beginNodeCurrent->next = nextNodeCurrent;
  nextNodePrevious->next = NULL;  //remove pointer from transition root
  free(nextNodePrevious);
  nextNodePrevious = beginNodeCurrent;

  nextNodeCurrent->nfaParent = newNfaParent;
  nextNodeCurrent->transRootPtr = newTransRoot;


  nextNodeCurrent->state1 = nextNodeCurrent->state1 + addState;
  beginNodeSaveEnd->state2 = nextNodeSaveStart->state1;
  nextNodeCurrent->state2 = nextNodeCurrent->state2 + addState;

  //printf("startOr state value: %d\n", startOr);

  nextNodePrevious = nextNodeCurrent;
  nextNodeCurrent = nextNodeCurrent->next;

  while(nextNodeCurrent->next != NULL){
    nextNodeCurrent->nfaParent = newNfaParent;
    nextNodeCurrent->transRootPtr = newTransRoot;

    if(nextNodeCurrent->state2 == -999) {
      nextNodePreviousDelete=nextNodeCurrent;
      nextNodeCurrent=nextNodePreviousDelete->next;
      nextNodePrevious->next=nextNodeCurrent;
      nextNodePreviousDelete->next=NULL;
      free(nextNodePreviousDelete);
      nextNodeCurrent->state1 = addState;
      nextNodeCurrent->state2 = (nextNodeCurrent->state2) + addState;
    } 
    else {
      nextNodeCurrent->state1 = (nextNodeCurrent->state1) + addState;
      nextNodeCurrent->state2 = (nextNodeCurrent->state2) + addState;
    }

    nextNodePrevious = nextNodeCurrent;
    nextNodeCurrent = nextNodeCurrent->next;
  }

  if(nextNodeCurrent->next == NULL) {
    diff = (nextNodeCurrent->state2 - nextNodeCurrent->state1);	  
    if(nextNodeCurrent->state2 != -999) {
      if(diff < 1 || diff > 1) {
        nextNodeCurrent->state1 = nextNodeCurrent->state1 + addState;
        nextNodeCurrent->state2 = nextNodeCurrent->state2 + addState;
        nextNodePrevious->state2 = nextNodeCurrent->state1;
      }
    }  
    else {
      nextNodeCurrent->state1 = (nextNodeCurrent->state1) + addState;
      //nextNodeCurrent->state1 = nextNodePrevious->state2;
    }
  }

  beginNode->next = NULL;
  free(nextNode);
  beginNode->acceptStates = nextNodeCurrent->state1;

return (beginNode);
}
