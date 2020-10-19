#include "header.h"

int main(int argc, char** argv) {

  if(argc!=2) {
    printf("ERROR: when starting the program in the terminal\n");
    printf("please enter 1 text file containing Reg-Ex for conversion\n");
    printf("in the following way\n");
    printf(">./main textFile.txt\n");
    printf("Please try again, Goodbye\n");
    exit(1);
  }

  //Initialize the NFA list
  nfa nfaList;
  nfaList = nfaInit();
  struct node* nfaRoot=nfaList;
  struct node* currentNfa=nfaList;
  struct trans* transRoot;
  struct trans* currentTrans;

  //Set File Handlers
  FILE *fptr;
  char arr[50][120];
  int arraySize;

  //Initialize Main Stack
  int top = -1;
  struct node* stackArr[MAX];

  // Open file 
  fptr = fopen(argv[1], "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
 
    fileHandler(fptr, arr, &arraySize);
    fclose(fptr); 


    int j,currentStrLength,isLetter,i=0;
    struct node* pop1;
    struct node* pop2;
    char *currString;

    while(i < arraySize) {
      currentStrLength = strlen(arr[i]);
      currString = arr[i];
      j = 0;
      while(j < currentStrLength){
        if(arr[i][j] != '\0') {
	  if(arr[i][currentStrLength-1] == 38 || arr[i][currentStrLength-1] == 42 || arr[i][currentStrLength-1] == 124) {
	  }
	  else {
	    if (top == -1){
              currentNfa = addNfa(currentNfa, currString);
	      currentNfa->isValid = false;
	    }
	    else {
	      currentNfa->isValid = false;
	      //printf("Invalid regular expression string\n");
	    }
	    break;
	  }
	  if(arr[i][j] >= 97 && arr[i][j] <= 101) {          //using ascii numerical values for a through e
            currentNfa = addNfa(currentNfa, currString);
	    currentTrans = addTrans(currentNfa,arr[i][j]);
     	    push(currentNfa,stackArr,&top);
          }
	  else if(arr[i][j] == 69) {          //using ascii numerical value for E
            currentNfa = addNfa(currentNfa, currString);
	    currentTrans = addTrans(currentNfa,arr[i][j]);
     	    push(currentNfa,stackArr,&top);
          }
	  else if(arr[i][j] == 38) {          //using ascii numerical value for &
            if(top >= 1) {
	      pop1 = pop(stackArr,&top); 
	      pop2 = pop(stackArr,&top);
	      currentNfa = opAnd(pop2,pop1); 
     	      push(currentNfa,stackArr,&top);
	    }
	    else {
	      if (top == -1){
                currentNfa = addNfa(currentNfa, currString);
	        currentNfa->isValid = false;
	      }
	      else {
	        currentNfa->isValid = false;
	        //printf("Invalid regular expression string\n");
	      }
	      break;
	    }
	  }
	  else if(arr[i][j] == 124) {          //using ascii numerical value for |
            if(top >= 1) {
	      pop1 = pop(stackArr,&top); 
	      pop2 = pop(stackArr,&top);
	      currentNfa = opOr(pop2,pop1); 
     	      push(currentNfa,stackArr,&top);
	    }
	    else {
	      if (top == -1){
                currentNfa = addNfa(currentNfa, currString);
	        currentNfa->isValid = false;
	      }
	      else {
	        currentNfa->isValid = false;
	        //printf("Invalid regular expression string\n");
	      }
	      break;
	    }
	  }
	  else if(arr[i][j] == 42) {          //using ascii numerical value for *
            if(top >= 0) {
	      pop1 = pop(stackArr,&top); 
	      currentNfa = opStar(pop1); 
     	      push(currentNfa,stackArr,&top);
	    }
	    else {
	      if (top == -1){
                currentNfa = addNfa(currentNfa, currString);
	        currentNfa->isValid = false;
	      }
	      else {
	        currentNfa->isValid = false;
	        //printf("Invalid regular expression string\n");
	      }
	      break;
	    }
	  }
	  else {
	    if (top == -1){
              currentNfa = addNfa(currentNfa, currString);
	      currentNfa->isValid = false;
	    }
	    else {
	      currentNfa->isValid = false;
	      //printf("Invalid regular expression string\n");
	    }
	    break;
	  }
	  j++;
	}
	else {
	printf("ended up in else statement\n");
	  break;
	}
      }
      while(top != -1) {
        pop(stackArr,&top);
      }
      //printf("top value: %d\n", top);
      i++;
    }

print(nfaRoot, transRoot);

return 0;
}

