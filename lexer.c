#include "lcc.h"

char const* TOKEN_KIND[] = {
  "Plus",
  "Minus",
  "Slash",
  "Star",
  "Literal"
};

char const* HEX_NUMERIC_DIGS = "0123456789abcdef";

int ClawBack = 0;

static void preprocess_file() {
  // TODO: perform input file pre-processing
}

// returns position of the character c in str
// else returns -1
static int charpos(const char* str, int c) {
  char *t;
  int idx = 0;

  for (idx = 0; idx < strlen(str); ++idx) {
    printf("c: %c, idx: %d, str[idx]: %c\n", c, idx, str[idx]);
    if (str[idx] == c) {
      return idx;
    }
  }
  return -1;
}

static int scan_numeric(int c, FILE* file) {
  int val = 0, dig;
  while ((dig = charpos(HEX_NUMERIC_DIGS, c)) != -1) {
    val = 10 * val + dig;
    printf("c is %c\n", c);
    printf("val is %d\n", val);
    c = fgetc(file);
  }
  ClawBack = c;
  return val;
}

static int next(const FILE* file) {
  int c;

  if (ClawBack) {
    c = ClawBack;
    ClawBack = 0;
    return c;
  }

  return fgetc(file);
}

static bool is_skippable(int c) {
  return (' ' == c || '\n' == c || '\t' == c || '\r' == c);
}

Token* new_token() {
  Token* tok = 
  tok->next = NULL;
  return tok;
}

Token* append_token(Token* tok, TokenKind tokenKind, int value) {
  Token* new_tok = calloc(1, sizeof(Token));
  new_tok->tokenKind = tokenKind;
  if (tokenKind == TK_LITERAL) {
    new_tok->value = value;
  }
  tok->next = new_tok;
  return new_tok;
}

static void scan(const FILE* file) {
  Token* cur = &init_token;
  int c;

  while((c = next(file)) != EOF) {
    printf("c is %c\n", c);
    switch(c) {
      case '+':
        cur = append_token(&cur, TK_PLUS, NULL);
        break;
      case '-':
        cur = append_token(&cur, TK_MINUS, NULL);
        break;
      case '/':
        cur = append_token(&cur, TK_SLASH, NULL);
        break;
      case '*':
        cur = append_token(&cur, TK_STAR, NULL);
        break;
      default:
        if (is_skippable(c)) {
          break;
        }

        if (isdigit(c)) {
          cur = append_token(&cur, TK_LITERAL, scan_numeric(c, file));
          break;
        }
    }
  }
  return init_token;
}

void scan_file() {
  preprocess_file();
  scan(InputFile);
}



