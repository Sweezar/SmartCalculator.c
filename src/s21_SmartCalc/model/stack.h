#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef double numLexem;
typedef int operationLexem;

typedef enum Operators {
  NUMBER = 0,
  SUM = 1,
  SUB = 2,
  MULT = 3,
  DIVISION = 4,
  RESULT = 5,
  SIGN = 6,
  POW = 7,
  MOD = 8,
  SQRT = 9,
  SIN = 10,
  COS = 11,
  TAN = 12,
  ASIN = 13,
  ACOS = 14,
  ATAN = 15,
  LN = 16,
  LOG = 17,
  LEFT_BRACKET = 18,
  RIGHT_BRACKET = 19,
} Operators;

typedef struct Node {
  numLexem value;
  operationLexem math_operator;
  int priority;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
  size_t size;
} Stack;

void stack_create(Stack *s);
size_t stack_size(const Stack *s);
operationLexem stack_top_operator(const Stack *s);
void stack_push(Stack *s, numLexem value, operationLexem math_operator,
                int priority);
numLexem stack_pop_number(Stack *s);
operationLexem stack_pop_operator(Stack *s);
int stack_is_empty(const Stack *s);
void delete_list(Node *top);
void stack_clear(Stack *s);

#endif
