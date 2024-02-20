#include "s21_smart_calc.h"

Node get_node_operators(char *expression) {
	Node res;
	res.value = 0;
	switch (*expression) {
		case '+':
			res.operator = SUM;
			res.priority = 1;
			break;
		case '-':
			res.operator = SUB;
			res.priority = 1;
			break;
		case '*':
			res.operator = MULT;
			res.priority = 2;
			break;
		case '/':
			res.operator = DIVISION;
			res.priority = 2;
			break;
		case '^':
			res.operator = POW;
			res.priority = 3;
			break;
		case '(':
			res.operator = LEFT_BRACKET;
			res.priority = 0;
			break;
		case ')':
			res.operator = RIGHT_BRACKET;
			res.priority = 6;
			break;
		default:
			break;
	}
	return res;
}

char* identify_number_in_expression(char *expression, Stack *numbers) {
	numLexem num = atof(expression);
	stack_push(numbers, num, NUMBER, 0);
	while (isdigit(*expression) || *expression == '.') {
		expression += 1;
	}
	return expression;
}

char* identify_operator_in_expression(char *expression, Stack *operators, Stack *numbers, int* is_operator_last, int* is_negative_number, int* in_brackets_flag, int* numbers_in_brackets) {
	Node current_operation_node;
	double tmp_result = 0;

	if(*is_operator_last && *expression == '-') { // если унарный минус
		*is_negative_number = 1;
		expression += 1;
	} else if(is_math_function(expression) || is_mod(expression)) { // если математическая функция
		expression = evaluate_math_functions(expression, operators);
	} else {
		current_operation_node = get_node_operators(expression); // текущая нода операции
		if(current_operation_node.operator == LEFT_BRACKET) { // левую скобку сразу закидываем в стек 
			stack_push(operators, current_operation_node.value, current_operation_node.operator, current_operation_node.priority);
			*in_brackets_flag += 1;
			*is_operator_last = 1;
		} else if(stack_is_empty(operators)) { // либо если стек пуст
			stack_push(operators, current_operation_node.value, current_operation_node.operator, current_operation_node.priority);
			*is_operator_last = 1;
		} else if(current_operation_node.operator == RIGHT_BRACKET) { //если правая скобка, то считаем все выражение
			if(*numbers_in_brackets > 1) {
				while(operators->top->operator != LEFT_BRACKET) {
					calculate_last_expression(numbers, operators);
					*numbers_in_brackets -= 1;
				}	
			}
			if(stack_top_operator(operators) == LEFT_BRACKET) {
				stack_pop_operator(operators); // сброс левой скобки из стека
				*in_brackets_flag -= 1;
			}
			if(!stack_is_empty(operators) && stack_top_operator(operators) >= SQRT && stack_top_operator(operators) <= LG) { //если перед открывающей скобкой стояла математическая функция, то считаем
				tmp_result = calculate_math_function(stack_pop_number(numbers), stack_pop_operator(operators));
				stack_push(numbers, tmp_result, NUMBER, 0);
			}
			if(!in_brackets_flag) { // если больше скобок не осталось - то и чисел в скобках нет =) 
				*numbers_in_brackets = 0;
			}
		} else if(current_operation_node.priority <= operators->top->priority) { // если текущий оператор менее приоритетный чем верхний в стеке, то считаем предыдущее
			while(!stack_is_empty(operators) && current_operation_node.priority <= operators->top->priority) { // считаем, пока в секе есть операторы или пока не встретим оператор более высокого приоритета
				calculate_last_expression(numbers, operators);
			}
			stack_push(operators, current_operation_node.value, current_operation_node.operator, current_operation_node.priority);
			*is_operator_last = 1;
		} else { // иначе просто закидываем оператор в стек
			stack_push(operators, current_operation_node.value, current_operation_node.operator, current_operation_node.priority);
			*is_operator_last = 1;
		}
		expression += 1;
	}
	return expression;
}

double evaluate_expression(char *expression) {
	char* expression_ptr = expression;
	int is_operator_last = 1;
	int is_negative_number = 0;
	int numbers_in_brackets = 0;
	int in_brackets_flag = 0;

	Stack numbers;
	Stack operators;
	stack_create(&numbers);
	stack_create(&operators);

	while(*expression_ptr) {
		if (isdigit(*expression_ptr)) {
			expression_ptr = identify_number_in_expression(expression_ptr, &numbers);
			if (is_negative_number) {
				is_negative_number = 0;
				numbers.top->value *= -1;
			}
			is_operator_last = 0;
			if(in_brackets_flag) {
				numbers_in_brackets++;
			}
		} else {
			expression_ptr = identify_operator_in_expression(expression_ptr, &operators, &numbers, &is_operator_last, &is_negative_number, &in_brackets_flag, &numbers_in_brackets);
		}
	}

	// stack_print(&numbers);
	// stack_print(&operators);

	while(!stack_is_empty(&operators)) {
		calculate_last_expression(&numbers, &operators);
	}

	return stack_pop_number(&numbers);
}

char* evaluate_math_functions(char *expression, Stack *operators) {
	if(is_sin(expression)) {
		stack_push(operators, 0, SIN, 5);
		expression += 3;
	} else if(is_cos(expression)) {
		stack_push(operators, 0, COS, 5);
		expression += 3;
	} else if(is_tan(expression)) {
		stack_push(operators, 0, TAN, 5);
		expression += 3;
	} else if(is_asin(expression)) {
		stack_push(operators, 0, ASIN, 5);
		expression += 4;
	} else if(is_acos(expression)) {
		stack_push(operators, 0, ACOS, 5);
		expression += 4;
	} else if(is_atan(expression)) {
		stack_push(operators, 0, ATAN, 5);
		expression += 4;
	} else if(is_ln(expression)) {
		stack_push(operators, 0, LN, 5);
		expression += 2;
	} else if(is_log(expression)) {
		stack_push(operators, 0, LG, 5);
		expression += 2;
	} else if(is_sqrt(expression)) {
		stack_push(operators, 0, SQRT, 5);
		expression += 4;
	} else if(is_mod(expression)) {
		stack_push(operators, 0, MOD, 2);
		expression += 3;
	}

	return expression;
}

double calculate_expression(double a, double b, int operator) {
	double result = 0;
	switch (operator) {
	case SUM:
		result = a + b;
		break;
	case SUB:
		result = a - b;
		break;
	case MULT:
		result = a * b;
		break;
	case DIVISION:
		result = a / b;
		break;
	case POW:
		result = pow(a, b);
		break;
	case MOD:
		result = (int)a % (int)b;
		break;
	
	default:
		break;
	}

	return result;
};

double calculate_math_function(double a, int operator) {
	double result = 0;
	switch (operator) {
	case SQRT:
		result = sqrt(a);
		break;
	case SIN:
		result = sin(a);
		break;
	case COS:
		result = cos(a);
		break;
	case TAN:
		result = tan(a);
		break;
	case ASIN:
		result = asin(a);
		break;
	case ACOS:
		result = acos(a);
		break;
	case ATAN:
		result = atan(a);
		break;
	case LN:
		result = log(a);
		break;
	case LG:
		result = log10(a);
		break;
	default:
		break;
	}
	return result;
}

void calculate_last_expression(Stack* numbers, Stack* operators) {
	double b = stack_pop_number(numbers);
	double a = stack_pop_number(numbers);
	double tmp_result = calculate_expression(a, b, stack_pop_operator(operators));
	stack_push(numbers, tmp_result, NUMBER, 0);
}