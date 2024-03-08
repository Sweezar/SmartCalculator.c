#include "s21_smart_calc.h"

int evaluate_expression(char* expression, double* result, double x) {
  char* expression_ptr = expression;
  s_options options;
  options.is_operator_last = 1;
  options.numbers_in_brackets = 0;
  options.in_brackets_flag = 0;
  options.error_code = 0;

  Stack numbers;
  Stack operators;
  stack_create(&numbers);
  stack_create(&operators);

  while (*expression_ptr) {
    if(*expression_ptr == 'x') {
      stack_push(&numbers, x, NUMBER, 0);
      options.is_operator_last = 0;
      if (options.in_brackets_flag) {
        options.numbers_in_brackets++;
      }
      expression_ptr += 1;
    } else if (isdigit(*expression_ptr)) {
      expression_ptr = identify_number_in_expression(expression_ptr, &numbers, &options);
      options.is_operator_last = 0;
      if (options.in_brackets_flag) {
        options.numbers_in_brackets++;
      }
    } else {
      expression_ptr = identify_operator_in_expression(
          expression_ptr, &operators, &numbers, &options);
    }
  }

  while(!stack_is_empty(&operators) && 0 == options.error_code) {
    options.error_code = calculate_last_operation(&numbers, &operators);
  }
  if(0 == options.error_code) {
    *result = stack_pop_number(&numbers);
  }
  if(!stack_is_empty(&numbers) || !stack_is_empty(&operators)) {
    options.error_code = 1;
  }
  stack_clear(&numbers);
  stack_clear(&operators);

  return options.error_code;
}

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

char* identify_number_in_expression(char* expression, Stack* numbers, s_options* options) {
  numLexem num = atof(expression);
  stack_push(numbers, num, NUMBER, 0);
  int dot_counter = 0;
  while (isdigit(*expression) || *expression == '.') {
    if(*expression == '.') {
      dot_counter++;
    }
    expression += 1;
  }
  if(dot_counter > 1) {
    options->error_code = 1;
  }
  return expression;
}

char* identify_operator_in_expression(char* expression, Stack* operators, Stack* numbers, s_options* options) {

  if (options->is_operator_last && (*expression == '-' || *expression == '+')) { 
    if(*expression == '-') { // если унарный минус
      stack_push(numbers, 0, NUMBER, 0); 
      stack_push(operators, 0, SUB, 6);
      if(options->in_brackets_flag) {
        options->numbers_in_brackets++;
      }
    }
    
    expression += 1;
  } else if (is_math_function(expression)) {  // если математическая функция
    expression = evaluate_math_functions(expression, operators);
  } else { // если простые операторы
    expression = evaluate_operators(expression, numbers, operators, options);
  }
  return expression;
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
    stack_push(operators, 0, LOG, 5);
    expression += 3;
  } else if (is_sqrt(expression)) {
    stack_push(operators, 0, SQRT, 5);
    expression += 4;
  }

  return expression;
}

char* evaluate_operators(char* expression, Stack* numbers, Stack* operators, s_options* options) {
  Node cur_node;
  double tmp_result = 0;
  cur_node = get_node_operators(expression);  // текущая нода операции
  // левую скобку сразу закидываем в стек
  if (cur_node.math_operator== LEFT_BRACKET) {
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    options->in_brackets_flag += 1;
    options->is_operator_last = 1;
  } else if (stack_is_empty(operators)) {  // либо если стек пуст
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    options->is_operator_last = 1;
  } else if (cur_node.math_operator == RIGHT_BRACKET) { // правую скобку считаем
    if (options->numbers_in_brackets > 1) { // в скобках больше одного числа
      while (operators->top->math_operator != LEFT_BRACKET) {
        calculate_last_operation(numbers, operators);
        options->numbers_in_brackets -= 1;
      }
    }
    if (stack_top_operator(operators) == LEFT_BRACKET) {
      stack_pop_operator(operators);  // сброс левой скобки из стека
      options->in_brackets_flag -= 1;
    }
    if (!stack_is_empty(operators) && stack_top_operator(operators) >= SQRT && stack_top_operator(operators) <= LOG) {
      tmp_result = calculate_math_function(stack_pop_number(numbers), stack_pop_operator(operators));
      stack_push(numbers, tmp_result, NUMBER, 0);
    }
    if (!options->in_brackets_flag) {
      options->numbers_in_brackets = 0;
    }
  } else if (cur_node.priority <= operators->top->priority) {
    while (!stack_is_empty(operators) && cur_node.priority <= operators->top->priority) {
      calculate_last_operation(numbers, operators);
    }
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    options->is_operator_last = 1;
  } else {  // иначе просто закидываем оператор в стек
    stack_push(operators, cur_node.value, cur_node.math_operator, cur_node.priority);
    options->is_operator_last = 1;
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
    case LOG:
      result = log10(a);
      break;
  }
  return result;
}

int calculate_last_operation(Stack* numbers, Stack* operators) {
  int return_code = 0;
  double a = 0, b = 0, tmp_result;
  int math_operator = 0;
  if(!(stack_is_empty(operators) && stack_size(numbers) == 1)) {
    if(!stack_is_empty(operators)) {
      math_operator = stack_pop_operator(operators);
    } else {
      return_code = 1;
    }
    if(stack_size(numbers) >= 2) {
      b = stack_pop_number(numbers);
    } else {
      return_code = 1;
    }
    if(!stack_is_empty(numbers)) {
      a = stack_pop_number(numbers);
    } else {
      return_code = 1;
    }
    if(0 == b && math_operator == DIVISION) {
      return_code = 1;
    }
    if(0 == return_code) {
      tmp_result = calculate_operation(a, b, math_operator);
      stack_push(numbers, tmp_result, NUMBER, 0);
    }
  }

  return return_code;
}
