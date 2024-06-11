#include "s21_math.h"

long double s21_powi(double base, long long int exp) {
  int minus_flag = 0;
  if (exp < 0) {
    minus_flag = 1;
    exp *= -1;
  }
  long double res = 0;
  if (exp == 1)
    res = base;
  else if (exp == 0)
    res = 1;
  else {
    res = s21_powi(base, exp / 2);
    if (exp == exp / 2 * 2) {
      res *= res;
    } else {
      res *= s21_powi(base, exp - exp / 2);
    }
  }
  if (minus_flag) res = 1 / res;
  return res;
}