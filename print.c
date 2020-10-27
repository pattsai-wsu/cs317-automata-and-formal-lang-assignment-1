#include "header.h"
void print(struct node* nfaRoot) {
  struct trans* transRoot;
  if(nfaRoot->isNfaRoot == 1) {
    if(nfaRoot->next != NULL) {
      nfaRoot=nfaRoot->next;
    }
    else {
      printf("Sorry, you have entered an empty list. Please try again\n");
      exit(0);
    }
  }
  int n=0;
  while(1) {
    if(nfaRoot->isValid==1) {
      printf("CONVERT REGULAR EXPRESSION:    %s\n", nfaRoot->nfaFullString);
      if(nfaRoot->transList != NULL){
        transRoot = nfaRoot->transList;
        int z=0;
        while(1) {
          if(transRoot->next != NULL){
	    if(transRoot->isTransRoot != 1){
              if (nfaRoot->startState == transRoot->state1) {
                printf("S ");
              }
              if (nfaRoot->acceptStates == transRoot->state1) {
                printf("F ");
              }

	      if(transRoot->state2 != -999) { 
	        printf("(q%d, %c) -> q%d\n", transRoot->state1, transRoot->symbol, transRoot->state2);
              }
	      else {
	        printf("(q%d, %c)\n", transRoot->state1, transRoot->symbol);
	      }
            }
            transRoot=transRoot->next;
            z++;
	  }
	  else {
	    if(transRoot->isTransRoot != 1){
              if (nfaRoot->startState == transRoot->state1) {
                printf("S ");
              }
              if (nfaRoot->acceptStates == transRoot->state1) {
                printf("F ");
              }

	      if(transRoot->state2 != -999) { 
	        printf("(q%d, %c) -> q%d\n", transRoot->state1, transRoot->symbol, transRoot->state2);
              }
	      else {
	        printf("(q%d, %c)\n", transRoot->state1, transRoot->symbol);
	      }

	    }
  	    break;
	  }
        }
      }
      if(nfaRoot->next!=NULL) {
        printf("\n\n");
        nfaRoot=nfaRoot->next;
        n++;
      }
      else {
        break;
      }
    }
    else {
      printf("CONVERT REGULAR EXPRESSION:    %s\n", nfaRoot->nfaFullString);
      printf("\nSorry, the regular expression entered is not valid\n");
      printf("Please remember to enter only the ascii characters:\n"); 
      printf("a b c d e | & *\n"); 
      printf("You may not use spaces in your Regular Expression\n"); 
      printf("Each Regular Expression to be evaluated must be on a separate line of the imported file\n"); 
      if(nfaRoot->next!=NULL) {
        printf("\n\n");
        nfaRoot=nfaRoot->next;
        n++;
      }
      else {
        break;
      }
    }
  }
}

