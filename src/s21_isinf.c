#include "s21_math.h"

int s21_isinf(double x) {
  return (x == S21_POS_INFINITY || x == S21_NEG_INFINITY) ? 1 : 0;
}