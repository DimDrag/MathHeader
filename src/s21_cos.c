#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (s21_isinf(x))
    result = S21_NEG_NAN;
  else if (s21_isnan(x))
    result = x;
  else {
    x = s21_fmod(x, 2 * S21_PI);
    for (int i = 0; i < 100; i++) {
      result += (s21_pow(-1, i) * s21_pow(x, 2 * i)) / (s21_factorial(2 * i));
    }
  }
  return result;
}
