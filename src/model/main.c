#include "s21_smart_calc.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int evaluateExpression(const char* expression, Stack* numbers, Stack* operators) {
	int is_negative_number = 0;
	for(int i = 0; i < (int)strlen(expression); i++) {
		if(isdigit(expression[i])) {
			numLexem num = atof(expression + i);
			if(is_negative_number) {
				is_negative_number = 0;
				num = -num;
			}
			stack_push(numbers, num, NUMBER, 0);
			while(isdigit(expression[i])) {
				i++;
			}
		}
		switch (expression[i])
		{
		case '+':
			stack_push(operators, 0, SUM, 1);
			break;
		case '-':
			if(!isdigit(expression[i - 1])) {
				is_negative_number = 1;
			} else {
				stack_push(operators, 0, SUB, 1);
			}
			break;
		case '*':
			stack_push(operators, 0, MULT, 2);
			break;
		case '/':
			stack_push(operators, 0, DIVISION, 2);
			break;
		case '^':
			stack_push(operators, 0, POW, 3);
			break;
		case '(':
			stack_push(operators, 0, LEFT_BRACKET, 3);
			break;
		case ')':
			stack_push(operators, 0, RIGHT_BRACKET, 3);
			break;
		default:

			break;
		}
	}
    
	return 0;
}



int main() {
	Stack numbers; // Список для чисел
    Stack operators; // Список для операторов
    const char* expression = "-15+-1-(-6--4)";
    int result = evaluateExpression(expression, &numbers, &operators);
    printf("Result: %d\n", result);

	stack_print(&numbers);
	stack_print(&operators);

	stack_clear(&numbers);
	stack_clear(&operators);

    return 0;
}