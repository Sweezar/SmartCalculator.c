#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "math_functions.h"
#include "stack.h"

Node get_node_operators(char *expression);
char *identify_number_in_expression(char *expression, Stack *numbers);

double evaluate_expression(char *expression);
char *evaluate_math_functions(char *expression, Stack *operators);
char* evaluate_operators(char* expression, Stack* numbers, Stack* operators, int* in_brackets_flag, int* is_operator_last, int* numbers_in_brackets);
double calculate_operation(double a, double b, int math_operator);
double calculate_math_function(double a, int math_operator);
void calculate_last_operation(Stack *numbers, Stack *operators);

#endif