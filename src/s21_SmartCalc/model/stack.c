#include "stack.h"

void stack_create(Stack *s) {
  s->top = NULL;
  s->size = 0;
}

size_t stack_size(const Stack *s) { return s->size; }

int stack_top_is_num(const Stack *s) { return (s->top->math_operator== 0); }

numLexem stack_top_num(const Stack *s) { return s->top->value; }

int stack_top_is_operator(const Stack *s) { return (s->top->math_operator!= 0); }

operationLexem stack_top_operator(const Stack *s) { return s->top->math_operator; }

void stack_push(Stack *s, numLexem value, operationLexem math_operator,
                int priority) {
  Node *ptr = (Node *)malloc(sizeof(Node));
  if (ptr != NULL) {
    ptr->value = value;
    ptr->math_operator= math_operator;
    ptr->priority = priority;
    ptr->next = s->top;
    s->top = ptr;
    s->size++;
  }
}

/**
 * Достать верхний элемент списка типа double
 * Не забывать проверять, что список не пуст
 * @param s указатель на стек
 * @return значение элемента
 */
numLexem stack_pop_number(Stack *s) {
  Node *tmp = s->top;
  numLexem tmp_value = tmp->value;
  s->top = s->top->next;
  s->size--;
  free(tmp);
  return tmp_value;
}

operationLexem stack_pop_operator(Stack *s) {
  Node *tmp = s->top;
  operationLexem tmp_value = tmp->math_operator;
  s->top = s->top->next;
  s->size--;
  free(tmp);
  return tmp_value;
}

int stack_is_empty(const Stack *s) { return s->size == 0; }

void delete_list(Node *top) {
  Node *ptr = top;
  while (ptr != NULL) {
    Node *tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
}

void stack_clear(Stack *s) {
  delete_list(s->top);
  s->top = NULL;
  s->size = 0;
}

void print_list(Node *top) {
  Node *ptr = top;
  while (ptr != NULL) {
    if (ptr->math_operator) {
      printf("%d - operator, \t", ptr->math_operator);
    } else {
      printf("%lf - number, \t", ptr->value);
    }
    ptr = ptr->next;
  }
}

void stack_print(const Stack *s) { print_list(s->top); }

// Stack get_inverse_stack(Stack *s) {
//   Stack tmp;
//   Node *ptr = s->top;
//   stack_create(&tmp);

//   while (ptr != NULL) {
//     stack_push(&tmp, ptr->value, ptr->operator, ptr->priority);
//     ptr = ptr->next;
//   }

//   return tmp;
// }