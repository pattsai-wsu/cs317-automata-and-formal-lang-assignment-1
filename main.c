#include "header.h"

int main(int argc, char** argv) {
  FILE *fptr;
  char arr[50][120];
  int arraySize;

  
  // Open file 
  fptr = fopen(argv[1], "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
 
    fileHandler(fptr, arr, &arraySize);
    fclose(fptr); 

    printf("array size: %d\n\n", arraySize);
    //int arrSize = sizeof(arr)/sizeof(struct Node);
    //printf("%d\n\n", arrSize);

    int j=0;
 
    while(j < arraySize) {
      printf("%s", arr[j]);
      j++;
      printf("\n");
    }

   printf("\nsingle print out of arr[5]\n");
   printf("%s\n", arr[5]);

   printf("\nsingle print out of arr[2]\n");
   printf("%s\n", arr[2]);

   printf("\nsingle print out of arr[2][1]\n");
   printf("%c\n", arr[2][1]);
return 0;
}

