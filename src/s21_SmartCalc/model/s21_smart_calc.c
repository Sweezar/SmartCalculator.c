#include "s21_smart_calc.h"

Node get_node_operators(char* expression) {
  Node res;
  res.value = 0;
  switch (*expression) {
    case '+':
      res.math_operator= SUM;
      res.priority = 1;
      break;
    case '-':
      res.math_operator= SUB;
      res.priority = 1;
      break;
    case '*':
      res.math_operator= MULT;
      res.priority = 2;
      break;
    case '/':
      res.math_operator= DIVISION;
      res.priority = 2;
      break;
    case '^':
      res.math_operator= POW;
      res.priority = 3;
      break;
    case '(':
      res.math_operator= LEFT_BRACKET;
      res.priority = 0;
      break;
    case ')':
      res.math_operator= RIGHT_BRACKET;
      res.priority = 6;
      break;
    default:
      break;
  }
  if(is_mod(expression)) {
    res.math_operator = MOD;
    res.priority = 2;
  }
  return res;
}

char* identify_number_in_expression(char* expression, Stack* numbers) {
  numLexem num = atof(expression);
  stack_push(numbers, num, NUMBER, 0);
  while (isdigit(*expression) || *expression == '.') {
    expression += 1;
  }
  return expression;
}

char* identify_operator_in_expression(char* expression, Stack* operators,
                                      Stack* numbers, int* is_operator_last,
                                      int* is_negative_number,
                                      int* in_brackets_flag,
                                      int* numbers_in_brackets) {

  if (*is_operator_last && *expression == '-') {  // если унарный минус
    *is_negative_number = 1;
    expression += 1;
  } else if (is_math_function(expression)) {  // если математическая функция
    expression = evaluate_math_functions(expression, operators);
  } else { // если простые операторы
    expression = evaluate_operators(expression, numbers, operators, in_brackets_flag, is_operator_last, numbers_in_brackets);
  }
  return expression;
}

double evaluate_expression(char* expression) {
  char* expression_ptr = expression;
  int is_operator_last = 1;
  int is_negative_number = 0;
  int numbers_in_brackets = 0;
  int in_brackets_flag = 0;
  double result;

  Stack numbers;
  Stack operators;
  stack_create(&numbers);
  stack_create(&operators);

  while (*expression_ptr) {
    if (isdigit(*expression_ptr)) {
      expression_ptr = identify_number_in_expression(expression_ptr, &numbers);
      if (is_negative_number) {
        is_negative_number = 0;
        numbers.top->value *= -1;
      }
      is_operator_last = 0;
      if (in_brackets_flag) {
        numbers_in_brackets++;
      }
    } else {
      expression_ptr = identify_operator_in_expression(
          expression_ptr, &operators, &numbers, &is_operator_last,
          &is_negative_number, &in_brackets_flag, &numbers_in_brackets);
    }
  }

  // stack_print(&numbers);
  // stack_print(&operators);

  while (!stack_is_empty(&operators)) {
    calculate_last_operation(&numbers, &operators);
  }

  result = stack_pop_number(&numbers);
  stack_clear(&numbers);
  stack_clear(&operators);

  return result;
}

char* evaluate_math_functions(char* expression, Stack* operators) {
  if (is_sin(expression)) {
    stack_push(operators, 0, SIN, 5);
    expression += 3;
  } else if (is_cos(expression)) {
    stack_push(operators, 0, COS, 5);
    expression += 3;
  } else if (is_tan(expression)) {
    stack_push(operators, 0, TAN, 5);
    expression += 3;
  } else if (is_asin(expression)) {
    stack_push(operators, 0, ASIN, 5);
    expression += 4;
  } else if (is_acos(expression)) {
    stack_push(operators, 0, ACOS, 5);
    expression += 4;
  } else if (is_atan(expression)) {
    stack_push(operators, 0, ATAN, 5);
    expression += 4;
  } else if (is_ln(expression)) {
    stack_push(operators, 0, LN, 5);
    expression += 2;
  } else if (is_log(expression)) {
    stack_push(operators, 0, LG, 5);
    expression += 2;
  } else if (is_sqrt(expression)) {
    stack_push(operators, 0, SQRT, 5);
    expression += 4;
  }

  return expression;
}

char* evaluate_operators(char* expression, Stack* numbers, Stack* operators, int* in_brackets_flag, int* is_operator_last, int* numbers_in_brackets) {
  Node cur_node;
  double tmp_result = 0;
  cur_node = get_node_operators(expression);  // текущая нода операции
  // левую скобку сразу закидываем в стек
  if (cur_node.math_operator== LEFT_BRACKET) {
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    *in_brackets_flag += 1;
    *is_operator_last = 1;
  } else if (stack_is_empty(operators)) {  // либо если стек пуст
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    *is_operator_last = 1;
  } else if (cur_node.math_operator == RIGHT_BRACKET) {
    if (*numbers_in_brackets > 1) {
      while (operators->top->math_operator != LEFT_BRACKET) {
        calculate_last_operation(numbers, operators);
        *numbers_in_brackets -= 1;
      }
    }
    if (stack_top_operator(operators) == LEFT_BRACKET) {
      stack_pop_operator(operators);  // сброс левой скобки из стека
      *in_brackets_flag -= 1;
    }
    if (!stack_is_empty(operators) && stack_top_operator(operators) >= SQRT && stack_top_operator(operators) <= LG) {
      tmp_result = calculate_math_function(stack_pop_number(numbers), stack_pop_operator(operators));
      stack_push(numbers, tmp_result, NUMBER, 0);
    }
    if (!in_brackets_flag) {
      *numbers_in_brackets = 0;
    }
  } else if (cur_node.priority <= operators->top->priority) {
    while (!stack_is_empty(operators) && cur_node.priority <= operators->top->priority) {
      calculate_last_operation(numbers, operators);
    }
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    *is_operator_last = 1;
  } else {  // иначе просто закидываем оператор в стек
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    *is_operator_last = 1;
  }
  if(is_mod(expression)) {
    expression += 3;
  } else {
    expression += 1;
  }

  return expression;
}

double calculate_operation(double a, double b, int math_operator) {
  double result = 0;
  switch (math_operator) {
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
  }

  return result;
};

double calculate_math_function(double a, int math_operator) {
  double result = 0;
  switch (math_operator) {
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
  }
  return result;
}

void calculate_last_operation(Stack* numbers, Stack* operators) {
  double b = stack_pop_number(numbers);
  double a = stack_pop_number(numbers);
  double tmp_result = calculate_operation(a, b, stack_pop_operator(operators));
  stack_push(numbers, tmp_result, NUMBER, 0);
}