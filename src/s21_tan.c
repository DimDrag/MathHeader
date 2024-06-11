#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0;
  if (s21_isinf(x))
    result = S21_NEG_NAN;
  else if (s21_isnan(x))
    result = x;
  else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
