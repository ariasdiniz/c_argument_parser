#ifndef ARIA_C_ARGUMENT_PARSER_PARSER_H
#define ARIA_C_ARGUMENT_PARSER_PARSER_H

#include "../lib/simple_data_structures/datastructures.h"

HashTable *parse_args(int argc, char *argv[]);
void call_help(HashTable *parsed_args);

#endif // ARIA_C_ARGUMENT_PARSER_PARSER_H