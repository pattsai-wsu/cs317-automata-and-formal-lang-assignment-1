#include "header.h"

struct node* opOr(struct node* beginNode, struct node* nextNode) {
  struct trans* beginNodePrevious;
  struct trans* beginNodeCurrent;
  struct trans* nextNodePrevious;
  struct trans* nextNodePreviousTrack;
  struct trans* nodeTrack;
  struct trans* nextNodeCurrent;
  int diff,addState,numStates=0;

  beginNodePrevious = beginNode->transList;
  beginNodeCurrent = beginNodePrevious->next;
  numStates++;

  while(beginNodeCurrent->next != NULL) {
    beginNodeCurrent = beginNodeCurrent->next;
    numStates++;
  }
  addState = beginNodeCurrent->state1;

  nextNodePrevious = nextNode->transList;
  nextNodePreviousTrack = nextNode->transList;
  nextNodeCurrent = nextNodePrevious->next;
  numStates++;

  nextNodeCurrent->state1 = beginNodeCurrent->state1 + 1;
  nextNodeCurrent->state2 = (nextNodeCurrent->state1) + 1;
  nextNodePreviousTrack = nextNodeCurrent;
  nextNodePrevious = nextNodeCurrent;
  nextNodeCurrent = nextNodeCurrent->next;
  numStates++;
  
  int tester = 0;

  while(nextNodeCurrent->next != NULL) {
    diff = (nextNodeCurrent->state2 - nextNodeCurrent->state1);	  
    printf("next Node current state1: %d, state2: %d\n", nextNodeCurrent->state1, nextNodeCurrent->state2);
    printf("iteration: %d, diff value: %d\n", tester, diff);

    nextNodeCurrent->state1 = nextNodePreviousTrack->state2;
    nextNodeCurrent->state2 = (nextNodeCurrent->state1) + diff;

    nextNodePrevious = nextNodeCurrent;
    nextNodePreviousTrack = nextNodeCurrent;
    nextNodeCurrent = nextNodeCurrent->next;
    numStates++;
  }
  if(nextNodeCurrent->next == NULL) {
    diff = (nextNodeCurrent->state2 - nextNodeCurrent->state1);	  
    if(nextNodeCurrent->state2 != -999) {
      if(diff < 1 || diff > 1) {
        printf("next Node current state1: %d, state2: %d\n", nextNodeCurrent->state1, nextNodeCurrent->state2);
        printf("iteration: %d, diff value: %d\n", tester, diff);
        nextNodeCurrent->state1 = (nextNodePreviousTrack->state2 + diff) - 1;
        nextNodePreviousTrack->state2 = nextNodeCurrent->state1;
      }
    }  
    else {
      nextNodeCurrent->state1 = nextNodePreviousTrack->state2;
    }
  }

  struct trans* newStateTrans1 = malloc(sizeof(struct trans));
  newStateTrans1->state1 = numStates + 1;
  newStateTrans1->state2 = beginNode->transList->next->state1;
  newStateTrans1->symbol = 'E';
  newStateTrans1->isTransRoot = false;
  newStateTrans1->nfaParent = beginNode;
  newStateTrans1->next = beginNode->transList->next;

  struct trans* newStateTrans2 = malloc(sizeof(struct trans));
  newStateTrans2->state1 = newStateTrans1->state1;
  newStateTrans2->state2 = nextNode->transList->next->state1;
  newStateTrans2->symbol = 'E';
  newStateTrans2->isTransRoot = false;
  newStateTrans2->nfaParent = newStateTrans1->nfaParent;
  newStateTrans2->next = nextNode->transList->next;

  struct trans* newEndTrans1 = malloc(sizeof(struct trans));
  newEndTrans1->state1 = (newStateTrans1->state1) + 1;
  newEndTrans1->state2 = -999;
  newEndTrans1->symbol = 'E';
  newEndTrans1->isTransRoot = false;
  newEndTrans1->nfaParent = beginNode;
  newEndTrans1->next = newStateTrans2;

  //printf("Or Function - End of 1st RE linked to beginning of 2nd RE: %p", newEndTrans1->next);

  struct trans* newEndTrans2 = malloc(sizeof(struct trans));
  newEndTrans2->state1 = newEndTrans1->state1;
  newEndTrans2->state2 = -999;
  newEndTrans2->symbol = 'E';
  newEndTrans2->isTransRoot = false;
  newEndTrans2->nfaParent = beginNode;
  newEndTrans2->next = NULL;

  //numStates=newEndTrans1->state1;

  beginNodeCurrent->state2 = newEndTrans1->state1;
  nextNodeCurrent->state2 = newEndTrans1->state1;
  beginNodeCurrent->next = newEndTrans1;
  nextNodeCurrent->next = newEndTrans2;

  nextNode->transList = NULL;
  beginNode->next = NULL;

  beginNode->startState = newStateTrans1->state1;
  beginNode->acceptStates = newEndTrans1->state1;
  beginNode->transList->next = newStateTrans1;

  return (beginNode);
}
