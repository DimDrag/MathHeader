#include "s21_math.h"

long double s21_sqrt(double x) {
  long double ans = 0;
  if (x == 0)
    ans = x;
  else if (s21_isnan(x))
    ans = x;
  else if (x < 0)
    ans = S21_NEG_NAN;
  else {
    long double logx = s21_log(x);
    for (int i = 0; i < 1000; i++) {
      ans += s21_powi(0.5 * logx, i) / s21_factorial(i);
    }
  }
  return (double)ans;
}