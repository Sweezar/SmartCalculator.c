#include "s21_smart_calc.h"

int main() {
	double res = 0;
	char *expression = "(1+2)*3^2^2-6/(7+8/9)";
	res = evaluate_expression(expression);
	
	printf("res = %lf", res);

	return 0;
}