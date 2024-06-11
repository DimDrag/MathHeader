#include "s21_math.h"

long double s21_asin(double x) {
  long double ans = 0;
  if (s21_isinf(x) || s21_fabsl(x) > 1)
    ans = S21_POS_NAN;
  else if (s21_isnan(x))
    ans = x;
  else
    ans = s21_atan(x / s21_pow(1 - x * x, 0.5));
  return ans;
}