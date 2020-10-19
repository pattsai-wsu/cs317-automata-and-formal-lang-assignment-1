#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

struct node {
  int startState;
  int acceptStates;
  bool isNfaRoot;
  bool isValid;
  char *nfaFullString;
  struct trans *transList;
  struct node *next;
};
typedef struct node* nfa;

struct trans {
  int state1;
  int state2;
  char symbol;
  bool isTransRoot;
  struct trans *transRootPtr;
  struct node *nfaParent;
  struct trans *next;
};
typedef struct trans* transition;

struct node* nfaInit();
struct node* addNfa(struct node*, char[120]);
struct trans* transitionInit(struct node*);
struct trans* addTrans(struct node*,char);
void addTransEnd(struct trans*);
void push(struct node*, struct node**, int*);
struct node* pop(struct node**, int*);
struct node* opAnd(struct node*, struct node*);
struct node* opOr(struct node*, struct node*);
struct node* opStar(struct node*);
void readTop(char*, int*);
void printAll(struct node*, struct trans*);
void printNfa(struct trans*);
void print(struct node*, struct trans*);

void fileHandler(FILE*, char[][120], int*);
void clearStack(struct node**, int*);
