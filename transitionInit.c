#include "header.h"

struct trans* transitionInit(struct node* nfaParent){
  struct trans *transSent;

  transSent=malloc(sizeof(struct trans));
  transSent->state1=-999;
  transSent->state2=-999;
  transSent->isTransRoot=true;
  transSent->transRootPtr=transSent;
  transSent->nfaParent=nfaParent;
  transSent->next=NULL;

  return (transSent);
}

