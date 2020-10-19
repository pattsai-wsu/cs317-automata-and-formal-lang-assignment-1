#include "header.h"

void fileHandler(FILE* fileIn, char arrIn[][120], int *arraySize) {

  char c;
  char expression[120];
  int i,j;

  // Read contents from file 
  c = fgetc(fileIn);
  i=0;
  while(c == '\r' || c == '\n') {
    c = fgetc(fileIn);
  }

  while (c != EOF) { 
    j=0;

    while(c!='\n') {
      if(c == '\r'){ break; }
      expression[j] = c;
        c = fgetc(fileIn);
      j++;
    }

    expression[j++]='\0';
    strcpy(arrIn[i],expression);

    //reset the expression array to empty
    j=0;
    while(j<120) {
      expression[j] = '\0';
      j++;
    }

    //get next char
    c = fgetc(fileIn);
    i++;
  }

*arraySize = i;
return;
}
