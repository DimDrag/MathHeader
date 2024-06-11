#include "s21_math.h"

long double s21_factorial(unsigned long long x) {
  long double ans = 1;
  for (; x; ans *= x, x--)
    ;
  return ans;
}