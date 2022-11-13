#ifndef INTCODE_H
#define INTCODE_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int* parse(char *program, int* nints);
void find_noun_verb(int* pr, int n);
void execute(int *program, int nints, int *err, bool print);
void add(int *program, int *index);
void multiply(int *program, int *index);

#endif
