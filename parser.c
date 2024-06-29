#include "lcc.h"

void parse(Token tok) {
  printf("tok=>%c", tok.tokenKind);
  while(tok.next != NULL) {
    printf("tk: %d\n", tok.tokenKind);
    if (tok.tokenKind == TK_LITERAL) {
      printf("val: %d\n", tok.value);
    }
    tok = *tok.next;
  }
}