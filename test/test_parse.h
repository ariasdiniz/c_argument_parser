#ifndef ARIA_ARGUMENT_PARSER_TEST_PARSE_H
#define ARIA_ARGUMENT_PARSER_TEST_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../argument_parser.h"

void test_parseargs() {
  // Simulate program execution with 7 arguments (including program name)
  char *argv[] = {"pname", "arg1", "--arg2", "param1", "-arg3", "-arg4", "param2"};
  const int argc = 7;
  // Parse the arguments
  HashTable *table = parse_args(argc, argv);
  const char *arg1 = getfromhash(table, "arg1");
  const char *value1 = getfromhash(table, "--arg2");
  const char *arg3 = getfromhash(table, "-arg3");
  const char *value2 = getfromhash(table, "-arg4");
  assert(strcmp(arg1, argv[1]) == 0);
  assert(strcmp(value1, argv[3]) == 0);
  assert(strcmp(arg3, argv[4]) == 0);
  assert(strcmp(value2, argv[6]) == 0);
  deletehash(table);
  printf("test_parseargs passed.\n");
}

void run_parseargs_tests() {
  printf("----------------STARTING PARSE ARGS TESTS-----------------\n");
  test_parseargs();
  printf("----------------FINISHING PARSE ARGS TESTS-----------------\n");
}

#endif // ARIA_ARGUMENT_PARSER_TEST_PARSE_H