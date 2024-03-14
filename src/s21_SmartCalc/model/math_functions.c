#include "math_functions.h"

int is_cos(const char* string) {
  return string[0] == 'c' && string[1] == 'o' && string[2] == 's';
}

int is_sin(const char* string) {
  return string[0] == 's' && string[1] == 'i' && string[2] == 'n';
}

int is_tan(const char* string) {
  return string[0] == 't' && string[1] == 'a' && string[2] == 'n';
}

int is_acos(const char* string) {
  return string[0] == 'a' && string[1] == 'c' && string[2] == 'o' &&
         string[3] == 's';
}

int is_asin(const char* string) {
  return string[0] == 'a' && string[1] == 's' && string[2] == 'i' &&
         string[3] == 'n';
}

int is_atan(const char* string) {
  return string[0] == 'a' && string[1] == 't' && string[2] == 'a' &&
         string[3] == 'n';
}

int is_ln(const char* string) { return string[0] == 'l' && string[1] == 'n'; }

int is_log(const char* string) {
  return string[0] == 'l' && string[1] == 'o' && string[2] == 'g';
}

int is_sqrt(const char* string) {
  return string[0] == 's' && string[1] == 'q' && string[2] == 'r' &&
         string[3] == 't';
}

int is_mod(const char* string) {
  return string[0] == 'm' && string[1] == 'o' && string[2] == 'd';
}

int is_math_function(const char* string) {
  return is_sin(string) || is_cos(string) || is_tan(string) ||
         is_asin(string) || is_acos(string) || is_atan(string) ||
         is_ln(string) || is_log(string) || is_sqrt(string);
}