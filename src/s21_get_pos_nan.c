#include "s21_math.h"

double get_pos_nan() {
  double x = S21_NEG_NAN;
  unsigned long long L =
      (*((unsigned long long*)&x)) & ~((unsigned long long)1 << 63);
  x = *((double*)&L);
  return x;
}