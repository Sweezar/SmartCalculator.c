#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

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
	SQRT = 8,
	SIN = 9,
	COS = 10,
	TAN = 11,
	ASIN = 12,
	ACOS = 13,
	ATAN = 14,
	MOD = 15,
	LN = 16,
	LG = 17,
	LEFT_BRACKET = 18,
	RIGHT_BRACKET = 19,
} Operators;

typedef struct Node{
    numLexem value;
	operationLexem operator;
	int priority;
    struct Node *next;
} Node;

typedef struct{
    Node *top;
    size_t size;
} Stack;

void stack_create(Stack *s);
size_t stack_size(const Stack *s);
int stack_top_is_num(const Stack *s);
numLexem stack_top_num(const Stack *s);
int stack_top_is_operator(const Stack *s);
operationLexem stack_top_operator(const Stack *s);
void stack_push(Stack *s, numLexem value, operationLexem operator, int priority);
numLexem stack_pop_number(Stack *s);
operationLexem stack_pop_operator(Stack *s);
int stack_is_empty(const Stack *s);
void delete_list(Node *top);
void stack_clear(Stack *s);
void print_list(Node *top);
void stack_print(const Stack *s);

#endif 