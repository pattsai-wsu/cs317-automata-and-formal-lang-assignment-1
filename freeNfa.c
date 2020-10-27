#include "header.h"

void freeNfa(struct node* root) {
  if (root == NULL) {
    return;
  }

  freeNfa(root->next);
  freeTrans(root->transList);
  free(root);
}
