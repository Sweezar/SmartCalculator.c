#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"
#include "math_functions.h"

Node get_node_operators(char *expression);
char* identify_number_in_expression(char *expression, Stack *numbers);

double evaluate_expression(char *expression);
char* evaluate_math_functions(char *expression, Stack *operators);
double calculate_expression(double a, double b, int operator);
double calculate_math_function(double a, int operator);
void calculate_last_expression(Stack* numbers, Stack* operators);

#endif