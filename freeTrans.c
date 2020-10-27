#include "header.h"

void freeTrans(struct trans* root) {
  if (root == NULL) {
    return;
  }

  freeTrans(root->next);
  free(root);
}
