#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

extern FILE* InputFile;

typedef int bool;
enum { false, true };

typedef enum {
  TK_PLUS, TK_MINUS, TK_SLASH, TK_STAR, TK_LITERAL
} TokenKind;


typedef struct Token Token;
struct Token {
  TokenKind tokenKind;
  int value;
  Token* next;
};

extern Token init_token;
