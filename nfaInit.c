#include "header.h"

struct node* nfaInit(){
  struct node *nfaSent;

  nfaSent=malloc(sizeof(struct node));
  nfaSent->startState=-999;
  nfaSent->acceptStates=-999;
  nfaSent->isNfaRoot=true;
  nfaSent->isValid=true;
  nfaSent->transList=NULL;
  nfaSent->next=NULL;

  return (nfaSent);
}
