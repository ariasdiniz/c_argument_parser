#include "parseargs.h"
#include <stdlib.h>

HashTable *parse_args(int argc, char *argv[]) {
  HashTable *table = createhash();
  if (argc == 1) {
    return table;
  }
}

void call_help(HashTable *parsed_args) {}
