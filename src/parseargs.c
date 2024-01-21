#include "parseargs.h"
#include <stdlib.h>
#include <stdio.h>

HashTable *parse_args(int argc, char *argv[]) {
  HashTable *table = createhash();
  if (argc == 1) {
    return table;
  }
  char *first_char;
  for (int i=1; i<argc; i++) {
    first_char = argv[i];
    printf("first char: %s\n", first_char);
    if (i < argc - 1 && first_char != '-') {
      printf("adding to hash\n");
      addtohash(table, argv[i], argv[i + 1]);
      i++;
    } else {
      addtohash(table, argv[i], argv[i]);
    }
  }
  return table;
}

void call_help(HashTable *parsed_args) {}
