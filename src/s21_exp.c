#include "s21_math.h"

long double s21_exp(double x) {
  long double ans = 0;
  if (x == S21_POS_INFINITY)
    ans = x;
  else if (x == S21_NEG_INFINITY)
    ans = 0;
  else if (s21_isnan(x))
    ans = x;
  else if (x == 0)
    ans = 1;
  else {
    int minus_flag = 0;
    if (x < 0) {
      minus_flag = 1;
      x *= -1;
    }
    for (int i = 0; i < 1000; i++) {
      ans += s21_powi(x, i) / s21_factorial(i);
    }
    if (minus_flag) ans = 1 / ans;
  }
  return (double)ans;
}