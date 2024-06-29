#include "lcc.h"

FILE *InputFile;
Token init_token = {};
int main(int argc, char *argv[]) {
  InputFile = fopen(argv[1], "r");


  if(!InputFile) {
    fprintf(stderr, "Unable to open file: %s", argv[1]);
    return EXIT_FAILURE;
  }

  scan_file();
  parse(init_token);

  return EXIT_SUCCESS;
}